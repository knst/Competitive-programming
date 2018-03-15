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

    int n;
    cin >> n;
    vector<__int128> v(n);
    for (auto& i : v) {
        int x;
        cin >> x;
        i = x;
    }

    map<__int128, vector<int>> positions;
    for (int i = 0; i < n; ++i) {
        positions[v[i]].push_back(i);
    }

    __int128 sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += i * v[i];
        sum -= (n - i - 1) * v[i];
    }
    for (auto i : positions) {
        __int128 k = i.first;
        if (positions.find(k - 1) != positions.end()) {
            const vector<int>& lv = i.second;
            const vector<int>& rv = positions[k - 1];
            /*
            cout << "lv: ";
            for (auto i : lv)
                cout << i << ' ';
            cout << endl;
            cout << "rv: ";
            for (auto i :rv)
                cout << i << ' ';
            cout << endl;
            */

            __int128 r = 0;
            for (size_t j = 0; j < lv.size(); ++j) {
                __int128 rs = rv.size();
                while (r < rs && rv[r] < lv[j])
                    ++r;
//                cerr << " > " << sum << ' ' << r << ' ' << rs << endl;
                sum -= r - (rs - r);
            }

        }
    }
    int64_t result1 = sum / 100;
    int64_t result2 = sum % 100;
    if (result1) cout << result1;
    cout << result2 << endl;
}
