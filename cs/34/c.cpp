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

vector<int> dec(int x)
{
    vector<int> m(32);
    for (int i = 0; i < 30; ++i) {
        if (x & (1 << i)) m[i]++;
    }
    return m;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) cin >> i;


    unsigned int a = 0;
    for (auto& i : v) a = a | i;
    if (a == 0) {
        cout << 1 << endl;
        return 0;
    }

    int best = n;
    unsigned int current = 0;
    int count = 0;
    int start = 0;
    vector<int> mask(30);
    for (int i = 0; i < n; ) {
        while (i < n && current != a) {
            auto m = dec(v[i]);
            current = current | v[i];
            for (int j = 0; j < 30; ++j) {
                mask[j] += m[j];
            }
            ++i;
            ++count;
        }
        while (current == a) {
            if (count < best) best = count;
            auto m = dec(v[start]);
            for (int j = 0; j < 30; ++j) {
                mask[j] -= m[j];
                if (mask[j] == 0) {
                    current = current & ~(1u << j);
                }
            }
            ++start;
            --count;
        }
    }
    cout << best << endl;
}
