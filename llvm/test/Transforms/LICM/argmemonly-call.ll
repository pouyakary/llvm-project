; RUN: opt -S -basic-aa -licm -licm-n2-threshold=0 -verify-memoryssa %s -enable-new-pm=0 | FileCheck %s --check-prefix=ALIAS-N2
; RUN: opt -licm -basic-aa -licm-n2-threshold=200 < %s -S -enable-new-pm=0 | FileCheck %s --check-prefix=ALIAS-N2

; RUN: opt -aa-pipeline=basic-aa -licm-n2-threshold=0 -passes='require<aa>,require<targetir>,require<scalar-evolution>,require<opt-remark-emit>,loop(licm)' < %s -S | FileCheck %s
; RUN: opt -aa-pipeline=basic-aa -licm-n2-threshold=0 -passes='require<aa>,require<targetir>,require<scalar-evolution>,require<opt-remark-emit>,loop-mssa(licm)' < %s -S | FileCheck %s --check-prefix=ALIAS-N2
; RUN: opt -aa-pipeline=basic-aa -licm-n2-threshold=200 -passes='require<aa>,require<targetir>,require<scalar-evolution>,require<opt-remark-emit>,loop(licm)' < %s -S | FileCheck %s --check-prefix=ALIAS-N2

declare i32 @foo() readonly argmemonly nounwind
declare i32 @foo2() readonly nounwind
declare i32 @bar(i32* %loc2) readonly argmemonly nounwind

define void @test(i32* %loc) {
; CHECK-LABEL: @test
; CHECK: @foo
; CHECK-LABEL: loop:
; ALIAS-N2-LABEL: @test
; ALIAS-N2: @foo
; ALIAS-N2-LABEL: loop:
  br label %loop

loop:
  %res = call i32 @foo()
  store i32 %res, i32* %loc
  br label %loop
}

; Negative test: show argmemonly is required
define void @test_neg(i32* %loc) {
; CHECK-LABEL: @test_neg
; CHECK-LABEL: loop:
; CHECK: @foo
; ALIAS-N2-LABEL: @test_neg
; ALIAS-N2-LABEL: loop:
; ALIAS-N2: @foo
  br label %loop

loop:
  %res = call i32 @foo2()
  store i32 %res, i32* %loc
  br label %loop
}

define void @test2(i32* noalias %loc, i32* noalias %loc2) {
; CHECK-LABEL: @test2
; CHECK: @bar
; CHECK-LABEL: loop:
; ALIAS-N2-LABEL: @test2
; ALIAS-N2: @bar
; ALIAS-N2-LABEL: loop:
  br label %loop

loop:
  %res = call i32 @bar(i32* %loc2)
  store i32 %res, i32* %loc
  br label %loop
}

; Negative test: %might clobber gep
define void @test3(i32* %loc) {
; CHECK-LABEL: @test3
; CHECK-LABEL: loop:
; CHECK: @bar
; ALIAS-N2-LABEL: @test3
; ALIAS-N2-LABEL: loop:
; ALIAS-N2: @bar
  br label %loop

loop:
  %res = call i32 @bar(i32* %loc)
  %gep = getelementptr i32, i32 *%loc, i64 1000000
  store i32 %res, i32* %gep
  br label %loop
}


; Negative test: %loc might alias %loc2
define void @test4(i32* %loc, i32* %loc2) {
; CHECK-LABEL: @test4
; CHECK-LABEL: loop:
; CHECK: @bar
; ALIAS-N2-LABEL: @test4
; ALIAS-N2-LABEL: loop:
; ALIAS-N2: @bar
  br label %loop

loop:
  %res = call i32 @bar(i32* %loc2)
  store i32 %res, i32* %loc
  br label %loop
}

declare i32 @foo_new(i32*) readonly
; With the default AST mechanism used by LICM for alias analysis,
; we clump foo_new with bar.
; With the N2 Alias analysis diagnostic tool, we are able to hoist the
; argmemonly bar call out of the loop.
; Using MemorySSA we can also hoist bar.

define void @test5(i32* %loc2, i32* noalias %loc) {
; ALIAS-N2-LABEL: @test5
; ALIAS-N2: @bar
; ALIAS-N2-LABEL: loop:

; CHECK-LABEL: @test5
; CHECK-LABEL: loop:
; CHECK:  @bar
  br label %loop

loop:
  %res1 = call i32 @bar(i32* %loc2)
  %res = call i32 @foo_new(i32* %loc2)
  store volatile i32 %res1, i32* %loc
  br label %loop
}


; memcpy doesn't write to it's source argument, so loads to that location
; can still be hoisted
define void @test6(i32* noalias %loc, i32* noalias %loc2) {
; CHECK-LABEL: @test6
; CHECK: %val = load i32, i32* %loc2
; CHECK-LABEL: loop:
; CHECK: @llvm.memcpy
; ALIAS-N2-LABEL: @test6
; ALIAS-N2: %val = load i32, i32* %loc2
; ALIAS-N2-LABEL: loop:
; ALIAS-N2: @llvm.memcpy
  br label %loop

loop:
  %val = load i32, i32* %loc2
  store i32 %val, i32* %loc
  %dest = bitcast i32* %loc to i8*
  %src = bitcast i32* %loc2 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %dest, i8* %src, i64 8, i1 false)
  br label %loop
}

define void @test7(i32* noalias %loc, i32* noalias %loc2) {
; CHECK-LABEL: @test7
; CHECK: %val = load i32, i32* %loc2
; CHECK-LABEL: loop:
; CHECK: @custom_memcpy
; ALIAS-N2-LABEL: @test7
; ALIAS-N2: %val = load i32, i32* %loc2
; ALIAS-N2-LABEL: loop:
; ALIAS-N2: @custom_memcpy
  br label %loop

loop:
  %val = load i32, i32* %loc2
  store i32 %val, i32* %loc
  %dest = bitcast i32* %loc to i8*
  %src = bitcast i32* %loc2 to i8*
  call void @custom_memcpy(i8* %dest, i8* %src)
  br label %loop
}

declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1)
declare void @custom_memcpy(i8* nocapture writeonly, i8* nocapture readonly) argmemonly nounwind
