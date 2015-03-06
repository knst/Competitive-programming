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

int main() {
    std::ios_base::sync_with_stdio(false);


    int n;
    cin >> n;
    vector<vector<char>> v(n+2, vector<char>(n+2));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            v[i+1][j+1] = s[j];
        }
    }

    bool ok =true;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int count = 0;
            if (v[i][j+1] == 'o')
                ++count;
            if (v[i][j-1] == 'o')
                ++count;
            if (v[i-1][j] == 'o')
                ++count;
            if (v[i+1][j] == 'o')
                ++count;
            if (count % 2 != 0)
                ok = false;
        }

    }
    if (ok) {
        cout << "YES" << endl;
    } else
        cout << "NO" << endl;


    return 0;
}

