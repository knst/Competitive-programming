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
}

void dfs(const vector<vector<int>>& mask, vector<bool>& used, size_t next, vector<size_t>& indexes) {
    if (used[next])
        return;
    used[next] = true;
    indexes.push_back(next);
    for (size_t i = 0; i < used.size(); ++i) {
        if (mask[next][i])
            dfs(mask, used, i, indexes);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) {
        cin >> i;
        --i;
    }
    vector<vector<int>> mask(n, vector<int>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (size_t j = 0; j < n; ++j) {
            mask[i][j] = (s[j] == '1');
        }
    }

    vector<bool> used(n, false);
    for (size_t i = 0; i < n; ++i) {
        vector<size_t> indexes;
        dfs(mask, used, i, indexes);
        if (indexes.empty())
            continue;
        sort(indexes.begin(), indexes.end());
        vector<int> New;
        for (auto i : indexes)
            New.push_back(v[i]);
        sort(New.begin(), New.end());
        for (size_t i = 0; i < indexes.size(); ++i) {
            v[indexes[i]] = New[i];
        }
    }
    for (auto i : v)
        cout << i+1 << ' ';

    return 0;
}

