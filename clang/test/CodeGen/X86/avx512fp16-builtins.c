// RUN: %clang_cc1 -ffreestanding -flax-vector-conversions=none %s -triple=x86_64-unknown-unknown -target-feature +avx512fp16 -emit-llvm -o - -Wall -Werror | FileCheck %s

#include <immintrin.h>

_Float16 test_mm512_cvtsh_h(__m512h __A) {
  // CHECK-LABEL: @test_mm512_cvtsh_h
  // CHECK: extractelement <32 x half> %{{.*}}, i32 0
  return _mm512_cvtsh_h(__A);
}

__m128h test_mm_setzero_ph() {
  // CHECK-LABEL: @test_mm_setzero_ph
  // CHECK: zeroinitializer
  return _mm_setzero_ph();
}

__m256h test_mm256_setzero_ph() {
  // CHECK-LABEL: @test_mm256_setzero_ph
  // CHECK: zeroinitializer
  return _mm256_setzero_ph();
}

__m256h test_mm256_undefined_ph() {
  // CHECK-LABEL: @test_mm256_undefined_ph
  // CHECK: ret <16 x half> zeroinitializer
  return _mm256_undefined_ph();
}

__m512h test_mm512_setzero_ph() {
  // CHECK-LABEL: @test_mm512_setzero_ph
  // CHECK: zeroinitializer
  return _mm512_setzero_ph();
}

__m128h test_mm_undefined_ph() {
  // CHECK-LABEL: @test_mm_undefined_ph
  // CHECK: ret <8 x half> zeroinitializer
  return _mm_undefined_ph();
}

__m512h test_mm512_undefined_ph() {
  // CHECK-LABEL: @test_mm512_undefined_ph
  // CHECK: ret <32 x half> zeroinitializer
  return _mm512_undefined_ph();
}

__m512h test_mm512_set1_ph(_Float16 h) {
  // CHECK-LABEL: @test_mm512_set1_ph
  // CHECK: insertelement <32 x half> {{.*}}, i32 0
  // CHECK: insertelement <32 x half> {{.*}}, i32 1
  // CHECK: insertelement <32 x half> {{.*}}, i32 2
  // CHECK: insertelement <32 x half> {{.*}}, i32 3
  // CHECK: insertelement <32 x half> {{.*}}, i32 4
  // CHECK: insertelement <32 x half> {{.*}}, i32 5
  // CHECK: insertelement <32 x half> {{.*}}, i32 6
  // CHECK: insertelement <32 x half> {{.*}}, i32 7
  // CHECK: insertelement <32 x half> {{.*}}, i32 8
  // CHECK: insertelement <32 x half> {{.*}}, i32 9
  // CHECK: insertelement <32 x half> {{.*}}, i32 10
  // CHECK: insertelement <32 x half> {{.*}}, i32 11
  // CHECK: insertelement <32 x half> {{.*}}, i32 12
  // CHECK: insertelement <32 x half> {{.*}}, i32 13
  // CHECK: insertelement <32 x half> {{.*}}, i32 14
  // CHECK: insertelement <32 x half> {{.*}}, i32 15
  // CHECK: insertelement <32 x half> {{.*}}, i32 16
  // CHECK: insertelement <32 x half> {{.*}}, i32 17
  // CHECK: insertelement <32 x half> {{.*}}, i32 18
  // CHECK: insertelement <32 x half> {{.*}}, i32 19
  // CHECK: insertelement <32 x half> {{.*}}, i32 20
  // CHECK: insertelement <32 x half> {{.*}}, i32 21
  // CHECK: insertelement <32 x half> {{.*}}, i32 22
  // CHECK: insertelement <32 x half> {{.*}}, i32 23
  // CHECK: insertelement <32 x half> {{.*}}, i32 24
  // CHECK: insertelement <32 x half> {{.*}}, i32 25
  // CHECK: insertelement <32 x half> {{.*}}, i32 26
  // CHECK: insertelement <32 x half> {{.*}}, i32 27
  // CHECK: insertelement <32 x half> {{.*}}, i32 28
  // CHECK: insertelement <32 x half> {{.*}}, i32 29
  // CHECK: insertelement <32 x half> {{.*}}, i32 30
  // CHECK: insertelement <32 x half> {{.*}}, i32 31
  return _mm512_set1_ph(h);
}

__m512h test_mm512_set_ph(_Float16 __h1, _Float16 __h2, _Float16 __h3, _Float16 __h4,
                          _Float16 __h5, _Float16 __h6, _Float16 __h7, _Float16 __h8,
                          _Float16 __h9, _Float16 __h10, _Float16 __h11, _Float16 __h12,
                          _Float16 __h13, _Float16 __h14, _Float16 __h15, _Float16 __h16,
                          _Float16 __h17, _Float16 __h18, _Float16 __h19, _Float16 __h20,
                          _Float16 __h21, _Float16 __h22, _Float16 __h23, _Float16 __h24,
                          _Float16 __h25, _Float16 __h26, _Float16 __h27, _Float16 __h28,
                          _Float16 __h29, _Float16 __h30, _Float16 __h31, _Float16 __h32) {
  // CHECK-LABEL: @test_mm512_set_ph
  // CHECK: insertelement <32 x half> {{.*}}, i32 0
  // CHECK: insertelement <32 x half> {{.*}}, i32 1
  // CHECK: insertelement <32 x half> {{.*}}, i32 2
  // CHECK: insertelement <32 x half> {{.*}}, i32 3
  // CHECK: insertelement <32 x half> {{.*}}, i32 4
  // CHECK: insertelement <32 x half> {{.*}}, i32 5
  // CHECK: insertelement <32 x half> {{.*}}, i32 6
  // CHECK: insertelement <32 x half> {{.*}}, i32 7
  // CHECK: insertelement <32 x half> {{.*}}, i32 8
  // CHECK: insertelement <32 x half> {{.*}}, i32 9
  // CHECK: insertelement <32 x half> {{.*}}, i32 10
  // CHECK: insertelement <32 x half> {{.*}}, i32 11
  // CHECK: insertelement <32 x half> {{.*}}, i32 12
  // CHECK: insertelement <32 x half> {{.*}}, i32 13
  // CHECK: insertelement <32 x half> {{.*}}, i32 14
  // CHECK: insertelement <32 x half> {{.*}}, i32 15
  // CHECK: insertelement <32 x half> {{.*}}, i32 16
  // CHECK: insertelement <32 x half> {{.*}}, i32 17
  // CHECK: insertelement <32 x half> {{.*}}, i32 18
  // CHECK: insertelement <32 x half> {{.*}}, i32 19
  // CHECK: insertelement <32 x half> {{.*}}, i32 20
  // CHECK: insertelement <32 x half> {{.*}}, i32 21
  // CHECK: insertelement <32 x half> {{.*}}, i32 22
  // CHECK: insertelement <32 x half> {{.*}}, i32 23
  // CHECK: insertelement <32 x half> {{.*}}, i32 24
  // CHECK: insertelement <32 x half> {{.*}}, i32 25
  // CHECK: insertelement <32 x half> {{.*}}, i32 26
  // CHECK: insertelement <32 x half> {{.*}}, i32 27
  // CHECK: insertelement <32 x half> {{.*}}, i32 28
  // CHECK: insertelement <32 x half> {{.*}}, i32 29
  // CHECK: insertelement <32 x half> {{.*}}, i32 30
  // CHECK: insertelement <32 x half> {{.*}}, i32 31
  return _mm512_set_ph(__h1, __h2, __h3, __h4, __h5, __h6, __h7, __h8,
                       __h9, __h10, __h11, __h12, __h13, __h14, __h15, __h16,
                       __h17, __h18, __h19, __h20, __h21, __h22, __h23, __h24,
                       __h25, __h26, __h27, __h28, __h29, __h30, __h31, __h32);
}

