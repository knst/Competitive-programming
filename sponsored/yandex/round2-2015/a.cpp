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
    int m;
    cin >> n >> m;
    vector<int> v(n + 1);
    for (size_t i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    uint64_t mod = 1000 * 1000 * 1000 + 7;
    vector<uint64_t> r(n + 1, 0);
    r[0] = 1;
    size_t start = 0;
    uint64_t sum = 1;
    int64_t h = 0;

    for (size_t i = 1; i < r.size(); ++i) {
        h += v[i];
        while (h > m) {
            sum = (sum + mod - r[start]) % mod;
            h -= v[start + 1];
            ++start;
        }
        r[i] = sum;
        sum = (sum + r[i]) % mod;
    }
    cout << r[n] << endl;
    return 0;
}
