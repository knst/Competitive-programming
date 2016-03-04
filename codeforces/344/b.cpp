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
    size_t m;
    size_t k;
    cin >> n >> m >> k;
    vector<pair<uint32_t, size_t>> r(n);
    vector<pair<uint32_t, size_t>> c(m);

    for (size_t i = 1; i <= k; ++i) {
        int type;
        cin >> type;
        size_t j;
        cin >> j;
        --j;
        uint32_t color;
        cin >> color;
        if (type == 1) {
            r[j] = {color, i};
        } else {
            c[j] = {color, i};
        }
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (r[i].second > c[j].second)
                cout << r[i].first << ' ';
            else
                cout << c[j].first << ' ';
        }
        cout << endl;
    }


    return 0;
}