__m512h test_mm512_setr_ph(_Float16 __h1, _Float16 __h2, _Float16 __h3, _Float16 __h4,
                           _Float16 __h5, _Float16 __h6, _Float16 __h7, _Float16 __h8,
                           _Float16 __h9, _Float16 __h10, _Float16 __h11, _Float16 __h12,
                           _Float16 __h13, _Float16 __h14, _Float16 __h15, _Float16 __h16,
                           _Float16 __h17, _Float16 __h18, _Float16 __h19, _Float16 __h20,
                           _Float16 __h21, _Float16 __h22, _Float16 __h23, _Float16 __h24,
                           _Float16 __h25, _Float16 __h26, _Float16 __h27, _Float16 __h28,
                           _Float16 __h29, _Float16 __h30, _Float16 __h31, _Float16 __h32) {
  // CHECK-LABEL: @test_mm512_setr_ph
  // CHECK: insertelement <32 x half> {{.*}}, i32 0
  // CHECK: insertelement <32 x half> {{.*}}, i32 1
  // CHECK: insertelement <32 x half> {{.*}}, i32 2
  // CHECK: insertelement <32 x half> {{.*}}, i32 3
  // CHECK: insertelement <32 x half> {{.*}}, i32 4
  // CHECK: insertelement <32 x half> {{.*}}, i32 5
  // CHECK: insertelement <32 x half> {{.*}}, i32 6
  // CHECK: insertelement <32 x half> {{.*}}, i32 7
  // CHECK: insertelement <32 x half> {{.*}}, i32 8
  // CHECK: insertelement <32 x half> {{.*}}, i32 9
  // CHECK: insertelement <32 x half> {{.*}}, i32 10
  // CHECK: insertelement <32 x half> {{.*}}, i32 11
  // CHECK: insertelement <32 x half> {{.*}}, i32 12
  // CHECK: insertelement <32 x half> {{.*}}, i32 13
  // CHECK: insertelement <32 x half> {{.*}}, i32 14
  // CHECK: insertelement <32 x half> {{.*}}, i32 15
  // CHECK: insertelement <32 x half> {{.*}}, i32 16
  // CHECK: insertelement <32 x half> {{.*}}, i32 17
  // CHECK: insertelement <32 x half> {{.*}}, i32 18
  // CHECK: insertelement <32 x half> {{.*}}, i32 19
  // CHECK: insertelement <32 x half> {{.*}}, i32 20
  // CHECK: insertelement <32 x half> {{.*}}, i32 21
  // CHECK: insertelement <32 x half> {{.*}}, i32 22
  // CHECK: insertelement <32 x half> {{.*}}, i32 23
  // CHECK: insertelement <32 x half> {{.*}}, i32 24
  // CHECK: insertelement <32 x half> {{.*}}, i32 25
  // CHECK: insertelement <32 x half> {{.*}}, i32 26
  // CHECK: insertelement <32 x half> {{.*}}, i32 27
  // CHECK: insertelement <32 x half> {{.*}}, i32 28
  // CHECK: insertelement <32 x half> {{.*}}, i32 29
  // CHECK: insertelement <32 x half> {{.*}}, i32 30
  // CHECK: insertelement <32 x half> {{.*}}, i32 31
  return _mm512_setr_ph(__h1, __h2, __h3, __h4, __h5, __h6, __h7, __h8,
                        __h9, __h10, __h11, __h12, __h13, __h14, __h15, __h16,
                        __h17, __h18, __h19, __h20, __h21, __h22, __h23, __h24,
                        __h25, __h26, __h27, __h28, __h29, __h30, __h31, __h32);
}

__m128 test_mm_castph_ps(__m128h A) {
  // CHECK-LABEL: test_mm_castph_ps
  // CHECK: bitcast <8 x half> %{{.*}} to <4 x float>
  return _mm_castph_ps(A);
}

__m256 test_mm256_castph_ps(__m256h A) {
  // CHECK-LABEL: test_mm256_castph_ps
  // CHECK: bitcast <16 x half> %{{.*}} to <8 x float>
  return _mm256_castph_ps(A);
}

__m512 test_mm512_castph_ps(__m512h A) {
  // CHECK-LABEL: test_mm512_castph_ps
  // CHECK: bitcast <32 x half> %{{.*}} to <16 x float>
  return _mm512_castph_ps(A);
}

__m128d test_mm_castph_pd(__m128h A) {
  // CHECK-LABEL: test_mm_castph_pd
  // CHECK: bitcast <8 x half> %{{.*}} to <2 x double>
  return _mm_castph_pd(A);
}

__m256d test_mm256_castph_pd(__m256h A) {
  // CHECK-LABEL: test_mm256_castph_pd
  // CHECK: bitcast <16 x half> %{{.*}} to <4 x double>
  return _mm256_castph_pd(A);
}

__m512d test_mm512_castph_pd(__m512h A) {
  // CHECK-LABEL: test_mm512_castph_pd
  // CHECK: bitcast <32 x half> %{{.*}} to <8 x double>
  return _mm512_castph_pd(A);
}

__m128i test_mm_castph_si128(__m128h A) {
  // CHECK-LABEL: test_mm_castph_si128
  // CHECK: bitcast <8 x half> %{{.*}} to <2 x i64>
  return _mm_castph_si128(A);
}

__m256i test_mm256_castph_si256(__m256h A) {
  // CHECK-LABEL: test_mm256_castph_si256
  // CHECK: bitcast <16 x half> %{{.*}} to <4 x i64>
  return _mm256_castph_si256(A);
}

__m512i test_mm512_castph_si512(__m512h A) {
  // CHECK-LABEL: test_mm512_castph_si512
  // CHECK: bitcast <32 x half> %{{.*}} to <8 x i64>
  return _mm512_castph_si512(A);
}

__m128h test_mm_castps_ph(__m128 A) {
  // CHECK-LABEL: test_mm_castps_ph
  // CHECK: bitcast <4 x float> %{{.*}} to <8 x half>
  return _mm_castps_ph(A);
}

__m256h test_mm256_castps_ph(__m256 A) {
  // CHECK-LABEL: test_mm256_castps_ph
  // CHECK: bitcast <8 x float> %{{.*}} to <16 x half>
  return _mm256_castps_ph(A);
}

__m512h test_mm512_castps_ph(__m512 A) {
  // CHECK-LABEL: test_mm512_castps_ph
  // CHECK: bitcast <16 x float> %{{.*}} to <32 x half>
  return _mm512_castps_ph(A);
}

__m128h test_mm_castpd_ph(__m128d A) {
  // CHECK-LABEL: test_mm_castpd_ph
  // CHECK: bitcast <2 x double> %{{.*}} to <8 x half>
  return _mm_castpd_ph(A);
}

__m256h test_mm256_castpd_ph(__m256d A) {
  // CHECK-LABEL: test_mm256_castpd_ph
  // CHECK: bitcast <4 x double> %{{.*}} to <16 x half>
  return _mm256_castpd_ph(A);
}

__m512h test_mm512_castpd_ph(__m512d A) {
  // CHECK-LABEL: test_mm512_castpd_ph
  // CHECK: bitcast <8 x double> %{{.*}} to <32 x half>
  return _mm512_castpd_ph(A);
}

__m128h test_mm_castsi128_ph(__m128i A) {
  // CHECK-LABEL: test_mm_castsi128_ph
  // CHECK: bitcast <2 x i64> %{{.*}} to <8 x half>
  return _mm_castsi128_ph(A);
}

__m256h test_mm256_castsi256_ph(__m256i A) {
  // CHECK-LABEL: test_mm256_castsi256_ph
  // CHECK: bitcast <4 x i64> %{{.*}} to <16 x half>
  return _mm256_castsi256_ph(A);
}

__m512h test_mm512_castsi512_ph(__m512i A) {
  // CHECK-LABEL: test_mm512_castsi512_ph
  // CHECK: bitcast <8 x i64> %{{.*}} to <32 x half>
  return _mm512_castsi512_ph(A);
}

__m128h test_mm256_castph256_ph128(__m256h __a) {
  // CHECK-LABEL: test_mm256_castph256_ph128
  // CHECK: shufflevector <16 x half> %{{.*}}, <16 x half> %{{.*}}, <8 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
  return _mm256_castph256_ph128(__a);
}

__m128h test_mm512_castph512_ph128(__m512h __a) {
  // CHECK-LABEL: test_mm512_castph512_ph128
  // CHECK: shufflevector <32 x half> %{{.*}}, <32 x half> %{{.*}}, <8 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
  return _mm512_castph512_ph128(__a);
}

