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

//constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

//    multiset<int64_t> s;
    map<uint32_t, size_t> m;

    size_t q;
    cin >> q;
    while (q--) {
        char c;
        string value;
        cin >> c;
        cin >> value;
        uint32_t t = 0;
        for (auto i : value) {
            t = t * 2 + (i - '0') % 2;
        }
        if (c == '+')
            m[t]++;
        if (c == '-')
            m[t]--;
        if (c == '?')
            cout << m[t] << '\n';
    }



    return 0;
}
