/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

#include <cmath>

using namespace std;

namespace std { template <class T1, class T2> struct hash<pair<T1, T2>> {
    size_t operator()(const pair<T1, T2>& p) const { return hash<T1>()(p.first) ^ hash<T2>()(p.second); }
};}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1)) * 4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

template<class T> T gcd(T A, T B) { return B == 0 ? A : gcd(B, A % B); }

uint64_t powMod(uint64_t G, uint64_t pow, uint64_t M) {
    if (pow == 0) return 1;
    return pow % 2 == 0 ? powMod(G * G % M, pow / 2, M) : powMod(G, pow - 1, M) * G % M;
}

uint64_t inverse(uint64_t X, uint64_t M) { return X == 1 ? 1 : powMod(X, M - 2, M); }

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    size_t k;
    int x;
    cin >> n >> k >> x;
    size_t M = 1024;
    vector<int> count(M);
    vector<int> count2(M);
    for (size_t i = 0; i < n; ++i) {
        int J;
        cin >> J;
        count[J]++;
    }

    for (size_t i = 0; i < k; ++i) {
        int shift = 0;
        for (size_t j = 0; j < M; ++j) {
            int t = count[j];
            if (t & 1) {
                shift = !shift;
            }
            int t2 = (t + shift)/ 2 ;
            int t_stay = t - t2;
            count2[j] += t_stay;
            count2[j ^ x] += t2;
        }
        swap(count, count2);
        fill(count2.begin(), count2.end(), 0);
    }
    for (size_t i = M - 1; ; --i) {
        if (count[i] != 0) {
            cout << i << ' ';
            break;
        }
    }
    for (size_t i = 0; ; ++i) {
        if (count[i] != 0) {
            cout << i << endl;
            break;
        }
    }
}
