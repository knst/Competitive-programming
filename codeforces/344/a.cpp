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
    vector<uint64_t> a(n);
    vector<uint64_t> b(n);
    for (auto& i : a)
        cin >> i;
    for (auto& i : b)
        cin >> i;
    uint64_t M = 0;
    for (size_t i = 0; i < n; ++i) {
        uint64_t a1 = 0;
        uint64_t b1 = 0;
        for (size_t j = i; j < n; ++j) {
            a1 = a1 | a[j];
            b1 = b1 | b[j];
            M = max(M, a1 + b1);
        }

    }
    cout << M << endl;

    return 0;
}
