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
    vector<pair<int,int>> u(n);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        u[i] = {x, i};
    }

    sort(u.begin(), u.end());
    vector<int> v(n);
    map<int, int> m;
    for (int i = 0; i < n; ++i) {
        v[i] = u[i].second;
        m[v[i]] = i;
    }
    vector<vector<int>> result;
    for (int i = 0; i < n; ++i) {
        if (v[i] == -1) continue;
        int next = m[i];
        v[next] = -1;
        vector<int> values = {next};
        while (next != i) {
            next = m[next];
            v[next] = -1;
            values.push_back(next);
//            cout << next << endl;
        }
        result.push_back(values);
    }
    cout << result.size() << endl;
    for (const auto& values : result) {
        cout << values.size();
        for (auto i : values) {
            cout << ' ' << i + 1;
        }
        cout << '\n';
    }

}
