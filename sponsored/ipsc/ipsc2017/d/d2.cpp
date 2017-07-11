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
#include <unordered_set>
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

    unordered_set<int> nob;
    vector<int> digits;
    for (int i = 0; i < 10; ++i) {
        digits.push_back(i);
    }
    do {
        for (size_t i = 0; i <= digits.size(); ++i) {
            int64_t value = 0;
            for (size_t j = 0; j < i; ++j) {
                value = value * 10 + digits[j];
            }
            if (value == 0) continue;
            if (value > 2'000'000'000) continue;
            nob.insert(value);
        }
    } while (next_permutation(digits.begin(), digits.end()));
    vector<int64_t> nob_v;
    for (auto i : nob) {
        nob_v.push_back(i);
    }
    random_shuffle(nob_v.begin(), nob_v.end());
    int t;
    cin >> t;

    while (t--) {
        int64_t n;
        cin >> n;
        bool ok = false;
        if (nob.find(n) != nob.end()) {
            cout << "1 " << n << endl;
            ok = true;
        } else {
            for (auto i : nob) {
                if (i > n) continue;
                if (nob.find(n - i) != nob.end()) {
                    cout << "2 " << i << ' ' << n - i << endl;
                    ok = true;
                    break;
                }
            }
        }
        if (!ok) cout << "fail " << n << endl;
/*        for (size_t i = 0; !ok && i < nob_v.size(); ++i) {
            int a = nob_v[i];
            if (a > n) continue;
            for (size_t j = i; !ok && j < nob_v.size(); ++j) {
                int b = nob_v[j];
                if (a + b > n) continue;
                if (a + b == n) throw "asdf???";
                if (nob.find(n - b - a) != nob.end()) {
                    cout << "3 " << a << ' ' << b << ' ' << n - b - a << endl;
                    ok = true;
                }
            }
        }
        */
    }
}
