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

    uint64_t m = 123456788;
    for (uint64_t a = 2; a <= m; ++a) {
        cout << a << endl;
    for (uint64_t b = a + 1; a + b <= m; ++b) {
        if (b % a)
            continue;
    for (uint64_t c = b + b; a + b + c <= m; c += b) {
    for (uint64_t d = c + c; a + b + c + d + d<= m; d += c) {
        uint64_t e = m - a - b - c - d;
        if (e % d)
            continue;
        if (e <= d)
            continue;
        cout << a << ' ' << b<< ' '  << c<< ' '  << d<< ' '  << e << endl;

    }
    }
    }
    }
    return 0;
}
