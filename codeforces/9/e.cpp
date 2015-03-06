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
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
};

void dfs(int index, int color, const vector<vector<int>>& e, vector<int>& used) {
    if (used[index] != -1)
        return;
    used[index] = color;
    for (const auto& edge : e[index])
        dfs(edge, color, e, used);
}

void Wrong() {
    cout << "NO" << endl;
    exit(0);
}

bool testE(const vector<vector<int>>& e) {
    for (auto i : e)
        if (i.size() != 2)
            return false;
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int m;
    cin >> n >> m;
    vector<int> w(n, 0);
    vector<vector<int>> e(n);
    for (int i = 0; i < m; ++i) {
        int x;
        int y;
        cin >> x >> y;
        --x;
        --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    vector<int> used(n, -1);
    for (int i = 0; i < n; ++i)
        dfs(i, i, e, used);

    bool loop = false;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < e[i].size(); ++j)
            if (e[i][j] == i)
                loop = true;
    bool cycle = true;
    for (auto i : used)
        if (i != 0)
            cycle = false;
    if (!testE(e))
            cycle = false;
    if (n == m && cycle) {
        cout << "YES 0" << endl;
        return 0;
    }
    if (n < m)
        Wrong();
    if (n != 1 && loop)
        Wrong();

    for (auto i : e)
        if (i.size() > 2)
            Wrong();

    if (n == 1) {
        cout << "YES" << endl;
        cout << n -m << endl;
        cout << "1 1" << endl;
        return 0;
    }
    vector<pair<int,int>> result;

    bool allOk = true;
    for (int iter = 0; iter < n - m; ++iter) {
        int i = 0;
        while (e[i].size() == 2)
            ++i;
        int j  =i + 1;
        if (iter == n-m - 1) {
            while (j < n && e[j].size() == 2)
                ++j;
        } else
            while (j < n && (e[j].size() == 2 || used[i] == used[j]))
                ++j;
        if (j >= n) {
            allOk = false;
            break;
        }
        e[i].push_back(j);
        e[j].push_back(i);
        result.push_back({i,j});
        int colorJ = used[j];
        for (auto& I : used)
            if (I == colorJ)
                I = used[i];
    }

    if (allOk) {
        cout << "YES " << n - m << endl;
        for (auto I : result)
            cout << I.first + 1 << ' ' << I.second + 1 << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}

