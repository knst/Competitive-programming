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
    int n;
    cin >> n;
    int y = 3;
    int m = 2;
    int d = 1;
    int t = 1;
    for (; t < n && y < 13; ++t) {
        do {
            ++d;
            if (d >= m) {
                ++m;
                d = 1;
            }
            if (m >= y || m > 12) {
                m = 2;
                ++y;
            }
        } while(d > m || m > y);
    }
    y += (n - t) / 66;
    t += (n - t) / 66 * 66;
    for (; t < n; ++t) {
        do {
            ++d;
            if (d >= m) {
                ++m;
                d = 1;
            }
            if (m >= y || m > 12) {
                m = 2;
                ++y;
            }
        } while(d > m || m > y);
    }


    cout << y << '/' << m << '/' << d << endl;
    return 0;
}
