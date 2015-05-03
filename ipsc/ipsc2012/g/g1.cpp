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

    int t;
    cin >> t;
    while (t--) {
        uint64_t a;
        uint64_t b;
        uint64_t c;
        uint64_t n;
        cin >> a >> b >> c >> n;
        size_t maximal = 0;
        for (size_t i = 0; i < n; ++i) {
            set<uint64_t> visited;
            size_t x = i;
            do {
                visited.insert(x);
                x = (a * x * x + b * x + c) % n;
            } while (visited.find(x) == visited.end());
            maximal = max(maximal, visited.size());
        }

        cout << maximal << endl;
    }

    return 0;
}