__m256h test_mm512_castph512_ph256(__m512h __a) {
  // CHECK-LABEL: test_mm512_castph512_ph256
  // CHECK: shufflevector <32 x half> %{{.*}}, <32 x half> %{{.*}}, <16 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
  return _mm512_castph512_ph256(__a);
}

__m256h test_mm256_castph128_ph256(__m128h __a) {
  // CHECK-LABEL: test_mm256_castph128_ph256
  // CHECK: shufflevector <8 x half> %{{.*}}, <8 x half> %{{.*}}, <16 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
  return _mm256_castph128_ph256(__a);
}

__m512h test_mm512_castph128_ph512(__m128h __a) {
  // CHECK-LABEL: test_mm512_castph128_ph512
  // CHECK: shufflevector <8 x half> %{{.*}}, <8 x half> %{{.*}}, <32 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
  return _mm512_castph128_ph512(__a);
}

__m512h test_mm512_castph256_ph512(__m256h __a) {
  // CHECK-LABEL: test_mm512_castph256_ph512
  // CHECK: shufflevector <16 x half> %{{.*}}, <16 x half> %{{.*}}, <32 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef, i32 undef>
  return _mm512_castph256_ph512(__a);
}

__m256h test_mm256_zextph128_ph256(__m128h __a) {
  // CHECK-LABEL: test_mm256_zextph128_ph256
  // CHECK: shufflevector <8 x half> %{{.*}}, <8 x half> {{.*}}, <16 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
  return _mm256_zextph128_ph256(__a);
}

__m512h test_mm512_zextph128_ph512(__m128h __a) {
  // CHECK-LABEL: test_mm512_zextph128_ph512
  // CHECK: shufflevector <8 x half> %{{.*}}, <8 x half> {{.*}}, <32 x i32> <i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
  return _mm512_zextph128_ph512(__a);
}

__m512h test_mm512_zextph256_ph512(__m256h __a) {
  // CHECK-LABEL: test_mm512_zextph256_ph512
  // CHECK: shufflevector <16 x half> %{{.*}}, <16 x half> {{.*}}, <32 x i32>
  return _mm512_zextph256_ph512(__a);
}

int test_mm_comi_round_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: test_mm_comi_round_sh
  // CHECK: %{{.}} = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %{{.}}, <8 x half> %{{.}}, i32 0, i32 8)
  return _mm_comi_round_sh(__A, __B, 0, _MM_FROUND_NO_EXC);
}

int test_mm_comi_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: test_mm_comi_sh
  // CHECK: %{{.}} = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %{{.}}, <8 x half> %{{.}}, i32 0, i32 4)
  return _mm_comi_sh(__A, __B, 0);
}

int test_mm_comieq_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: test_mm_comieq_sh
  // CHECK: %{{.}} = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %{{.}}, <8 x half> %{{.}}, i32 16, i32 4)
  return _mm_comieq_sh(__A, __B);
}

int test_mm_comilt_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: test_mm_comilt_sh
  // CHECK: %{{.}} = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %{{.}}, <8 x half> %{{.}}, i32 1, i32 4)
  return _mm_comilt_sh(__A, __B);
}

int test_mm_comile_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: test_mm_comile_sh
  // CHECK: %{{.}} = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %{{.}}, <8 x half> %{{.}}, i32 2, i32 4)
  return _mm_comile_sh(__A, __B);
}

int test_mm_comigt_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: test_mm_comigt_sh
  // CHECK: %{{.}} = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %{{.}}, <8 x half> %{{.}}, i32 14, i32 4)
  return _mm_comigt_sh(__A, __B);
}

int test_mm_comige_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: test_mm_comige_sh
  // CHECK: %{{.}} = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %{{.}}, <8 x half> %{{.}}, i32 13, i32 4)
  return _mm_comige_sh(__A, __B);
}

int test_mm_comineq_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: test_mm_comineq_sh
  // CHECK: %{{.}} = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %{{.}}, <8 x half> %{{.}}, i32 20, i32 4)
  return _mm_comineq_sh(__A, __B);
}

int test_mm_ucomieq_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: test_mm_ucomieq_sh
  // CHECK: %{{.}} = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %{{.}}, <8 x half> %{{.}}, i32 0, i32 4)
  return _mm_ucomieq_sh(__A, __B);
}

int test_mm_ucomilt_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: test_mm_ucomilt_sh
  // CHECK: %{{.}} = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %{{.}}, <8 x half> %{{.}}, i32 17, i32 4)
  return _mm_ucomilt_sh(__A, __B);
}

int test_mm_ucomile_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: test_mm_ucomile_sh
  // CHECK: %{{.}} = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %{{.}}, <8 x half> %{{.}}, i32 18, i32 4)
  return _mm_ucomile_sh(__A, __B);
}

int test_mm_ucomigt_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: test_mm_ucomigt_sh
  // CHECK: %{{.}} = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %{{.}}, <8 x half> %{{.}}, i32 30, i32 4)
  return _mm_ucomigt_sh(__A, __B);
}

int test_mm_ucomige_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: test_mm_ucomige_sh
  // CHECK: %{{.}} = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %{{.}}, <8 x half> %{{.}}, i32 29, i32 4)
  return _mm_ucomige_sh(__A, __B);
}

int test_mm_ucomineq_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: test_mm_ucomineq_sh
  // CHECK: %{{.}} = call i32 @llvm.x86.avx512fp16.vcomi.sh(<8 x half> %{{.}}, <8 x half> %{{.}}, i32 4, i32 4)
  return _mm_ucomineq_sh(__A, __B);
}

__m512h test_mm512_add_ph(__m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_add_ph
  // CHECK: %{{.*}} = fadd <32 x half> %{{.*}}, %{{.*}}
  return _mm512_add_ph(__A, __B);
}

__m512h test_mm512_mask_add_ph(__m512h __W, __mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_mask_add_ph
  // CHECK: %{{.*}} = fadd <32 x half> %{{.*}}, %{{.*}}
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return (__m512h)_mm512_mask_add_ph(__W, __U, __A, __B);
}

__m512h test_mm512_maskz_add_ph(__mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_maskz_add_ph
  // CHECK: %{{.*}} = fadd <32 x half> %{{.*}}, %{{.*}}
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_maskz_add_ph(__U, __A, __B);
}

