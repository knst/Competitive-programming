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

bool test(vector<vector<int>>& mask, vector<string>& v, int direction, vector<pair<int,int>>& pillar2, int x, int y) {
    if (mask[x][y] & direction)
        return false;
    mask[x][y] |= direction;
    if (v[x][y] == '#')
        pillar2.push_back({x, y});
    return true;
}
int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    size_t m;
    cin >> n >> m;
    vector<string> v;
    for (size_t i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    const int pL = 1;
    const int pR = 2;
    const int pU = 4;
    const int pD = 8;
    vector<vector<int>> mask(n ,vector<int>(m, 0));

    vector<pair<int,int>> pillar;
    for (size_t i = 0; i < m; ++i) {
        mask[n-1][i] = pL;
        if (v[n-1][i] == '#')
            pillar.push_back({n - 1, i});
    }
    size_t count = 0;
    while (!pillar.empty()) {
        ++count;
        vector<pair<int,int>> pillar2;
        for (auto p : pillar) {
            size_t x = p.first;
            size_t y = p.second;
            for (size_t i = x; i <= x && test(mask, v, pU, pillar2, i, y); --i);
            for (size_t i = x; i <  n && test(mask, v, pD, pillar2, i, y); ++i);
            for (size_t i = y; i <= y && test(mask, v, pL, pillar2, x, i); --i);
            for (size_t i = y; i <  m && test(mask, v, pR, pillar2, x, i); ++i);
        }
        if (mask[0][0] & pL) {
            cout << count << endl;
            return 0;
        }
        pillar = pillar2;
    }
    cout << -1 << endl;


    return 0;
}
