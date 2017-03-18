/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/
#include <bits/stdc++.h>
#include  <mmintrin.h> //MMX
#include  <xmmintrin.h> //SSE
#include  <emmintrin.h> //SSE2
#include  <pmmintrin.h> //SSE3
#include  <tmmintrin.h> //SSSE3
#include  <smmintrin.h> //SSSE4.1
#include  <nmmintrin.h> //SSSE4.2
using namespace std;

static inline __m128i z_mm_mullo_epu32(const __m128i &a, const __m128i &b)
{
    __m128i p1 = _mm_mul_epu32(a,b);
    __m128i p2 = _mm_mul_epu32(_mm_srli_si128(a,4), _mm_srli_si128(b,4));
    return _mm_unpacklo_epi32(_mm_shuffle_epi32(p1, _MM_SHUFFLE (0,0,2,0)), _mm_shuffle_epi32(p2, _MM_SHUFFLE (0,0,2,0)));
}

static inline __m128i _mm_cmpge_epi32 (const __m128i& x, const __m128i& y)
{
	return _mm_or_si128(_mm_cmpgt_epi32(x, y), _mm_cmpeq_epi32(x, y));
}

#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int q;
    cin >> n >> q;
    vector<uint32_t> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    for(int a0 = 0; a0 < q; a0++) {
        size_t left;
        size_t right;
        uint32_t x;
        uint32_t y;
        cin >> left >> right >> x >> y;
        ++right;
        y = y % x;
        int count = 0;
        if (left + 100 > right) {
            for (size_t i = left; i < right; ++i) {
                if (a[i] < x) {
                    if (a[i] == y) {
                        ++count;
                    }
                } else if (a[i] % x == y) {
                    ++count;
                }
            }
        } else {
            size_t Left = (left + 3) / 4 * 4;
            size_t Right = right / 4 * 4;
            uint32_t xb = 65536 / x;

            alignas(16) uint32_t* p = &a[0];
            alignas(16) uint32_t xbp[] = {xb, xb, xb, xb};
            alignas(16) uint32_t xp[] = {x, x, x, x};
            alignas(16) uint32_t result[] = {0, 0, 0, 0};
            alignas(16) uint32_t yp[] = {y, y, y, y};
            alignas(16) uint32_t yp2[] = {y + x, y + x, y + x, y + x};
            alignas(16) uint32_t yp3[] = {y + x + x, y + x + x, y + x + x, y + x + x};
            __m128i v_xb            = _mm_load_si128(reinterpret_cast<__m128i *>(xbp));
            __m128i summary_result  = _mm_load_si128(reinterpret_cast<__m128i *>(result));
            __m128i v_x             = _mm_load_si128(reinterpret_cast<__m128i *>(xp));
            __m128i v_y             = _mm_load_si128(reinterpret_cast<__m128i *>(yp));
            __m128i v_y2            = _mm_load_si128(reinterpret_cast<__m128i *>(yp2));
            __m128i v_y3            = _mm_load_si128(reinterpret_cast<__m128i *>(yp3));
            for (size_t i = Left; i < Right; i += 4) {
                __m128i v_a = _mm_load_si128(reinterpret_cast<__m128i *>(p + i));

                __m128i v_result = z_mm_mullo_epu32(v_x,_mm_srli_epi32(z_mm_mullo_epu32(v_a, v_xb), 16));
                v_result = _mm_sub_epi32(v_a, v_result);

                summary_result = _mm_add_epi32(summary_result,
                        _mm_cmpeq_epi32(v_result, v_y));
                summary_result = _mm_add_epi32(summary_result,
                        _mm_cmpeq_epi32(v_result, v_y3));
                summary_result = _mm_add_epi32(summary_result,
                        _mm_cmpeq_epi32(v_result, v_y2));
            }
            _mm_storeu_si128(reinterpret_cast<__m128i *>(result), summary_result);
            count -= result[0];
            count -= result[1];
            count -= result[2];
            count -= result[3];
            for (size_t i = left; i < Left; ++i) {
                if (a[i] % x == y)
                    ++count;
            }
            for (size_t i = Right; i < right; ++i) {
                if (a[i] % x == y)
                    ++count;
            }
        }
        cout << count << '\n';
    }
    return 0;
}
#pragma GCC pop_options
