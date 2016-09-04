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

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<string> v(n);
    for (auto& i : v)
        cin >> i;

    int m = n + n - 1;
    vector<vector<char>> field(m, vector<char>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            bool accepted = true;
            for (int a = 0; a < n; ++a) {
                for (int b = 0; b < n; ++b) {
                    if (v[a][b] == 'o') {
                        int x = a + i - n + 1;
                        int y = b + j - n + 1;
                        if (x >= 0 && y >= 0 && x < n && y < n) {
                            if (v[x][y] == '.')
                                accepted = false;
                        }
                    }
                }
            }
            if (accepted)
                field[i][j] = 'x';
            else
                field[i][j] = '.';
        }
    }
    field[n-1][n-1] = 'o';
    for (int a = 0; a < n; ++a) {
        for (int b = 0; b < n; ++b) {
            if (v[a][b] != 'o')
                continue;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (field[i][j] != 'x')
                        continue;
                    int x = a + i - n + 1;
                    int y = b + j - n + 1;
                    if (x >= 0 && y >= 0 && x < n && y < n)
                        if (v[x][y] == 'x')
                            v[x][y] = '.';
                }
            }
        }
    }
    bool ok = true;
    for (auto i : v)
        for (auto j : i)
            if (j == 'x')
                ok = false;
    if (!ok)
        cout << "NO" << endl;
    else {
        cout << "YES" << endl;
        for (auto i : field) {
            for (auto j : i)
                cout << j;
            cout << endl;
        }
    }

    return 0;
}
