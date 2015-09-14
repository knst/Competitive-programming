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
    size_t m;
    cin >> n >> m;
    size_t N = 1 << n;
    vector<vector<uint32_t>> v(n + 1, vector<uint32_t>(N));
    for (auto& i : v[0])
        cin >> i;
    size_t P = N;
    for (size_t i = 1; i <= n; ++i) {
        P /= 2;
        for (size_t j = 0; j < P; ++j) {
            if (i % 2)
                v[i][j] = v[i-1][j * 2] | v[i-1][j * 2 + 1];
            else
                v[i][j] = v[i - 1][j * 2] ^ v[i - 1][j * 2 + 1];
        }
    }
    for (size_t k = 0; k < m; ++k) {
        size_t p;
        int32_t x;
        cin >> p >> x;
        --p;
        v[0][p] = x;
        for (size_t i = 1; i <= n; ++i) {
            p /= 2;
            if (i % 2)
                v[i][p] = v[i-1][p * 2] | v[i-1][p * 2 + 1];
            else
                v[i][p] = v[i - 1][p * 2] ^ v[i - 1][p * 2 + 1];
        }
        cout << v[n][0] << '\n';
    }
    cout.flush();


    return 0;
}
