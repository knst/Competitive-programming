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

    size_t t;
    cin >> t;
    while (t--) {
        size_t n;
        size_t m;
        cin >> n >> m;
        vector<string> v(n);
        for (auto & i : v)
            cin >> i;
        size_t count = 0;
        for (size_t i = 1; i < n-1; ++i) {
            for (size_t j = 0; j < m; ++j) {
                if (v[i][j] == 'o' && v[i-1][j] == 'v' && v[i+1][j] == '^')
                    ++count;

            }
        }
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 1; j < m - 1; ++j) {
                if (v[i][j] == 'o' && v[i][j-1] == '>' && v[i][j+1] == '<')
                    ++count;

            }
        }
        cout << count << endl;
    }


    return 0;
}
