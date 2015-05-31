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

    size_t t;
    cin >> t;
    while (t--) {
        uint64_t a;
        uint64_t b;
        cin >> a >> b;
        vector<int> digits(10);
        while (a % 9 != b % 9) {
            digits[a % 9]++;
            ++a;
        }
        digits[a % 9]++;
        int m = -1;
        int mn = 0;
        for (auto i : digits) {
            if (i > m)
                m = i, mn = 0;
            if (i == m)
                ++mn;
        }
        cout << mn;
        for (size_t i = 1; i < digits.size(); ++i)
            if (digits[i] == m)
                cout << ' ' << i;
        if (digits[0] == m)
            cout << ' ' << 9;
        cout << '\n';

    }


    return 0;
}
