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
    cin >> n;
    vector<int64_t> m(n);
    vector<int64_t> r(n);
    for (auto& i : m) {
        cin >> i;
        if (i > 16) {
            while(true);
        }
    }
    for (auto& i : r) {
        cin >> i;
        if (i > 16) {
            while(true);
        }
    }
    size_t count1 = 0;
    for (int64_t d = 0; d < 1e7; ++d) {
        bool flag = false;
        for (size_t i = 0; i < n; ++i) {
            if (d % m[i] == r[i])
                flag = true;
        }
        if (flag)
            ++count1;
    }
    double result = static_cast<double>(count1) / 1e7;
    cout.precision(8);
    cout << fixed << result;
    return 0;
}
