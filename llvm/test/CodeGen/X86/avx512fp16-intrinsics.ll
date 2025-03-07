; NOTE: Assertions have been autogenerated by utils/update_llc_test_checks.py
; RUN: llc < %s -mtriple=x86_64-unknown-unknown -mattr=+avx512fp16 | FileCheck %s

declare i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half>, <8 x half>, i32, i32)

define i32 @test_x86_avx512fp16_ucomi_sh_lt(<8 x half> %a0, <8 x half> %a1) {
; CHECK-LABEL: test_x86_avx512fp16_ucomi_sh_lt:
; CHECK:       # %bb.0:
; CHECK-NEXT:    vcmpngesh %xmm1, %xmm0, %k0
; CHECK-NEXT:    kmovw %k0, %eax
; CHECK-NEXT:    retq
  %res = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %a0, <8 x half> %a1, i32 9, i32 4)
  ret i32 %res
}

declare <8 x half> @llvm.x86.avx512fp16.mask.add.sh.round(<8 x half>, <8 x half>, <8 x half>, i8, i32)

define <8 x half> @test_int_x86_avx512fp16_mask_add_sh(<8 x half> %x1, <8 x half> %x2, <8 x half> %src, i8 %mask, half * %ptr) {
; CHECK-LABEL: test_int_x86_avx512fp16_mask_add_sh:
; CHECK:       # %bb.0:
; CHECK-NEXT:    kmovd %edi, %k1
; CHECK-NEXT:    vaddsh %xmm1, %xmm0, %xmm0
; CHECK-NEXT:    vmovaps %xmm2, %xmm3
; CHECK-NEXT:    vaddsh %xmm1, %xmm0, %xmm3 {%k1}
; CHECK-NEXT:    vaddsh %xmm1, %xmm3, %xmm0 {%k1} {z}
; CHECK-NEXT:    vaddsh (%rsi), %xmm0, %xmm2 {%k1}
; CHECK-NEXT:    vmovaps %xmm2, %xmm0
; CHECK-NEXT:    retq
  %val.half = load half,half * %ptr
  %val = insertelement <8 x half> undef, half %val.half, i32 0
  %res0 = call <8 x half> @llvm.x86.avx512fp16.mask.add.sh.round(<8 x half> %x1, <8 x half> %x2, <8 x half> zeroinitializer, i8 -1, i32 4)
  %res1 = call <8 x half> @llvm.x86.avx512fp16.mask.add.sh.round(<8 x half> %res0, <8 x half> %x2, <8 x half> %src , i8 %mask, i32 4)
  %res2 = call <8 x half> @llvm.x86.avx512fp16.mask.add.sh.round(<8 x half> %res1, <8 x half> %x2, <8 x half> zeroinitializer , i8 %mask, i32 4)
  %res3 = call <8 x half> @llvm.x86.avx512fp16.mask.add.sh.round(<8 x half> %res2, <8 x half> %val, <8 x half> %src , i8 %mask, i32 4)
  ret <8 x half> %res3
}

declare <8 x half> @llvm.x86.avx512fp16.mask.sub.sh.round(<8 x half>, <8 x half>, <8 x half>, i8, i32)

define <8 x half> @test_int_x86_avx512fp16_mask_sub_sh(<8 x half> %x1, <8 x half> %x2, <8 x half> %src, i8 %mask, half * %ptr) {
; CHECK-LABEL: test_int_x86_avx512fp16_mask_sub_sh:
; CHECK:       # %bb.0:
; CHECK-NEXT:    kmovd %edi, %k1
; CHECK-NEXT:    vsubsh %xmm1, %xmm0, %xmm0
; CHECK-NEXT:    vmovaps %xmm2, %xmm3
; CHECK-NEXT:    vsubsh %xmm1, %xmm0, %xmm3 {%k1}
; CHECK-NEXT:    vsubsh %xmm1, %xmm3, %xmm0 {%k1} {z}
; CHECK-NEXT:    vsubsh (%rsi), %xmm0, %xmm2 {%k1}
; CHECK-NEXT:    vmovaps %xmm2, %xmm0
; CHECK-NEXT:    retq
  %val.half = load half,half * %ptr
  %val = insertelement <8 x half> undef, half %val.half, i32 0
  %res0 = call <8 x half> @llvm.x86.avx512fp16.mask.sub.sh.round(<8 x half> %x1, <8 x half> %x2, <8 x half> zeroinitializer, i8 -1, i32 4)
  %res1 = call <8 x half> @llvm.x86.avx512fp16.mask.sub.sh.round(<8 x half> %res0, <8 x half> %x2, <8 x half> %src , i8 %mask, i32 4)
  %res2 = call <8 x half> @llvm.x86.avx512fp16.mask.sub.sh.round(<8 x half> %res1, <8 x half> %x2, <8 x half> zeroinitializer , i8 %mask, i32 4)
  %res3 = call <8 x half> @llvm.x86.avx512fp16.mask.sub.sh.round(<8 x half> %res2, <8 x half> %val, <8 x half> %src , i8 %mask, i32 4)
  ret <8 x half> %res3
}

