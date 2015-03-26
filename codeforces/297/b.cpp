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

    string s;
    cin >> s;
    size_t m;
    cin >> m;
    size_t n;
    n = s.size();
    vector<bool> mask(n);
    for (size_t i = 0; i < m; ++i) {
        size_t x;
        cin >> x;
        --x;
        mask[x] = !mask[x];
        mask[n - x - 1] = !mask[n - x - 1];
    }

    size_t flip = false;
    for (size_t i = 0; i < n; ++i) {
        if (i < n / 2)
            if (mask[i])
                flip = !flip;
        if (flip)
            cout << s[n - i - 1];
        else
            cout << s[i];
        if (i >= n / 2)
            if (mask[i])
                flip = !flip;
    }
    cout << endl;

    return 0;
}
