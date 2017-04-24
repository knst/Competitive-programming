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


int process(const vector<vector<pair<int, int>>>& edges, int left, int right, int k, int current) {
    if (k == 1) return 0;
    if (k - 1 > right - current && k - 1 > current - left) return -1;
    static int m[81][81][81][81] = {};

    int best = m[left][right][current][k];
    if (best != 0) {
        return best;
    }

    best = -1;
    for (const auto& i : edges[current]) {
        if (i.first < left)
            continue;
        if (i.first >= right)
            continue;

        int nleft = left;
        int nright = right;
        if (i.first < current)
            nright = current;
        if (i.first > current)
            nleft = current + 1;
        int result = process(edges, nleft, nright, k - 1, i.first);
        if (result != -1) {
            result += i.second;
            if (best == -1)
                best = result;
            if (result < best)
                best = result;
        }
    }

    m[left][right][current][k] = best;
    return best;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int k;
    cin >> n >> k;

    int m;
    cin >> m;
    vector<vector<pair<int,int>>> edges(n);
    for (int i = 0; i < m; ++i) {
        int x;
        int y;
        int c;
        cin >> x >> y >> c;
        --x;
        --y;
        if (x == y)
            continue;
        edges[x].push_back({y, c});
    }

    int best = -1;
    for (int i = 0; i < n; ++i) {
        int result = process(edges, 0, n, k, i);
        if (best == -1) {
            best = result;
        }
        if (result != -1) {
            best = min(result, best);
        }
    }
    cout << best << endl;
}
