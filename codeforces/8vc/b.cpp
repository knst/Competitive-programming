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

    uint64_t s;
    uint64_t x;
//    cin >> s >> x;

    size_t maxCount = 0;
    for (s = 10000; s < 1000; ++s) {
        for (x = 0; x < 1000; ++x) {
            size_t count = 0;
            for (uint64_t a = 1; a < s; ++a) {
                uint64_t b = s - a;
                if ((a ^ b) == x)
                    ++count;

            }
            if (count >= maxCount) {
                cout << maxCount << ' ' << s << ' ' << x << endl;
                maxCount = count;
            }
        }
    }

    for (s = 0; s < 20; ++s) {
        for (x = 0; x < 20; ++x) {
            size_t count = 0;
            for (uint64_t a = 1; a < s; ++a) {
                uint64_t b = s - a;
                if ((a ^ b) == x)
                    ++count;

            }
            cout << count << '\t';
        }
        cout << endl;
    }
        cout << endl;

    return 0;
}
