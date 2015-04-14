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

    uint64_t a;
    uint64_t b;
    size_t n;
    cin >> a >> b >> n;
    for (size_t i = 0; i < n; ++i) {
        uint64_t l;
        uint64_t t;
        uint64_t m;
        cin >> l >> t >> m;
        --l;
        if (t < a) {
            cout << -1 << endl;
            continue;
        }
        uint64_t maxR = (t - a) / b;
        if (maxR < l) {
            cout << -1 << endl;
            continue;
        }
        uint64_t right = l;
        while (right <= maxR) {
            uint64_t sum = (l + right) * (right - l + 1) / 2 * b + (right - l + 1) * a;
            if (sum > m * t)
                break;
            else
                right += 1000;
        }
        if (right > maxR)
            right = maxR;
        while (right >= l) {
            uint64_t sum = (l + right) * (right - l + 1) / 2 * b + (right - l + 1) * a;
            if (sum > m * t)
                --right;
            else
                break;
        }
        if (right < l) {
            cout << -1 << endl;
        } else
            cout << right + 1 << endl;


    }
    return 0;
}
