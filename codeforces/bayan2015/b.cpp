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

int n;
int m;

int main() {
    std::ios_base::sync_with_stdio(false);

    cin >> n >> m;
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;

    bool ok = true;
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            vector<vector<bool>> used(n, vector<bool>(m, false));
            stack<pair<int,int>> s;
            s.push({x,y});
            while (!s.empty()) {
                pair<int,int> p = s.top();
                s.pop();
                if (p.first < 0 || p.second < 0 || p.first == n || p.second ==m)
                    continue;

                if (used[p.first][p.second])
                    continue;
                used[p.first][p.second] = true;
                if (s1[p.first] == '<')
                    s.push({p.first, p.second-1});
                else
                    s.push({p.first, p.second+1});
                if (s2[p.second] == 'v')
                    s.push({p.first+1, p.second});
                else
                    s.push({p.first-1, p.second});
            }
            for (auto i : used) {
                for (auto j : i) {
                    if (!j) {
                        ok = false;
                    }
                }
            }

        }
    }
    if (ok)
        cout << "YES";
    else
        cout << "NO";
    cout << endl;



    return 0;
}

