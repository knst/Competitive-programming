/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <iomanip>
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

inline double distance(const pair<int, int>& a, const pair<int, int>& b) {
    int x = a.first - b.first;
    int y = a.second - b.second;
    return sqrt(x * x + y * y);
}

double find(const vector<vector<double>>& distances, uint32_t mask, vector<double>& dp) {
    if (dp[mask] >= 0) return dp[mask];
    size_t n = distances.size();

    double minimal = numeric_limits<double>::max();
    for (size_t i = 0; i < n; ++i) {
        if (mask & (1u << i)) continue;
        for (size_t j = i + 1; j < n; ++j) {
            if (mask & (1u << j)) continue;
            minimal = min(minimal, distances[i][j] + find(distances, mask | (1u << i) | (1u << j), dp));
        }
    }
    dp[mask] = minimal;
    return minimal;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 0;
    while(++t) {
        int n;
        cin >> n;
        if (n == 0) break;
        n *= 2;

        vector<pair<int, int>> v(n);
        string name;
        for (auto& i : v) {
            cin >> name >> i.first >> i.second;
        }
        vector<double> dp;
        for (uint32_t i = 0; i + 1 < (1u << n); ++i) {
            dp.push_back(-1);
        }
        dp.push_back(0);
        vector<vector<double>> distances(n, vector<double>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                distances[i][j] = distance(v[i], v[j]);
            }
        }

        double minimal = find(distances, 0, dp);
        cout << "Case " << t << ": " << fixed << setprecision(2) << minimal << endl;
    }
}
