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
    cin.tie(0);

    size_t n;
    cin >> n;
    vector<vector<long long>> v(n, vector<long long>(n));
    size_t a, b;
    for (size_t i = 0;i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            cin >> v[i][j];
            if (v[i][j] == 0)
                a = i, b = j;
        }
    }
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    long long sum = 0 , sum2 = 0;
    size_t I = 0;
    if (a == 0)
        ++I;
    for (size_t j = 0; j< n; ++j) {
        sum += v[I][j];
        sum2 += v[a][j];
    }
    v[a][b] = sum - sum2;
    for (size_t i = 0; i < n; ++i) {
        long long s1 = 0;
        long long s2 = 0;
        for (size_t j = 0; j < n; ++j) {
            s1 += v[i][j];
            s2 += v[j][i];
        }
        if (s1 != sum || s2 != sum) {
            cout << -1 << endl;
            return 0;
        }
    }
    long long s1 = 0, s2 = 0;
    for (size_t i = 0; i < n; ++i) {
        s1 += v[i][i];
        s2 += v[n - i - 1][i];
    }
        if (s1 != sum || s2 != sum || v[a][b] <= 0) {
            cout << -1 << endl;
            return 0;
        }
        cout << v[a][b] << endl;;


    return 0;
}
