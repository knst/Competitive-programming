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

const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, -1, 0, 1};

const int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct Checker {
    int n;
    int m;
    vector<string> v;
    vector<vector<bool>> used;
    void Read() {
        cin >> n >> m;
        v.resize(n);
        for (auto& i : v)
            cin >> i;
    }
    bool check(int a, int b, bool ch) {
        if (ch && v[a][b] != '1')
            return false;
        int count = 0;
        for (int i = 0; i < 4; ++i) {
            int x = a + dx4[i];
            int y = b + dy4[i];
            if (x >= 0 && y >= 0 && x < n && y < m)
                if (v[x][y] == '1')
                    ++count;
        }
        if (count == 2)
            return true;
        return false;

    }
    vector<vector<bool>> used2;
    void Solve() {
        bool len4 = false;
        for (int i = 0; i < n-1; ++i) {
            for (int j = 0; j < m-1; ++j) {
                if (
                    v[i][j] == '1' &&
                    v[i+1][j] == '1' &&
                    v[i][j+1] == '1' &&
                    v[i+1][j+1] == '1'
                )
                    len4 = true;

            }
        }

        used = vector<vector<bool>>(n, vector<bool>(m, false));
        used2 = vector<vector<bool>>(n, vector<bool>(m, true));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] == '1')
                    used[i][j] = true;
            }
        }

        int maximal = 0;
        if (len4)
            maximal = 4;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!used[i][j]) {
                    eds.clear();
                    bool ok = dfs(i, j);
                    for (auto p : eds) {
                        int x = p.first;
                        int y = p.second;
                        int count = 0;
                        for (int i = 0; i < 4; ++i) {
                            int a = x + dx4[i];
                            int b = y + dy4[i];
                            if (a >= 0 && b >= 0 && a < n && b < m) {
                                if (v[a][b] == '1' && eds.find({a,b}) != eds.end())
                                    ++count;
                            }
                        }
                        if (count != 2)
                            ok = false;
                    }
                    if (ok && eds.size() > maximal) {
                        for (auto p : eds) {
                            used2[p.first][p.second] = false;
                        }
                        dfs2(eds.begin()->first, eds.begin()->second);
                        for (auto p : eds) {
                            if (used2[p.first][p.second] == false) {
                                ok = false;
                                used2[p.first][p.second] = true;
                            }
                        }
                    }
                    if (ok)
                        maximal = max(maximal, static_cast<int>(eds.size()));
                }
            }
        }
        cout << maximal << endl;
    }
    set<pair<int,int>> eds;
    bool dfs(int x, int y) {
        used[x][y] = true;
        if (x == 0 || y == 0 || x == n-1 || y == m-1)
            return false;
        for (int i = 0; i < 8; ++i) {
            int a = x + dx8[i];
            int b = y + dy8[i];
            if (v[a][b] == '1')
                eds.insert({a,b});

            if (v[a][b] == '0' && used[a][b] == false) {
                bool ok = dfs(a, b);
                if (!ok)
                    return false;
            }
        }
        return true;
    }
    void dfs2(int x, int y) {
        if (used2[x][y])
            return;
        used2[x][y] = true;
        for (int i = 0; i < 4; ++i) {
            int a = x + dx4[i];
            int b = y + dy4[i];
            if (a < 0 || b < 0 || a>=n || b >= m)
                continue;
            dfs2(a, b);
        }
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);

    Checker c;
    c.Read();
    c.Solve();

    return 0;
}
