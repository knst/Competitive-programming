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

    int n;
    int m;
inline int Diff(const vector<vector<string>>& vs, int i, int j) {
    if (i == -1 || j == -1)
        return n * m;
    int count = 0;
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < m; ++b) {
            if (vs[i][a][b] != vs[j][a][b])
                ++count;
        }
    }
//    cout << '?' << i << ' ' << j << ' ' << count << endl;
    return count;
}
int main() {
    std::ios_base::sync_with_stdio(false);

    cin >> n >> m;
    int k;
    int w;
    cin >> k >> w;
    vector<vector<string>> vs(k);
    for (int i = 0; i < k; ++i) {
        vs[i].resize(n);
        for (int j = 0; j < n; ++j) {
            cin >> vs[i][j];
        }
    }
    vector<int> result(k);

    for (int i = 0; i < k; ++i) {
        int minimal = n * m;
        int minimali = -1;
        for (int j = 0; j < k; ++j) {
            if (i == j)
                continue;
            int count = Diff(vs, i, j);
            if (minimal > count * w) {
                minimal = count * w;
                minimali = j;
            }
        }
        result[i] = minimali;
    }
    int summary = 0;
    {
        vector<bool> used(n, false);
        for (int i = 0; i < k; ++i) {
            if (used[result[i]]) {
                summary += Diff(vs, i, result[i]) * w;
            } else {
                summary += n * m;
            }
            used[i] = true;
        }
    }
    cout << summary << endl;
    {
        vector<bool> used2(n, false);
        for (int i = 0; i < k; ++i) {
            if (used2[result[i]]) {
                cout << i + 1 << ' ' << result[i] + 1 << '\n';
            } else {
                cout << i + 1 << " 0\n";
            }
            used2[i] = 1;
        }
    }
    cout.flush();

    return 0;
}
