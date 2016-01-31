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


    vector<vector<int>> v(n, vector<int>(n));
    for (auto& i : v)
        for (auto& j : i)
            cin >> j;
    vector<int> values(n);
    for (size_t i = 1; i <= n; ++i) {
        int hypo = -1;
        for (size_t j = 0; j < n; ++j) {
            bool possible = true;
            for (size_t k = 0; k < n; ++k) {
                if (v[j][k] > i)
                    possible = false;
                if (v[k][j] > i)
                    possible = false;
            }
            if (possible && values[j] == 0)
                hypo = j;
        }
        values[hypo] = i;
    }
    for (auto i : values)
        cout << i << ' ';
    cout << endl;

    return 0;
}
