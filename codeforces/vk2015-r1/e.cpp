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
    size_t k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto& i : v)
        cin >> i;
    size_t q;
    cin >> q;
    for (size_t i = 0; i < q; ++i) {
        int x;
        cin >> x;
        size_t minimum = 21;
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                for (size_t a = 0; a <= k; ++a)  {
                    for (size_t b = 0; a + b <= k; ++b) {
                        if (a * v[i] + b * v[j] == x) {
                            minimum = min<size_t>(minimum, a + b);
                        }
                    }
                }
            }
        }
        if (minimum != 21)
            cout << minimum << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}
