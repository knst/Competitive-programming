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

bool test(int64_t t1, int64_t t2) {
    if (t1 == 0)
        return true;
    if (t1 == 0)
        return false;
    if (t1 > 0 && t2 > 0)
        return true;
    if (t1 < 0 && t2 < 0)
        return true;
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    const string Y = "YES";
    const string N = "NO";

    int64_t xa, ya;
    int64_t xb, yb;
    cin >> xa >> ya >> xb >> yb;
    int64_t x = xb - xa;
    int64_t y = yb - ya;
    if (x == 0 && y == 0) {
        cout << Y << endl;
        return 0;
    }
    size_t n;
    cin >> n;
    vector<pair<int64_t, int64_t>> v(n);
    for (auto & i : v)
        cin >> i.first >> i.second;

    for (auto i : v) {
        if (i.first == 0 && i.second == 0)
            continue;
        if (
            i.first * y == i.second * x &&
            (i.first >= 0) == (x >= 0) &&
            (i.second >= 0) == (y >= 0)
        ) {
            cout << Y << endl;
            return 0;
        }
    }

    for (auto i : v)
        for (auto j : v) {
            int64_t x0 = i.first;
            int64_t y0 = i.second;
            int64_t x1 = j.first;
            int64_t y1 = j.second;
            if (x0 * y1 == x1 * y0)
                continue;
            if (test(
                        x * y1 - x1 * y,
                        y1 * x0 - y0 * x1
                    ) &&
                test(
                        y * x0 - y0 * x,
                        y1 * x0 - y0 * x1
                    )) {
                cout << Y << endl;
                return 0;
            }
        }
    cout << N << endl;

    return 0;
}
