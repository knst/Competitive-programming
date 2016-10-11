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
    size_t operator()(const auto& p) const { return hash<T1>()(p.first) ^ hash<T2>()(p.second); }
};}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1)) * 4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

auto gcd(auto A, auto B) { return B == 0 ? A : gcd(B, A % B); }

uint64_t powMod(uint64_t G, uint64_t pow, uint64_t M) {
    if (pow == 0) return 1;
    return pow % 2 == 0 ? powMod(G * G % M, pow / 2, M) : powMod(G, pow - 1, M) * G % M;
}

uint64_t inverse(uint64_t X, uint64_t M) { return X == 1 ? 1 : powMod(X, M - 2, M); }

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    size_t m;
    cin >> n >> m;
    size_t k;
    cin >> k;
    vector<string> v(n);
    for (auto& i : v)
        cin >> i;
    vector<vector<bool>> mask(n, vector<bool>(m));
    vector<vector<pair<size_t, size_t>>> lakes;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (mask[i][j])
                continue;
            if (v[i][j] != '.')
                continue;
            vector<pair<size_t, size_t>> lake;
            queue<pair<size_t, size_t>> q;
            q.push({i,j});
            bool notLake = false;
            while (!q.empty()) {
                auto p = q.front();
                q.pop();
                size_t x = p.first;
                size_t y = p.second;
                if (p.first >= n)
                    continue;
                if (p.second >= m)
                    continue;
                if (mask[p.first][p.second])
                    continue;
                if (v[p.first][p.second] != '.')
                    continue;
                if (x == 0 || y == 0 || x + 1 == n || y + 1 == m)
                    notLake = true;
                lake.push_back({p.first, p.second});
                mask[p.first][p.second] = true;
                for (size_t k = 0; k < 4; ++k) {
                    q.push({p.first + dx4[k], p.second + dy4[k]});
                }
            }
            if (!notLake) {
                lakes.push_back(lake);
            }

        }
    }
    for (size_t i = 0; i < lakes.size(); ++i) {
        for (size_t j = 1; j < lakes.size(); ++j) {
            if (lakes[j].size() < lakes[j - 1].size())
                swap(lakes[j], lakes[j-1]);
        }
    }
//    for (auto i : lakes) {
 //       for (auto j : i)
  //          cout << j.first << ' ' << j.second << endl;
   //     cout << endl;
  //  }
    size_t count = 0;
    for (size_t i = 0; i < lakes.size() - k; ++i) {
        for (auto p : lakes[i]) {
            ++count;
            v[p.first][p.second] = '*';
        }
    }
    cout << count << endl;
    for (auto i : v)
        cout << i << endl;

}
