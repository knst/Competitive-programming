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

struct A {
static int calc() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n, m, k;
    cin >> n >> m >> k;

    vector<size_t> c(n);
    for (auto& i : c) {
        cin >> i;
        if (i == 0)
            i = 1000;
        --i;
    }
    vector<vector<long>> p(n, vector<long>(m));
    for (auto& i : p) {
        for (auto& j : i) {
            cin >> j;
        }
    }

    // for m-color already k lines: sum for it.
    vector<vector<long>> sum(m, vector<long>(k + 1, -1));
    for (size_t i = 0; i < m; ++i) {
        if (c[i] == 999) {
            sum[i][0] = p[0][i];
        } else {
            sum[i][0] = 0;
        }
    }
    for (size_t i = 1; i < n; ++i) {
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < k; ++j) {
                cout << sum[i][j] << ' ';
            }
            cout << endl;
        }
        vector<vector<long>> sum2(m, vector<long>(k + 1, -1));
        for (size_t j = 0; j < k; ++j) {
            for (size_t a = 0; a < m; ++a) {
                if (c[i] != 999) {
                    if (sum[a][j] != -1) {
                        if (a == c[i]) {
                            if (sum2[a][j] == -1)
                                sum2[a][j] = sum[a][j];
                            else
                                sum2[a][j] = min(sum2[a][j], sum[a][j]);
                        } else {
                            if (sum2[c[i]][j + 1] == -1)
                                sum2[c[i]][j + 1] = sum[a][j];
                            else
                                sum2[c[i]][j + 1] = min(sum2[c[i]][j + 1], sum[a][j]);
                        }
                    }
                } else {
                    for (size_t b = 0; b < m; ++b) {
                        if (sum[b][j] != -1) {
                            if (a == b) {
                                if (sum2[a][j] == -1)
                                    sum2[a][j] = sum[b][j] + p[i][a];
                                else
                                    sum2[a][j] = min(sum[a][j], sum[b][j] + p[i][a]);
                            } else {
                                if (sum[b][j] != -1) {
                                    if (sum2[a][j + 1] == -1)
                                        sum2[a][j + 1] = sum[b][j] + p[i][a];
                                    else
                                        sum2[a][j + 1] = min(sum[a][j + 1], sum[b][j] + p[i][a]);
                                }
                            }
                        }
                    }
                }
            }
        }
        sum = sum2;

    }
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < k; ++j) {
            cout << sum[i][j] << ' '; }
        cout << endl;
    }
    long res = -1;
    for (size_t i = 0; i < m; ++i) {
        if (res == -1) {
            res = sum[i][k - 1];
        } else {
            long s = sum[i][k-1];
            if (s != -1)
                res = min(s, res);
        }
    }
    cout << res << endl;

    return 0;
} };

int main() {
    return A::calc();
}
