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

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

uint32_t w(uint32_t x) {
    int c = 0;
    while (x) {
        ++c;
        x &= x-1;
    }
    return c;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    uint32_t n;
    cin >> n;
    uint32_t k;
    cin >> k;
    vector<int64_t> v(n);
    for(auto& i : v)
        cin >> i;
    int64_t bestSum = -1;
    for (uint32_t p = 1; p < (1u << n); ++p) {
        if (w(p) != k)
            continue;
        int64_t sum = 0;
        for (size_t i = 0; i < n; ++i) {
            if (p & (1 << i))
                continue;
            for (size_t j = 0; j < n; ++j) {
                if (!(p & (1 << j)))
                    continue;
                sum += abs(v[i] - v[j]);
            }
        }
        if (sum < bestSum || bestSum == -1)
            bestSum = sum;
    }
    cout << bestSum << endl;

    return 0;
}
