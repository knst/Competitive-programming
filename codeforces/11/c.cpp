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

using namespace std;
//test speed
/*
namespace std {
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}; */
namespace std {
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
};

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int main() {
    std::ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        int m;
        cin >> n >> m;
        vector<vector<int>> v(n+2, vector<int>(m+2, 0));
        for (int i = 1;i <= n; ++i) {
            string s;
            cin >> s;
            for (int j = 1;j <= m; ++j) {
                if (s[j-1])
                    v[i][j] = 1;
            }
        }
        vector<vector<vector<int>>> dynContinued(8, vector<vector<int>>(n + 2, vector<int>(m + 2,0)));
        vector<vector<vector<int>>> dynFinished(8, vector<vector<int>>(n + 2, vector<int>(m + 2,0)));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int direction = 0; direction < 8; ++direction) {
                    dynFinished[direction][i][j] = dynFinished[direction][i+dx][i+dy]
            }
        }


    }

    return 0;
}