declare <8 x half> @llvm.x86.avx512fp16.mask.mul.sh.round(<8 x half>, <8 x half>, <8 x half>, i8, i32)

define <8 x half> @test_int_x86_avx512fp16_mask_mul_sh(<8 x half> %x1, <8 x half> %x2, <8 x half> %src, i8 %mask, half * %ptr) {
; CHECK-LABEL: test_int_x86_avx512fp16_mask_mul_sh:
; CHECK:       # %bb.0:
; CHECK-NEXT:    kmovd %edi, %k1
; CHECK-NEXT:    vmulsh %xmm1, %xmm0, %xmm0
; CHECK-NEXT:    vmovaps %xmm2, %xmm3
; CHECK-NEXT:    vmulsh %xmm1, %xmm0, %xmm3 {%k1}
; CHECK-NEXT:    vmulsh %xmm1, %xmm3, %xmm0 {%k1} {z}
; CHECK-NEXT:    vmulsh (%rsi), %xmm0, %xmm2 {%k1}
; CHECK-NEXT:    vmovaps %xmm2, %xmm0
; CHECK-NEXT:    retq
  %val.half = load half,half * %ptr
  %val = insertelement <8 x half> undef, half %val.half, i32 0
  %res0 = call <8 x half> @llvm.x86.avx512fp16.mask.mul.sh.round(<8 x half> %x1, <8 x half> %x2, <8 x half> zeroinitializer, i8 -1, i32 4)
  %res1 = call <8 x half> @llvm.x86.avx512fp16.mask.mul.sh.round(<8 x half> %res0, <8 x half> %x2, <8 x half> %src , i8 %mask, i32 4)
  %res2 = call <8 x half> @llvm.x86.avx512fp16.mask.mul.sh.round(<8 x half> %res1, <8 x half> %x2, <8 x half> zeroinitializer , i8 %mask, i32 4)
  %res3 = call <8 x half> @llvm.x86.avx512fp16.mask.mul.sh.round(<8 x half> %res2, <8 x half> %val, <8 x half> %src , i8 %mask, i32 4)
  ret <8 x half> %res3
}

declare <8 x half> @llvm.x86.avx512fp16.mask.div.sh.round(<8 x half>, <8 x half>, <8 x half>, i8, i32)

