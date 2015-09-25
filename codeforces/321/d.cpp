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
    size_t k;
    cin >> n >> m >> k;
    vector<uint64_t> s(n);
    for (auto& i : s)
        cin >> i;

    vector<vector<uint64_t>> p(n, vector<uint64_t>>(n));
    for (size_t i = 0; i < n; ++i) {
        size_t x;
        size_t y;
        uint64_t c;
        cin >> x >> y >> c;
        x--;
        y--;
        p[x][y] = c;
    }

    size_t N = (1u << n);
    vector<vector<uint64_t>> values(N, vector<uint64_t>(n + 1));
    for (size_t i = 0; i < n; ++i) {



    }




    return 0;
}