__m512h test_mm512_add_round_ph(__m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_add_round_ph
  // CHECK: @llvm.x86.avx512fp16.add.ph.512
  return _mm512_add_round_ph(__A, __B, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
}
__m512h test_mm512_mask_add_round_ph(__m512h __W, __mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_mask_add_round_ph
  // CHECK: @llvm.x86.avx512fp16.add.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_mask_add_round_ph(__W, __U, __A, __B, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
}
__m512h test_mm512_maskz_add_round_ph(__mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_maskz_add_round_ph
  // CHECK: @llvm.x86.avx512fp16.add.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_maskz_add_round_ph(__U, __A, __B, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
}

__m512h test_mm512_sub_ph(__m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_sub_ph
  // CHECK: %{{.*}} = fsub <32 x half> %{{.*}}, %{{.*}}
  return _mm512_sub_ph(__A, __B);
}

__m512h test_mm512_mask_sub_ph(__m512h __W, __mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_mask_sub_ph
  // CHECK: %{{.*}} = fsub <32 x half> %{{.*}}, %{{.*}}
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return (__m512h)_mm512_mask_sub_ph(__W, __U, __A, __B);
}

__m512h test_mm512_maskz_sub_ph(__mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_maskz_sub_ph
  // CHECK: %{{.*}} = fsub <32 x half> %{{.*}}, %{{.*}}
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_maskz_sub_ph(__U, __A, __B);
}

__m512h test_mm512_sub_round_ph(__m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_sub_round_ph
  // CHECK: @llvm.x86.avx512fp16.sub.ph.512
  return _mm512_sub_round_ph(__A, __B, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
}
__m512h test_mm512_mask_sub_round_ph(__m512h __W, __mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_mask_sub_round_ph
  // CHECK: @llvm.x86.avx512fp16.sub.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_mask_sub_round_ph(__W, __U, __A, __B, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
}
__m512h test_mm512_maskz_sub_round_ph(__mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_maskz_sub_round_ph
  // CHECK: @llvm.x86.avx512fp16.sub.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_maskz_sub_round_ph(__U, __A, __B, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
}

__m512h test_mm512_mul_ph(__m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_mul_ph
  // CHECK: %{{.*}} = fmul <32 x half> %{{.*}}, %{{.*}}
  return _mm512_mul_ph(__A, __B);
}

__m512h test_mm512_mask_mul_ph(__m512h __W, __mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_mask_mul_ph
  // CHECK: %{{.*}} = fmul <32 x half> %{{.*}}, %{{.*}}
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return (__m512h)_mm512_mask_mul_ph(__W, __U, __A, __B);
}

__m512h test_mm512_maskz_mul_ph(__mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_maskz_mul_ph
  // CHECK: %{{.*}} = fmul <32 x half> %{{.*}}, %{{.*}}
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_maskz_mul_ph(__U, __A, __B);
}

__m512h test_mm512_mul_round_ph(__m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_mul_round_ph
  // CHECK: @llvm.x86.avx512fp16.mul.ph.512
  return _mm512_mul_round_ph(__A, __B, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
}
__m512h test_mm512_mask_mul_round_ph(__m512h __W, __mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_mask_mul_round_ph
  // CHECK: @llvm.x86.avx512fp16.mul.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_mask_mul_round_ph(__W, __U, __A, __B, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
}
__m512h test_mm512_maskz_mul_round_ph(__mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_maskz_mul_round_ph
  // CHECK: @llvm.x86.avx512fp16.mul.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_maskz_mul_round_ph(__U, __A, __B, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
}

__m512h test_mm512_div_ph(__m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_div_ph
  // CHECK: %{{.*}} = fdiv <32 x half> %{{.*}}, %{{.*}}
  return _mm512_div_ph(__A, __B);
}

__m512h test_mm512_mask_div_ph(__m512h __W, __mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_mask_div_ph
  // CHECK: %{{.*}} = fdiv <32 x half> %{{.*}}, %{{.*}}
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return (__m512h)_mm512_mask_div_ph(__W, __U, __A, __B);
}

__m512h test_mm512_maskz_div_ph(__mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_maskz_div_ph
  // CHECK: %{{.*}} = fdiv <32 x half> %{{.*}}, %{{.*}}
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_maskz_div_ph(__U, __A, __B);
}

__m512h test_mm512_div_round_ph(__m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_div_round_ph
  // CHECK: @llvm.x86.avx512fp16.div.ph.512
  return _mm512_div_round_ph(__A, __B, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
}
__m512h test_mm512_mask_div_round_ph(__m512h __W, __mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_mask_div_round_ph
  // CHECK: @llvm.x86.avx512fp16.div.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_mask_div_round_ph(__W, __U, __A, __B, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
}
__m512h test_mm512_maskz_div_round_ph(__mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_maskz_div_round_ph
  // CHECK: @llvm.x86.avx512fp16.div.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_maskz_div_round_ph(__U, __A, __B, _MM_FROUND_TO_ZERO | _MM_FROUND_NO_EXC);
}

__m512h test_mm512_min_ph(__m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_min_ph
  // CHECK: @llvm.x86.avx512fp16.min.ph.512
  return _mm512_min_ph(__A, __B);
}

__m512h test_mm512_mask_min_ph(__m512h __W, __mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_mask_min_ph
  // CHECK: @llvm.x86.avx512fp16.min.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return (__m512h)_mm512_mask_min_ph(__W, __U, __A, __B);
}

__m512h test_mm512_maskz_min_ph(__mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_maskz_min_ph
  // CHECK: @llvm.x86.avx512fp16.min.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_maskz_min_ph(__U, __A, __B);
}

__m512h test_mm512_min_round_ph(__m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_min_round_ph
  // CHECK: @llvm.x86.avx512fp16.min.ph.512
  return _mm512_min_round_ph(__A, __B, _MM_FROUND_NO_EXC);
}
__m512h test_mm512_mask_min_round_ph(__m512h __W, __mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_mask_min_round_ph
  // CHECK: @llvm.x86.avx512fp16.min.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_mask_min_round_ph(__W, __U, __A, __B, _MM_FROUND_NO_EXC);
}
__m512h test_mm512_maskz_min_round_ph(__mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_maskz_min_round_ph
  // CHECK: @llvm.x86.avx512fp16.min.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_maskz_min_round_ph(__U, __A, __B, _MM_FROUND_NO_EXC);
}

__m512h test_mm512_max_ph(__m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_max_ph
  // CHECK: @llvm.x86.avx512fp16.max.ph.512

  return _mm512_max_ph(__A, __B);
}

__m512h test_mm512_mask_max_ph(__m512h __W, __mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_mask_max_ph
  // CHECK: @llvm.x86.avx512fp16.max.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return (__m512h)_mm512_mask_max_ph(__W, __U, __A, __B);
}

__m512h test_mm512_maskz_max_ph(__mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_maskz_max_ph
  // CHECK: @llvm.x86.avx512fp16.max.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_maskz_max_ph(__U, __A, __B);
}

__m512h test_mm512_max_round_ph(__m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_max_round_ph
  // CHECK: @llvm.x86.avx512fp16.max.ph.512
  return _mm512_max_round_ph(__A, __B, _MM_FROUND_NO_EXC);
}

__m512h test_mm512_mask_max_round_ph(__m512h __W, __mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_mask_max_round_ph
  // CHECK: @llvm.x86.avx512fp16.max.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_mask_max_round_ph(__W, __U, __A, __B, _MM_FROUND_NO_EXC);
}

__m512h test_mm512_maskz_max_round_ph(__mmask32 __U, __m512h __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_maskz_max_round_ph
  // CHECK: @llvm.x86.avx512fp16.max.ph.512
  // CHECK: select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_maskz_max_round_ph(__U, __A, __B, _MM_FROUND_NO_EXC);
}

__m512h test_mm512_abs_ph(__m512h a) {
  // CHECK-LABEL: @test_mm512_abs_ph
  // CHECK: and <16 x i32>
  return _mm512_abs_ph(a);
}

__m128h test_mm_add_round_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_add_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.add.sh.round
  return _mm_add_round_sh(__A, __B, _MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO);
}
__m128h test_mm_mask_add_round_sh(__m128h __W, __mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mask_add_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.add.sh.round
  return _mm_mask_add_round_sh(__W, __U, __A, __B, _MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO);
}
__m128h test_mm_maskz_add_round_sh(__mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_maskz_add_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.add.sh.round
  return _mm_maskz_add_round_sh(__U, __A, __B, _MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO);
}
__m128h test_mm_mask_add_sh(__m128h __W, __mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mask_add_sh
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = fadd half %{{.*}}, %{{.*}}
  // CHECK: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = bitcast i8 %{{.*}} to <8 x i1>
  // CHECK-NEXT: %{{.*}} = extractelement <8 x i1> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = select i1 %{{.*}}, half %{{.*}}, half %{{.*}}
  // CHECK-NEXT: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i64 0
  return _mm_mask_add_sh(__W, __U, __A, __B);
}
__m128h test_mm_maskz_add_sh(__mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_maskz_add_sh
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = fadd half %{{.*}}, %{{.*}}
  // CHECK: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = bitcast i8 %{{.*}} to <8 x i1>
  // CHECK-NEXT: %{{.*}} = extractelement <8 x i1> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = select i1 %{{.*}}, half %{{.*}}, half %{{.*}}
  // CHECK-NEXT: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i64 0
  return _mm_maskz_add_sh(__U, __A, __B);
}

__m128h test_mm_add_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_add_sh
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = fadd half %{{.*}}, %{{.*}}
  // CHECK: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i32 0
  return _mm_add_sh(__A, __B);
}

__m128h test_mm_sub_round_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_sub_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.sub.sh.round
  return _mm_sub_round_sh(__A, __B, _MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO);
}
__m128h test_mm_mask_sub_round_sh(__m128h __W, __mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mask_sub_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.sub.sh.round
  return _mm_mask_sub_round_sh(__W, __U, __A, __B, _MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO);
}
__m128h test_mm_maskz_sub_round_sh(__mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_maskz_sub_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.sub.sh.round
  return _mm_maskz_sub_round_sh(__U, __A, __B, _MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO);
}
__m128h test_mm_mask_sub_sh(__m128h __W, __mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mask_sub_sh
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = fsub half %{{.*}}, %{{.*}}
  // CHECK: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = bitcast i8 %{{.*}} to <8 x i1>
  // CHECK-NEXT: %{{.*}} = extractelement <8 x i1> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = select i1 %{{.*}}, half %{{.*}}, half %{{.*}}
  // CHECK-NEXT: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i64 0
  return _mm_mask_sub_sh(__W, __U, __A, __B);
}
__m128h test_mm_maskz_sub_sh(__mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_maskz_sub_sh
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = fsub half %{{.*}}, %{{.*}}
  // CHECK: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = bitcast i8 %{{.*}} to <8 x i1>
  // CHECK-NEXT: %{{.*}} = extractelement <8 x i1> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = select i1 %{{.*}}, half %{{.*}}, half %{{.*}}
  // CHECK-NEXT: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i64 0
  return _mm_maskz_sub_sh(__U, __A, __B);
}

__m128h test_mm_sub_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_sub_sh
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = fsub half %{{.*}}, %{{.*}}
  // CHECK: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i32 0
  return _mm_sub_sh(__A, __B);
}