define <8 x half> @test_int_x86_avx512fp16_mask_div_sh(<8 x half> %x1, <8 x half> %x2, <8 x half> %src, i8 %mask, half * %ptr) {
; CHECK-LABEL: test_int_x86_avx512fp16_mask_div_sh:
; CHECK:       # %bb.0:
; CHECK-NEXT:    kmovd %edi, %k1
; CHECK-NEXT:    vdivsh %xmm1, %xmm0, %xmm0
; CHECK-NEXT:    vmovaps %xmm2, %xmm3
; CHECK-NEXT:    vdivsh %xmm1, %xmm0, %xmm3 {%k1}
; CHECK-NEXT:    vdivsh %xmm1, %xmm3, %xmm0 {%k1} {z}
; CHECK-NEXT:    vdivsh (%rsi), %xmm0, %xmm2 {%k1}
; CHECK-NEXT:    vmovaps %xmm2, %xmm0
; CHECK-NEXT:    retq
  %val.half = load half,half * %ptr
  %val = insertelement <8 x half> undef, half %val.half, i32 0
  %res0 = call <8 x half> @llvm.x86.avx512fp16.mask.div.sh.round(<8 x half> %x1, <8 x half> %x2, <8 x half> zeroinitializer, i8 -1, i32 4)
  %res1 = call <8 x half> @llvm.x86.avx512fp16.mask.div.sh.round(<8 x half> %res0, <8 x half> %x2, <8 x half> %src , i8 %mask, i32 4)
  %res2 = call <8 x half> @llvm.x86.avx512fp16.mask.div.sh.round(<8 x half> %res1, <8 x half> %x2, <8 x half> zeroinitializer , i8 %mask, i32 4)
  %res3 = call <8 x half> @llvm.x86.avx512fp16.mask.div.sh.round(<8 x half> %res2, <8 x half> %val, <8 x half> %src , i8 %mask, i32 4)
  ret <8 x half> %res3
}

declare <8 x half> @llvm.x86.avx512fp16.mask.min.sh.round(<8 x half>, <8 x half>, <8 x half>, i8, i32)

define <8 x half> @test_int_x86_avx512fp16_mask_min_sh(<8 x half> %x1, <8 x half> %x2, <8 x half> %src, i8 %mask, half * %ptr) {
; CHECK-LABEL: test_int_x86_avx512fp16_mask_min_sh:
; CHECK:       # %bb.0:
; CHECK-NEXT:    kmovd %edi, %k1
; CHECK-NEXT:    vminsh %xmm1, %xmm0, %xmm0
; CHECK-NEXT:    vmovaps %xmm2, %xmm3
; CHECK-NEXT:    vminsh %xmm1, %xmm0, %xmm3 {%k1}
; CHECK-NEXT:    vminsh %xmm1, %xmm3, %xmm0 {%k1} {z}
; CHECK-NEXT:    vminsh (%rsi), %xmm0, %xmm2 {%k1}
; CHECK-NEXT:    vmovaps %xmm2, %xmm0
; CHECK-NEXT:    retq
  %val.half = load half,half * %ptr
  %val = insertelement <8 x half> undef, half %val.half, i32 0
  %res0 = call <8 x half> @llvm.x86.avx512fp16.mask.min.sh.round(<8 x half> %x1, <8 x half> %x2, <8 x half> zeroinitializer, i8 -1, i32 4)
  %res1 = call <8 x half> @llvm.x86.avx512fp16.mask.min.sh.round(<8 x half> %res0, <8 x half> %x2, <8 x half> %src , i8 %mask, i32 4)
  %res2 = call <8 x half> @llvm.x86.avx512fp16.mask.min.sh.round(<8 x half> %res1, <8 x half> %x2, <8 x half> zeroinitializer , i8 %mask, i32 4)
  %res3 = call <8 x half> @llvm.x86.avx512fp16.mask.min.sh.round(<8 x half> %res2, <8 x half> %val, <8 x half> %src , i8 %mask, i32 4)
  ret <8 x half> %res3
}

declare <8 x half> @llvm.x86.avx512fp16.mask.max.sh.round(<8 x half>, <8 x half>, <8 x half>, i8, i32)

