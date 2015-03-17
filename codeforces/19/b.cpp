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

    size_t n;
    cin >> n;
    uint64_t MAX = numeric_limits<uint64_t>::max() / 2;
    vector<uint64_t> cs(n * 2001 + 1, MAX);
    cs[0] = 0;
    size_t last = 0;
    for (size_t i = 0; i < n; ++i) {
        size_t t;
        uint64_t c;
        cin >> t >> c;
        ++t;
        for (size_t j = last; j <= last; --j) {
            cs[j + t] = min(cs[j + t], cs[j] + c);
        }
        last += t;
        last = min<size_t>(last, 4002);
    }
    uint64_t ans = MAX;
    for (size_t i = n; i <= last; ++i) {
        ans = min(ans, cs[i]);
    }
    cout << ans << endl;


    return 0;
}