__m128h test_mm_mul_round_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mul_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.mul.sh.round
  return _mm_mul_round_sh(__A, __B, _MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO);
}
__m128h test_mm_mask_mul_round_sh(__m128h __W, __mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mask_mul_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.mul.sh.round
  return _mm_mask_mul_round_sh(__W, __U, __A, __B, _MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO);
}
__m128h test_mm_maskz_mul_round_sh(__mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_maskz_mul_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.mul.sh.round
  return _mm_maskz_mul_round_sh(__U, __A, __B, _MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO);
}
__m128h test_mm_mask_mul_sh(__m128h __W, __mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mask_mul_sh
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = fmul half %{{.*}}, %{{.*}}
  // CHECK: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = bitcast i8 %{{.*}} to <8 x i1>
  // CHECK-NEXT: %{{.*}} = extractelement <8 x i1> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = select i1 %{{.*}}, half %{{.*}}, half %{{.*}}
  // CHECK-NEXT: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i64 0
  return _mm_mask_mul_sh(__W, __U, __A, __B);
}
__m128h test_mm_maskz_mul_sh(__mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_maskz_mul_sh
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = fmul half %{{.*}}, %{{.*}}
  // CHECK: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = bitcast i8 %{{.*}} to <8 x i1>
  // CHECK-NEXT: %{{.*}} = extractelement <8 x i1> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = select i1 %{{.*}}, half %{{.*}}, half %{{.*}}
  // CHECK-NEXT: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i64 0
  return _mm_maskz_mul_sh(__U, __A, __B);
}

__m128h test_mm_mul_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mul_sh
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = fmul half %{{.*}}, %{{.*}}
  // CHECK: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i32 0
  return _mm_mul_sh(__A, __B);
}

__m128h test_mm_div_round_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_div_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.div.sh.round
  return _mm_div_round_sh(__A, __B, _MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO);
}
__m128h test_mm_mask_div_round_sh(__m128h __W, __mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mask_div_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.div.sh.round
  return _mm_mask_div_round_sh(__W, __U, __A, __B, _MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO);
}
__m128h test_mm_maskz_div_round_sh(__mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_maskz_div_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.div.sh.round
  return _mm_maskz_div_round_sh(__U, __A, __B, _MM_FROUND_NO_EXC | _MM_FROUND_TO_ZERO);
}
__m128h test_mm_mask_div_sh(__m128h __W, __mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mask_div_sh
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = fdiv half %{{.*}}, %{{.*}}
  // CHECK: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = bitcast i8 %{{.*}} to <8 x i1>
  // CHECK-NEXT: %{{.*}} = extractelement <8 x i1> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = select i1 %{{.*}}, half %{{.*}}, half %{{.*}}
  // CHECK-NEXT: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i64 0
  return _mm_mask_div_sh(__W, __U, __A, __B);
}
__m128h test_mm_maskz_div_sh(__mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_maskz_div_sh
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = fdiv half %{{.*}}, %{{.*}}
  // CHECK: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = bitcast i8 %{{.*}} to <8 x i1>
  // CHECK-NEXT: %{{.*}} = extractelement <8 x i1> %{{.*}}, i64 0
  // CHECK-NEXT: %{{.*}} = select i1 %{{.*}}, half %{{.*}}, half %{{.*}}
  // CHECK-NEXT: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i64 0
  return _mm_maskz_div_sh(__U, __A, __B);
}

__m128h test_mm_div_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_div_sh
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: %{{.*}} = fdiv half %{{.*}}, %{{.*}}
  // CHECK: %{{.*}} = insertelement <8 x half> %{{.*}}, half %{{.*}}, i32 0
  return _mm_div_sh(__A, __B);
}

__m128h test_mm_min_round_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_min_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.min.sh.round
  return _mm_min_round_sh(__A, __B, 0x08);
}
__m128h test_mm_mask_min_round_sh(__m128h __W, __mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mask_min_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.min.sh.round
  return _mm_mask_min_round_sh(__W, __U, __A, __B, 0x08);
}
__m128h test_mm_maskz_min_round_sh(__mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_maskz_min_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.min.sh.round
  return _mm_maskz_min_round_sh(__U, __A, __B, 0x08);
}
__m128h test_mm_mask_min_sh(__m128h __W, __mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mask_min_sh
  // CHECK: @llvm.x86.avx512fp16.mask.min.sh.round
  return _mm_mask_min_sh(__W, __U, __A, __B);
}
__m128h test_mm_maskz_min_sh(__mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_maskz_min_sh
  // CHECK: @llvm.x86.avx512fp16.mask.min.sh.round
  return _mm_maskz_min_sh(__U, __A, __B);
}

__m128h test_mm_min_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_min_sh
  // CHECK: @llvm.x86.avx512fp16.mask.min.sh.round
  return _mm_min_sh(__A, __B);
}

__m128h test_mm_max_round_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_max_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.max.sh.round
  return _mm_max_round_sh(__A, __B, 0x08);
}
__m128h test_mm_mask_max_round_sh(__m128h __W, __mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mask_max_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.max.sh.round
  return _mm_mask_max_round_sh(__W, __U, __A, __B, 0x08);
}
__m128h test_mm_maskz_max_round_sh(__mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_maskz_max_round_sh
  // CHECK: @llvm.x86.avx512fp16.mask.max.sh.round
  return _mm_maskz_max_round_sh(__U, __A, __B, 0x08);
}
__m128h test_mm_mask_max_sh(__m128h __W, __mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mask_max_sh
  // CHECK: @llvm.x86.avx512fp16.mask.max.sh.round
  return _mm_mask_max_sh(__W, __U, __A, __B);
}
__m128h test_mm_maskz_max_sh(__mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_maskz_max_sh
  // CHECK: @llvm.x86.avx512fp16.mask.max.sh.round
  return _mm_maskz_max_sh(__U, __A, __B);
}

__m128h test_mm_max_sh(__m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_max_sh
  // CHECK: @llvm.x86.avx512fp16.mask.max.sh.round
  return _mm_max_sh(__A, __B);
}
__mmask32 test_mm512_cmp_round_ph_mask(__m512h a, __m512h b) {
  // CHECK-LABEL: @test_mm512_cmp_round_ph_mask
  // CHECK: fcmp oeq <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_round_ph_mask(a, b, 0, _MM_FROUND_NO_EXC);
}

__mmask32 test_mm512_mask_cmp_round_ph_mask(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: @test_mm512_mask_cmp_round_ph_mask
  // CHECK: [[CMP:%.*]] = fcmp oeq <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_round_ph_mask(m, a, b, 0, _MM_FROUND_NO_EXC);
}

