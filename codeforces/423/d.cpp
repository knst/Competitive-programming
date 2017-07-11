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
    int k;
    cin >> n >> k;
    int l = n - k;
    if (l == 1) {
        cout << 2 << endl;
        for (int i = 0; i < k; ++i) {
            cout << i + 1 << ' ' << n << '\n';
        }
/*    } else if (l == 2) {
        cout << "1 2\n";
        int t = 1;
        for (int i = 0; i < k; ++i) {
            cout << i + 3 << ' ' << t << '\n';
            if (t == 1) t = 2;
            else t = 1;
        }
        */
    } else {
        vector<vector<int>> v(k);
        int j = 0;
        for (int i = 2; i <= n; ++i) {
            v[j].push_back(i);
            ++j;
            if (j >= v.size()) j = 0;
        }
        if (v.size() == 1) {
            cout << v[0].size() << endl;
        } else {
            cout << v[0].size() + v[1].size() << endl;
        }
        for (int i = 0; i < v.size(); ++i) {
            cout << "1 " << v[i][0] << '\n';
            for (int j = 1; j < v[i].size(); ++j) {
                cout << v[i][j - 1] << ' ' << v[i][j] << '\n';
            }
        }
    }

}
