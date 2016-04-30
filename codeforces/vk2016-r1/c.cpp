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
    size_t d;
    size_t h;
    cin >> n >> d >> h;
    if (h == 1 && d == 2 && n > 2) {
        for (size_t i = 1; i < n; ++i) {
            cout << "1 " << i + 1 << '\n';
        }
        return 0;
    }

    if (h == 1 || d == 1) {
        if (n > 2) {
            cout << "-1" << endl;
            return 0;
        }
    }
    if (d < h) {
        cout << "-1" << endl;
        return 0;
    }

    if (d > h + h) {
        cout << "-1" << endl;
        return 0;
    }

    if (d == h) {
        if (d == n - 1) {
            for (size_t i = 1; i < n; ++i) {
                cout << i << ' ' << i + 1 << '\n';
            }
            return 0;
        }
        for (size_t i = 0; i < h; ++i) {
            cout << i + 1 << ' ' << i + 2 << '\n';
        }
        for (size_t i = h + 2; i <= n; ++i) {
            cout << "2 " << i << endl;
        }
        return 0;
    }
    size_t c = 1;
    vector<pair<size_t, size_t>> result;
    for (size_t i = 1; i <= h; ++i) {
        result.push_back({i, i + 1});
        ++c;
    }
    if (d > h) {
        result.push_back({1, h + 2});
        ++c;
    }
    for (size_t i = h; i + 1 < d; ++i) {
        result.push_back({c, c + 1});
        ++c;
    }
    while (c < n) {
        ++c;
        result.push_back({1, c});
    }
    if (c > n) {
        cout << -1 << endl;
        return 0;
    }
    for (auto i : result)
        cout << i.first << ' ' << i.second << '\n';



    return 0;
}