__mmask32 test_mm512_cmp_ph_mask_eq_oq(__m512h a, __m512h b) {
  // CHECK-LABEL: @test_mm512_cmp_ph_mask_eq_oq
  // CHECK: fcmp oeq <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_EQ_OQ);
}

__mmask32 test_mm512_cmp_ph_mask_lt_os(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_lt_os
  // CHECK: fcmp olt <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_LT_OS);
}

__mmask32 test_mm512_cmp_ph_mask_le_os(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_le_os
  // CHECK: fcmp ole <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_LE_OS);
}

__mmask32 test_mm512_cmp_ph_mask_unord_q(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_unord_q
  // CHECK: fcmp uno <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_UNORD_Q);
}

__mmask32 test_mm512_cmp_ph_mask_neq_uq(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_neq_uq
  // CHECK: fcmp une <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_NEQ_UQ);
}

__mmask32 test_mm512_cmp_ph_mask_nlt_us(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_nlt_us
  // CHECK: fcmp uge <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_NLT_US);
}

__mmask32 test_mm512_cmp_ph_mask_nle_us(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_nle_us
  // CHECK: fcmp ugt <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_NLE_US);
}

__mmask32 test_mm512_cmp_ph_mask_ord_q(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_ord_q
  // CHECK: fcmp ord <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_ORD_Q);
}

__mmask32 test_mm512_cmp_ph_mask_eq_uq(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_eq_uq
  // CHECK: fcmp ueq <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_EQ_UQ);
}

__mmask32 test_mm512_cmp_ph_mask_nge_us(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_nge_us
  // CHECK: fcmp ult <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_NGE_US);
}

__mmask32 test_mm512_cmp_ph_mask_ngt_us(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_ngt_us
  // CHECK: fcmp ule <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_NGT_US);
}

__mmask32 test_mm512_cmp_ph_mask_false_oq(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_false_oq
  // CHECK: fcmp false <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_FALSE_OQ);
}

__mmask32 test_mm512_cmp_ph_mask_neq_oq(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_neq_oq
  // CHECK: fcmp one <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_NEQ_OQ);
}

__mmask32 test_mm512_cmp_ph_mask_ge_os(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_ge_os
  // CHECK: fcmp oge <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_GE_OS);
}

__mmask32 test_mm512_cmp_ph_mask_gt_os(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_gt_os
  // CHECK: fcmp ogt <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_GT_OS);
}

__mmask32 test_mm512_cmp_ph_mask_true_uq(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_true_uq
  // CHECK: fcmp true <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_TRUE_UQ);
}

__mmask32 test_mm512_cmp_ph_mask_eq_os(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_eq_os
  // CHECK: fcmp oeq <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_EQ_OS);
}

__mmask32 test_mm512_cmp_ph_mask_lt_oq(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_lt_oq
  // CHECK: fcmp olt <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_LT_OQ);
}

__mmask32 test_mm512_cmp_ph_mask_le_oq(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_le_oq
  // CHECK: fcmp ole <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_LE_OQ);
}

__mmask32 test_mm512_cmp_ph_mask_unord_s(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_unord_s
  // CHECK: fcmp uno <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_UNORD_S);
}

__mmask32 test_mm512_cmp_ph_mask_neq_us(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_neq_us
  // CHECK: fcmp une <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_NEQ_US);
}

__mmask32 test_mm512_cmp_ph_mask_nlt_uq(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_nlt_uq
  // CHECK: fcmp uge <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_NLT_UQ);
}

__mmask32 test_mm512_cmp_ph_mask_nle_uq(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_nle_uq
  // CHECK: fcmp ugt <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_NLE_UQ);
}

__mmask32 test_mm512_cmp_ph_mask_ord_s(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_ord_s
  // CHECK: fcmp ord <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_ORD_S);
}

__mmask32 test_mm512_cmp_ph_mask_eq_us(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_eq_us
  // CHECK: fcmp ueq <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_EQ_US);
}

__mmask32 test_mm512_cmp_ph_mask_nge_uq(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_nge_uq
  // CHECK: fcmp ult <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_NGE_UQ);
}

__mmask32 test_mm512_cmp_ph_mask_ngt_uq(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_ngt_uq
  // CHECK: fcmp ule <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_NGT_UQ);
}

__mmask32 test_mm512_cmp_ph_mask_false_os(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_false_os
  // CHECK: fcmp false <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_FALSE_OS);
}

__mmask32 test_mm512_cmp_ph_mask_neq_os(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_neq_os
  // CHECK: fcmp one <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_NEQ_OS);
}

__mmask32 test_mm512_cmp_ph_mask_ge_oq(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_ge_oq
  // CHECK: fcmp oge <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_GE_OQ);
}

__mmask32 test_mm512_cmp_ph_mask_gt_oq(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_gt_oq
  // CHECK: fcmp ogt <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_GT_OQ);
}

__mmask32 test_mm512_cmp_ph_mask_true_us(__m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_cmp_ph_mask_true_us
  // CHECK: fcmp true <32 x half> %{{.*}}, %{{.*}}
  return _mm512_cmp_ph_mask(a, b, _CMP_TRUE_US);
}

__mmask32 test_mm512_mask_cmp_ph_mask_eq_oq(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: @test_mm512_mask_cmp_ph_mask_eq_oq
  // CHECK: [[CMP:%.*]] = fcmp oeq <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_EQ_OQ);
}

__mmask32 test_mm512_mask_cmp_ph_mask_lt_os(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_lt_os
  // CHECK: [[CMP:%.*]] = fcmp olt <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_LT_OS);
}

__mmask32 test_mm512_mask_cmp_ph_mask_le_os(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_le_os
  // CHECK: [[CMP:%.*]] = fcmp ole <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_LE_OS);
}

__mmask32 test_mm512_mask_cmp_ph_mask_unord_q(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_unord_q
  // CHECK: [[CMP:%.*]] = fcmp uno <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_UNORD_Q);
}

__mmask32 test_mm512_mask_cmp_ph_mask_neq_uq(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_neq_uq
  // CHECK: [[CMP:%.*]] = fcmp une <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_NEQ_UQ);
}

__mmask32 test_mm512_mask_cmp_ph_mask_nlt_us(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_nlt_us
  // CHECK: [[CMP:%.*]] = fcmp uge <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_NLT_US);
}

__mmask32 test_mm512_mask_cmp_ph_mask_nle_us(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_nle_us
  // CHECK: [[CMP:%.*]] = fcmp ugt <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_NLE_US);
}

__mmask32 test_mm512_mask_cmp_ph_mask_ord_q(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_ord_q
  // CHECK: [[CMP:%.*]] = fcmp ord <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_ORD_Q);
}

__mmask32 test_mm512_mask_cmp_ph_mask_eq_uq(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_eq_uq
  // CHECK: [[CMP:%.*]] = fcmp ueq <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_EQ_UQ);
}

__mmask32 test_mm512_mask_cmp_ph_mask_nge_us(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_nge_us
  // CHECK: [[CMP:%.*]] = fcmp ult <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_NGE_US);
}

__mmask32 test_mm512_mask_cmp_ph_mask_ngt_us(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_ngt_us
  // CHECK: [[CMP:%.*]] = fcmp ule <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_NGT_US);
}

__mmask32 test_mm512_mask_cmp_ph_mask_false_oq(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_false_oq
  // CHECK: [[CMP:%.*]] = fcmp false <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_FALSE_OQ);
}

__mmask32 test_mm512_mask_cmp_ph_mask_neq_oq(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_neq_oq
  // CHECK: [[CMP:%.*]] = fcmp one <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_NEQ_OQ);
}

__mmask32 test_mm512_mask_cmp_ph_mask_ge_os(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_ge_os
  // CHECK: [[CMP:%.*]] = fcmp oge <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_GE_OS);
}

__mmask32 test_mm512_mask_cmp_ph_mask_gt_os(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_gt_os
  // CHECK: [[CMP:%.*]] = fcmp ogt <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_GT_OS);
}

__mmask32 test_mm512_mask_cmp_ph_mask_true_uq(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_true_uq
  // CHECK: [[CMP:%.*]] = fcmp true <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_TRUE_UQ);
}

__mmask32 test_mm512_mask_cmp_ph_mask_eq_os(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_eq_os
  // CHECK: [[CMP:%.*]] = fcmp oeq <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_EQ_OS);
}

