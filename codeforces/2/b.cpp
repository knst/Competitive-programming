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

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> v2(n, vector<int>(n));
    vector<vector<int>> v5(n, vector<int>(n));
    bool zero = false;
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int value;
            cin >> value;
            if (value == 0) {
                zero = true;
                x = i;
                y = j;
                v5[i][j] += n * n * 10 + 1;
                v2[i][j] += n * n * 10 + 1;
            }
            while (value != 0 && (value % 5 == 0 || value % 2 == 0)) {
                if (value % 5 == 0) {
                    v5[i][j]++;
                    value /= 5;
                }
                if (value % 2 == 0) {
                    v2[i][j]++;
                    value /= 2;
                }
            }
        }
    }
    vector<vector<long long>> d2(n, vector<long long>(n));
    vector<vector<long long>> d5(n, vector<long long>(n));
    d2[0][0] = v2[0][0];
    d5[0][0] = v5[0][0];

    for (int i = 1; i < n; ++i) {
        d5[i][0] = d5[i-1][0] + v5[i][0];
        d5[0][i] = d5[0][i-1] + v5[0][i];
        d2[i][0] = d2[i-1][0] + v2[i][0];
        d2[0][i] = d2[0][i-1] + v2[0][i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j< n; ++j) {
            d2[i][j]= min(d2[i][j-1], d2[i-1][j]) + v2[i][j];
            d5[i][j]= min(d5[i][j-1], d5[i-1][j]) + v5[i][j];
        }
    }
    long long result = min(d2[n-1][n-1], d5[n-1][n-1]);
    string S = "";
/*
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << d5[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << d2[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
*/
    if (result == 0 || !zero) {
        int x = n-1;
        int y = n-1;
        vector<vector<long long>>& d = (result == d2[x][y]) ? d2 : d5;
        vector<vector<int>>& v = (result == d2[x][y]) ? v2 : v5;
        while (x != 0 || y != 0) {
            if (x == 0 && y != 0) {
                S = 'R' + S;
                --y;
            } else if (y == 0 && x != 0) {
                S = 'D' + S;
                --x;
            } else if (d[x-1][y] + v[x][y] == d[x][y]) {
                S = 'D' + S;
                --x;
            } else {
                S = 'R' + S;
                --y;
            }

        }
        cout << result << endl;
        cout << S << endl;
    } else {
        cout << 1 << endl;
        for (int i = 0; i < x; ++i)
            cout << 'D';
        for (int j = 0; j < n-1; ++j)
            cout << 'R';
        for (int i = x; i < n-1; ++i)
            cout << 'D';
        cout << endl;
    }

    return 0;
}