define <8 x half> @test_int_x86_avx512fp16_mask_max_sh(<8 x half> %x1, <8 x half> %x2, <8 x half> %src, i8 %mask, half * %ptr) {
; CHECK-LABEL: test_int_x86_avx512fp16_mask_max_sh:
; CHECK:       # %bb.0:
; CHECK-NEXT:    kmovd %edi, %k1
; CHECK-NEXT:    vmaxsh %xmm1, %xmm0, %xmm0
; CHECK-NEXT:    vmovaps %xmm2, %xmm3
; CHECK-NEXT:    vmaxsh %xmm1, %xmm0, %xmm3 {%k1}
; CHECK-NEXT:    vmaxsh %xmm1, %xmm3, %xmm0 {%k1} {z}
; CHECK-NEXT:    vmaxsh (%rsi), %xmm0, %xmm2 {%k1}
; CHECK-NEXT:    vmovaps %xmm2, %xmm0
; CHECK-NEXT:    retq
  %val.half = load half,half * %ptr
  %val = insertelement <8 x half> undef, half %val.half, i32 0
  %res0 = call <8 x half> @llvm.x86.avx512fp16.mask.max.sh.round(<8 x half> %x1, <8 x half> %x2, <8 x half> zeroinitializer, i8 -1, i32 4)
  %res1 = call <8 x half> @llvm.x86.avx512fp16.mask.max.sh.round(<8 x half> %res0, <8 x half> %x2, <8 x half> %src , i8 %mask, i32 4)
  %res2 = call <8 x half> @llvm.x86.avx512fp16.mask.max.sh.round(<8 x half> %res1, <8 x half> %x2, <8 x half> zeroinitializer , i8 %mask, i32 4)
  %res3 = call <8 x half> @llvm.x86.avx512fp16.mask.max.sh.round(<8 x half> %res2, <8 x half> %val, <8 x half> %src , i8 %mask, i32 4)
  ret <8 x half> %res3
}

declare i8 @llvm.x86.avx512fp16.mask.cmp.sh(<8 x half>, <8 x half>, i32, i8, i32)

define i8 @test_int_x86_avx512_mask_cmp_sh(<8 x half> %x0, <8 x half> %x1, i8 %x3, i32 %x4) {
; CHECK-LABEL: test_int_x86_avx512_mask_cmp_sh:
; CHECK:       # %bb.0:
; CHECK-NEXT:    kmovd %edi, %k1
; CHECK-NEXT:    vcmpunordsh %xmm1, %xmm0, %k0 {%k1}
; CHECK-NEXT:    kmovd %k0, %eax
; CHECK-NEXT:    # kill: def $al killed $al killed $eax
; CHECK-NEXT:    retq
  %res2 = call i8 @llvm.x86.avx512fp16.mask.cmp.sh(<8 x half> %x0, <8 x half> %x1, i32 3, i8 %x3, i32 4)
  ret i8 %res2
}


define i8 @test_int_x86_avx512_mask_cmp_sh_all(<8 x half> %x0, <8 x half> %x1, i8 %x3, i32 %x4) {
; CHECK-LABEL: test_int_x86_avx512_mask_cmp_sh_all:
; CHECK:       # %bb.0:
; CHECK-NEXT:    kmovd %edi, %k1
; CHECK-NEXT:    vcmplesh %xmm1, %xmm0, %k0
; CHECK-NEXT:    kmovd %k0, %ecx
; CHECK-NEXT:    vcmpunordsh {sae}, %xmm1, %xmm0, %k0
; CHECK-NEXT:    kmovd %k0, %edx
; CHECK-NEXT:    vcmpneqsh %xmm1, %xmm0, %k0 {%k1}
; CHECK-NEXT:    kmovd %k0, %esi
; CHECK-NEXT:    vcmpnltsh {sae}, %xmm1, %xmm0, %k0 {%k1}
; CHECK-NEXT:    kmovd %k0, %eax
; CHECK-NEXT:    andb %sil, %al
; CHECK-NEXT:    andb %dl, %al
; CHECK-NEXT:    andb %cl, %al
; CHECK-NEXT:    # kill: def $al killed $al killed $eax
; CHECK-NEXT:    retq
  %res1 = call i8 @llvm.x86.avx512fp16.mask.cmp.sh(<8 x half> %x0, <8 x half> %x1, i32 2, i8 -1, i32 4)
  %res2 = call i8 @llvm.x86.avx512fp16.mask.cmp.sh(<8 x half> %x0, <8 x half> %x1, i32 3, i8 -1, i32 8)
  %res3 = call i8 @llvm.x86.avx512fp16.mask.cmp.sh(<8 x half> %x0, <8 x half> %x1, i32 4, i8 %x3, i32 4)
  %res4 = call i8 @llvm.x86.avx512fp16.mask.cmp.sh(<8 x half> %x0, <8 x half> %x1, i32 5, i8 %x3, i32 8)

  %res11 = and i8 %res1, %res2
  %res12 = and i8 %res3, %res4
  %res13 = and i8 %res11, %res12
  ret i8 %res13
}
