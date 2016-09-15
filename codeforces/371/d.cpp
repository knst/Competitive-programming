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
    struct hash<pair<T1, T2>> {
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}

//constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int64_t request(int64_t x1, int64_t y1, int64_t x2, int64_t y2) {
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    int64_t ans;
    cin >> ans;
    return ans;
}

int solve(int64_t R, int64_t& x1, int64_t& y1, int64_t& x2, int64_t& y2) {
    if (x1 > x2)
        return 0;
    if (y1 > y2)
        return 0;

    int64_t l, r;
    l = x1;
    r = x2;
    while (l != r) {
        int64_t mid = (l + r + 1) / 2;
        int64_t a = request(mid, y1, x2, y2);
        if (a < R) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    x1 = l;

    l = x1;
    r = x2;
    while (l != r) {
        int64_t mid = (l + r + 1) / 2;
        int64_t a = request(x1, y1, mid, y2);
        if (a < R) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    x2 = l;

    // y!
    l = y1;
    r = y2;
    while (l != r) {
        int64_t mid = (l + r + 1) / 2;
        int64_t a = request(x1, mid, x2, y2);
        if (a < R) {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    y1 = l;

    l = y1;
    r = y2;
    while (l != r) {
        int64_t mid = (l + r + 1) / 2;
        int64_t a = request(x1, y1, x2, mid);
        if (a < R) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    y2 = l;

    return request(x1, y1, x2, y2);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int64_t n;
    cin >> n;

    int64_t x1 = 1;
    int64_t x2 = n;
    int64_t y1 = 1;
    int64_t y2 = n;
    solve(2, x1, y1, x2, y2);

    set<vector<int64_t>> result;
    if (1 == request(x1, y1, x2 - 1, y2)) {
        int64_t a1 = x1;
        int64_t b1 = y1;
        int64_t a2 = x2;
        int64_t b2 = y2;
        a2--;
        if (solve(1, a1, b1, a2, b2))
            result.insert({a1, b1, a2, b2});
    }
    if (1 == request(x1, y1, x2, y2 - 1)) {
        int64_t a1 = x1;
        int64_t b1 = y1;
        int64_t a2 = x2;
        int64_t b2 = y2;
        b2--;
        if (solve(1, a1, b1, a2, b2))
            result.insert({a1, b1, a2, b2});
    }
    if (1 == request(x1 + 1, y1, x2, y2)) {
        int64_t a1 = x1;
        int64_t b1 = y1;
        int64_t a2 = x2;
        int64_t b2 = y2;
        a1++;
        if (solve(1, a1, b1, a2, b2))
            result.insert({a1, b1, a2, b2});
    }
    if (1 == request(x1, y1 + 1, x2, y2)) {
        int64_t a1 = x1;
        int64_t b1 = y1;
        int64_t a2 = x2;
        int64_t b2 = y2;
        b1++;
        if (solve(1, a1, b1, a2, b2))
            result.insert({a1, b1, a2, b2});
    }
    cout << "!";
    for (auto i : result)
        for (auto j : i)
            cout << " " << j;
    cout << endl;



    return 0;
}
