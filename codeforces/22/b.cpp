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
    size_t m;
    cin >> n >> m;
    vector<string> v(n);

    for (auto& i : v)
        cin >> i;
    size_t maximum = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            for (size_t a = 1; a + i <= n; ++a) {
                for (size_t b = 1; b + j <= m; ++b) {
                    bool ok = true;
                    for (size_t x = i; ok && x < i + a; ++x) {
                        for (size_t y = j; ok && y < j + b; ++y) {
                            if (v[x][y] == '1')
                                ok = false;
                        }
                    }
                    if (ok) {
                        maximum = max(maximum, 2 * (a + b));
                    }
                }
            }
        }
    }
    cout << maximum << endl;

    return 0;
}
