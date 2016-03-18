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

    uint32_t n, a, b;
    cin >> n >> a >> b;
    if (a * b < n) {
        cout << "-1\n";
        return 0;
    }
    vector<vector<uint32_t>> v(a, vector<uint32_t>(b));
    uint32_t x = 0;
    uint32_t y = 0;
    for (size_t i = 0; i < a; ++i) {
        for (size_t j = 0; j < b; ++j) {
            if ((i + j) % 2 == 0) {
                v[i][j] = x++ * 2 + 1;
            } else {
                v[i][j] = ++y * 2;
            }
        }
    }
    for (auto i : v) {
        for (auto j : i) {
            if (j <= n) {
                cout << j << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << endl;
    }


    return 0;
}
