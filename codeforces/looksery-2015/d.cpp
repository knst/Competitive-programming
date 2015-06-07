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

namespace std {
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int solve(int n, int m, const vector<vector<bool>>& v) {
    set<pair<int,int>> s;
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < m; ++j) {
            int s1 = 0;
            s1 += v[i][j];
            s1 += v[i-1][j];
            s1 += v[i][j-1];
            s1 += v[i-1][j-1];
            if (s1 == 1 || s1 == 3)
                s.insert({i-1, j-1});
            if (s1 == 2 && v[i-1][j-1] == v[i][j])
                s.insert({i-1, j-1});
        }
    for (int i = 1; i < n; ++i)
        if (v[i][m - 1] != v[i-1][m-1])
            s.insert({i-1, m - 1});
    for (int j = 1; j < m; ++j)
        if (v[n-1][j] != v[n-1][j - 1])
            s.insert({n-1, j-1});
    s.insert({n-1, m-1});
//    for (auto i : s)
//        cout << i.first << ' ' << i.second << endl;
    return s.size();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto& i : v)
        cin >> i;
    vector<vector<bool>> M(n, vector<bool>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (v[i][j] == 'B')
                M[i][j] = true;
    int v1 = solve(n, m, M);
/*    for (auto& i : M)
        for (auto& j : i)
            j = !j;
    int v2 = solve(n, m, M); */
    cout << v1 << endl;
//    cout << v1 + v2 << endl;

    return 0;
}
