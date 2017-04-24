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

#include <cmath>

using namespace std;

namespace std { template <class T1, class T2> struct hash<pair<T1, T2>> {
    size_t operator()(const pair<T1, T2>& p) const { return hash<T1>()(p.first) ^ hash<T2>()(p.second); }
};}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1)) * 4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

template<class T> T gcd(T A, T B) { return B == 0 ? A : gcd(B, A % B); }

uint64_t powMod(uint64_t G, uint64_t pow, uint64_t M) {
    if (pow == 0) return 1;
    return pow % 2 == 0 ? powMod(G * G % M, pow / 2, M) : powMod(G, pow - 1, M) * G % M;
}

uint64_t inverse(uint64_t X, uint64_t M) { return X == 1 ? 1 : powMod(X, M - 2, M); }

bool trace(const vector<string>& v, int i, int j, int di, int dj) {
    int n = v.size();
    int m = v[0].size();
    while (i >= 0 && j >= 0 && v[i][j] != '*') {
        i -= di;
        j -= dj;
    }
    i += di;
    j += dj;
    while (i < n && j < m && v[i][j] != '*') {
        if (v[i][j] == 'S')
            return true;
        i += di;
        j += dj;
    }
    return false;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto& i : v) {
        cin >> i;
    }

    int si = 0;
    int sj = 0;
    int ti = 0;
    int tj = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = 0; j < v[0].size(); ++j) {
            if (v[i][j] == 'S') {
                si = i;
                sj = j;
            }
            if (v[i][j] == 'T') {
                ti = i;
                tj = j;
            }
        }
    }

    for (int i = si; i >= 0; --i) {
        if (v[i][sj] == '*')
            break;
        v[i][sj] = 'S';
    }
    for (int i = si; i < n; ++i) {
        if (v[i][sj] == '*')
            break;
        v[i][sj] = 'S';
    }
    for (int j = sj; j >= 0; --j) {
        if (v[si][j] == '*')
            break;
        v[si][j] = 'S';
    }
    for (int j = sj; j < m; ++j) {
        if (v[si][j] == '*')
            break;
        v[si][j] = 'S';
    }

    bool possible = false;
    if (v[ti][tj] == 'S') {
        possible = true;
    }

    {
        int i = ti;
        while (i >= 0 && v[i][tj] != '*')
            i--;
        ++i;
        while (i < n && v[i][tj] != '*') {
            if (trace(v, i, tj, 0, 1)) {
                possible = true;
            }
            ++i;
        }
    }

    {
        int j = tj;
        while (j >= 0 && v[ti][j] != '*')
            --j;
        ++j;
        while (j < m && v[ti][j] != '*') {
            if (trace(v, ti, j, 1, 0)) {
                possible = true;
            }
            ++j;
        }
    }
    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