__mmask32 test_mm512_mask_cmp_ph_mask_lt_oq(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_lt_oq
  // CHECK: [[CMP:%.*]] = fcmp olt <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_LT_OQ);
}

__mmask32 test_mm512_mask_cmp_ph_mask_le_oq(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_le_oq
  // CHECK: [[CMP:%.*]] = fcmp ole <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_LE_OQ);
}

__mmask32 test_mm512_mask_cmp_ph_mask_unord_s(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_unord_s
  // CHECK: [[CMP:%.*]] = fcmp uno <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_UNORD_S);
}

__mmask32 test_mm512_mask_cmp_ph_mask_neq_us(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_neq_us
  // CHECK: [[CMP:%.*]] = fcmp une <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_NEQ_US);
}

__mmask32 test_mm512_mask_cmp_ph_mask_nlt_uq(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_nlt_uq
  // CHECK: [[CMP:%.*]] = fcmp uge <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_NLT_UQ);
}

__mmask32 test_mm512_mask_cmp_ph_mask_nle_uq(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_nle_uq
  // CHECK: [[CMP:%.*]] = fcmp ugt <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_NLE_UQ);
}

__mmask32 test_mm512_mask_cmp_ph_mask_ord_s(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_ord_s
  // CHECK: [[CMP:%.*]] = fcmp ord <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_ORD_S);
}

__mmask32 test_mm512_mask_cmp_ph_mask_eq_us(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_eq_us
  // CHECK: [[CMP:%.*]] = fcmp ueq <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_EQ_US);
}

__mmask32 test_mm512_mask_cmp_ph_mask_nge_uq(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_nge_uq
  // CHECK: [[CMP:%.*]] = fcmp ult <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_NGE_UQ);
}

__mmask32 test_mm512_mask_cmp_ph_mask_ngt_uq(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_ngt_uq
  // CHECK: [[CMP:%.*]] = fcmp ule <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_NGT_UQ);
}

__mmask32 test_mm512_mask_cmp_ph_mask_false_os(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_false_os
  // CHECK: [[CMP:%.*]] = fcmp false <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_FALSE_OS);
}

__mmask32 test_mm512_mask_cmp_ph_mask_neq_os(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_neq_os
  // CHECK: [[CMP:%.*]] = fcmp one <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_NEQ_OS);
}

__mmask32 test_mm512_mask_cmp_ph_mask_ge_oq(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_ge_oq
  // CHECK: [[CMP:%.*]] = fcmp oge <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_GE_OQ);
}

__mmask32 test_mm512_mask_cmp_ph_mask_gt_oq(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_gt_oq
  // CHECK: [[CMP:%.*]] = fcmp ogt <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_GT_OQ);
}

__mmask32 test_mm512_mask_cmp_ph_mask_true_us(__mmask32 m, __m512h a, __m512h b) {
  // CHECK-LABEL: test_mm512_mask_cmp_ph_mask_true_us
  // CHECK: [[CMP:%.*]] = fcmp true <32 x half> %{{.*}}, %{{.*}}
  // CHECK: and <32 x i1> [[CMP]], {{.*}}
  return _mm512_mask_cmp_ph_mask(m, a, b, _CMP_TRUE_US);
}

__mmask8 test_mm_cmp_round_sh_mask(__m128h __X, __m128h __Y) {
  // CHECK-LABEL: @test_mm_cmp_round_sh_mask
  // CHECK: @llvm.x86.avx512fp16.mask.cmp.sh
  return _mm_cmp_round_sh_mask(__X, __Y, _CMP_NLT_US, _MM_FROUND_NO_EXC);
}

__mmask8 test_mm_mask_cmp_round_sh_mask(__mmask8 __M, __m128h __X, __m128h __Y) {
  // CHECK-LABEL: @test_mm_mask_cmp_round_sh_mask
  // CHECK: @llvm.x86.avx512fp16.mask.cmp.sh
  return _mm_mask_cmp_round_sh_mask(__M, __X, __Y, _CMP_NLT_US, _MM_FROUND_NO_EXC);
}

__mmask8 test_mm_cmp_sh_mask(__m128h __X, __m128h __Y) {
  // CHECK-LABEL: @test_mm_cmp_sh_mask
  // CHECK: @llvm.x86.avx512fp16.mask.cmp.sh
  return _mm_cmp_sh_mask(__X, __Y, _CMP_NLT_US);
}

__mmask8 test_mm_mask_cmp_sh_mask(__mmask8 __M, __m128h __X, __m128h __Y) {
  // CHECK-LABEL: @test_mm_mask_cmp_sh_mask
  // CHECK: @llvm.x86.avx512fp16.mask.cmp.sh
  return _mm_mask_cmp_sh_mask(__M, __X, __Y, _CMP_NLT_US);
}

// VMOVSH

__m128h test_mm_load_sh(void const *A) {
  // CHECK-LABEL: test_mm_load_sh
  // CHECK: load half, half* %{{.*}}, align 1{{$}}
  return _mm_load_sh(A);
}

__m128h test_mm_mask_load_sh(__m128h __A, __mmask8 __U, const void *__W) {
  // CHECK-LABEL: @test_mm_mask_load_sh
  // CHECK: %{{.*}} = call <8 x half> @llvm.masked.load.v8f16.p0v8f16(<8 x half>* %{{.*}}, i32 1, <8 x i1> %{{.*}}, <8 x half> %{{.*}})
  return _mm_mask_load_sh(__A, __U, __W);
}

__m128h test_mm_maskz_load_sh(__mmask8 __U, const void *__W) {
  // CHECK-LABEL: @test_mm_maskz_load_sh
  // CHECK: %{{.*}} = call <8 x half> @llvm.masked.load.v8f16.p0v8f16(<8 x half>* %{{.*}}, i32 1, <8 x i1> %{{.*}}, <8 x half> %{{.*}})
  return _mm_maskz_load_sh(__U, __W);
}

__m512h test_mm512_load_ph(void *p) {
  // CHECK-LABEL: @test_mm512_load_ph
  // CHECK: load <32 x half>, <32 x half>* %{{.*}}, align 64
  return _mm512_load_ph(p);
}

__m256h test_mm256_load_ph(void *p) {
  // CHECK-LABEL: @test_mm256_load_ph
  // CHECK: load <16 x half>, <16 x half>* %{{.*}}, align 32
  return _mm256_load_ph(p);
}

__m128h test_mm_load_ph(void *p) {
  // CHECK-LABEL: @test_mm_load_ph
  // CHECK: load <8 x half>, <8 x half>* %{{.*}}, align 16
  return _mm_load_ph(p);
}

__m512h test_mm512_loadu_ph(void *p) {
  // CHECK-LABEL: @test_mm512_loadu_ph
  // CHECK: load <32 x half>, <32 x half>* {{.*}}, align 1{{$}}
  return _mm512_loadu_ph(p);
}

__m256h test_mm256_loadu_ph(void *p) {
  // CHECK-LABEL: @test_mm256_loadu_ph
  // CHECK: load <16 x half>, <16 x half>* {{.*}}, align 1{{$}}
  return _mm256_loadu_ph(p);
}

__m128h test_mm_loadu_ph(void *p) {
  // CHECK-LABEL: @test_mm_loadu_ph
  // CHECK: load <8 x half>, <8 x half>* {{.*}}, align 1{{$}}
  return _mm_loadu_ph(p);
}

void test_mm_store_sh(void *A, __m128h B) {
  // CHECK-LABEL: test_mm_store_sh
  // CHECK: extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: store half %{{.*}}, half* %{{.*}}, align 1{{$}}
  _mm_store_sh(A, B);
}

void test_mm_mask_store_sh(void *__P, __mmask8 __U, __m128h __A) {
  // CHECK-LABEL: @test_mm_mask_store_sh
  // CHECK: call void @llvm.masked.store.v8f16.p0v8f16(<8 x half> %{{.*}}, <8 x half>* %{{.*}}, i32 1, <8 x i1> %{{.*}})
  _mm_mask_store_sh(__P, __U, __A);
}

void test_mm512_store_ph(void *p, __m512h a) {
  // CHECK-LABEL: @test_mm512_store_ph
  // CHECK: store <32 x half> %{{.*}}, <32 x half>* %{{.*}}, align 64
  _mm512_store_ph(p, a);
}

void test_mm256_store_ph(void *p, __m256h a) {
  // CHECK-LABEL: @test_mm256_store_ph
  // CHECK: store <16 x half> %{{.*}}, <16 x half>* %{{.*}}, align 32
  _mm256_store_ph(p, a);
}

void test_mm_store_ph(void *p, __m128h a) {
  // CHECK-LABEL: @test_mm_store_ph
  // CHECK: store <8 x half> %{{.*}}, <8 x half>* %{{.*}}, align 16
  _mm_store_ph(p, a);
}

void test_mm512_storeu_ph(void *p, __m512h a) {
  // CHECK-LABEL: @test_mm512_storeu_ph
  // CHECK: store <32 x half> %{{.*}}, <32 x half>* %{{.*}}, align 1{{$}}
  // CHECK-NEXT: ret void
  _mm512_storeu_ph(p, a);
}

void test_mm256_storeu_ph(void *p, __m256h a) {
  // CHECK-LABEL: @test_mm256_storeu_ph
  // CHECK: store <16 x half> %{{.*}}, <16 x half>* %{{.*}}, align 1{{$}}
  // CHECK-NEXT: ret void
  _mm256_storeu_ph(p, a);
}

void test_mm_storeu_ph(void *p, __m128h a) {
  // CHECK-LABEL: @test_mm_storeu_ph
  // CHECK: store <8 x half> %{{.*}}, <8 x half>* %{{.*}}, align 1{{$}}
  // CHECK-NEXT: ret void
  _mm_storeu_ph(p, a);
}

__m128h test_mm_move_sh(__m128h A, __m128h B) {
  // CHECK-LABEL: test_mm_move_sh
  // CHECK: extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: insertelement <8 x half> %{{.*}}, half %{{.*}}, i32 0
  return _mm_move_sh(A, B);
}

__m128h test_mm_mask_move_sh(__m128h __W, __mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_mask_move_sh
  // CHECK: [[EXT:%.*]] = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: insertelement <8 x half> %{{.*}}, half [[EXT]], i32 0
  // CHECK: [[A:%.*]] = extractelement <8 x half> [[VEC:%.*]], i64 0
  // CHECK-NEXT: [[B:%.*]] = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: bitcast i8 %{{.*}} to <8 x i1>
  // CHECK-NEXT: extractelement <8 x i1> %{{.*}}, i64 0
  // CHECK-NEXT: [[SEL:%.*]] = select i1 %{{.*}}, half [[A]], half [[B]]
  // CHECK-NEXT: insertelement <8 x half> [[VEC]], half [[SEL]], i64 0
  return _mm_mask_move_sh(__W, __U, __A, __B);
}

__m128h test_mm_maskz_move_sh(__mmask8 __U, __m128h __A, __m128h __B) {
  // CHECK-LABEL: @test_mm_maskz_move_sh
  // CHECK: [[EXT:%.*]] = extractelement <8 x half> %{{.*}}, i32 0
  // CHECK: insertelement <8 x half> %{{.*}}, half [[EXT]], i32 0
  // CHECK: [[A:%.*]] = extractelement <8 x half> [[VEC:%.*]], i64 0
  // CHECK-NEXT: [[B:%.*]] = extractelement <8 x half> %{{.*}}, i64 0
  // CHECK-NEXT: bitcast i8 %{{.*}} to <8 x i1>
  // CHECK-NEXT: extractelement <8 x i1> %{{.*}}, i64 0
  // CHECK-NEXT: [[SEL:%.*]] = select i1 %{{.*}}, half [[A]], half [[B]]
  // CHECK-NEXT: insertelement <8 x half> [[VEC]], half [[SEL]], i64 0
  return _mm_maskz_move_sh(__U, __A, __B);
}

short test_mm_cvtsi128_si16(__m128i A) {
  // CHECK-LABEL: test_mm_cvtsi128_si16
  // CHECK: extractelement <8 x i16> %{{.*}}, i32 0
  return _mm_cvtsi128_si16(A);
}

__m128i test_mm_cvtsi16_si128(short A) {
  // CHECK-LABEL: test_mm_cvtsi16_si128
  // CHECK: insertelement <8 x i16> undef, i16 %{{.*}}, i32 0
  // CHECK: insertelement <8 x i16> %{{.*}}, i16 0, i32 1
  // CHECK: insertelement <8 x i16> %{{.*}}, i16 0, i32 2
  // CHECK: insertelement <8 x i16> %{{.*}}, i16 0, i32 3
  return _mm_cvtsi16_si128(A);
}

_Float16 test_mm512_reduce_add_ph(__m512h __W) {
  // CHECK-LABEL: @test_mm512_reduce_add_ph
  // CHECK: call reassoc half @llvm.vector.reduce.fadd.v32f16(half 0xH8000, <32 x half> %{{.*}})
  return _mm512_reduce_add_ph(__W);
}

_Float16 test_mm512_reduce_mul_ph(__m512h __W) {
  // CHECK-LABEL: @test_mm512_reduce_mul_ph
  // CHECK: call reassoc half @llvm.vector.reduce.fmul.v32f16(half 0xH3C00, <32 x half> %{{.*}})
  return _mm512_reduce_mul_ph(__W);
}

_Float16 test_mm512_reduce_max_ph(__m512h __W) {
  // CHECK-LABEL: @test_mm512_reduce_max_ph
  // CHECK: call nnan half @llvm.vector.reduce.fmax.v32f16(<32 x half> %{{.*}})
  return _mm512_reduce_max_ph(__W);
}

_Float16 test_mm512_reduce_min_ph(__m512h __W) {
  // CHECK-LABEL: @test_mm512_reduce_min_ph
  // CHECK: call nnan half @llvm.vector.reduce.fmin.v32f16(<32 x half> %{{.*}})
  return _mm512_reduce_min_ph(__W);
}

__m512h test_mm512_mask_blend_ph(__mmask32 __U, __m512h __A, __m512h __W) {
  // CHECK-LABEL: @test_mm512_mask_blend_ph
  // CHECK:  %{{.*}} = bitcast i32 %{{.*}} to <32 x i1>
  // CHECK:  %{{.*}} = select <32 x i1> %{{.*}}, <32 x half> %{{.*}}, <32 x half> %{{.*}}
  return _mm512_mask_blend_ph(__U, __A, __W);
}

__m512h test_mm512_permutex2var_ph(__m512h __A, __m512i __I, __m512h __B) {
  // CHECK-LABEL: @test_mm512_permutex2var_ph
  // CHECK:  %{{.*}} = bitcast <32 x half> %{{.*}} to <32 x i16>
  // CHECK:  %{{.*}} = bitcast <8 x i64> %{{.*}} to <32 x i16>
  // CHECK:  %{{.*}} = bitcast <32 x half> %{{.*}} to <32 x i16>
  // CHECK:  %{{.*}} = call <32 x i16> @llvm.x86.avx512.vpermi2var.hi.512(<32 x i16> %{{.*}}, <32 x i16> %{{.*}}, <32 x i16> %{{.*}})
  // CHECK:  %{{.*}} = bitcast <32 x i16> %{{.*}} to <32 x half>
  return _mm512_permutex2var_ph(__A, __I, __B);
}

__m512h test_mm512_permutexvar_epi16(__m512i __A, __m512h __B) {
  // CHECK-LABEL: @test_mm512_permutexvar_epi16
  // CHECK:  %{{.*}} = bitcast <32 x half> %{{.*}} to <32 x i16>
  // CHECK:  %{{.*}} = bitcast <8 x i64> %{{.*}} to <32 x i16>
  // CHECK:  %{{.*}} = call <32 x i16> @llvm.x86.avx512.permvar.hi.512(<32 x i16> %{{.*}}, <32 x i16> %{{.*}})
  // CHECK:  %{{.*}} = bitcast <32 x i16> %{{.*}} to <32 x half>
  return _mm512_permutexvar_ph(__A, __B);
}
