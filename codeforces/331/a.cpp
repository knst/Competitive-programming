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
    set<int> xs, ys;
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        int x;
        int y;
        cin >> x >> y;
        xs.insert(x);
        ys.insert(y);
    }
    if (xs.size() < 2 || ys.size() < 2) {
        cout << -1 << endl;
        return 0;
    }
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    for (auto i : xs) {
        x2 = x1;
        x1 = i;
    }
    for (auto i : ys) {
        y2 = y1;
        y1 = i;
    }
    cout << (y2 - y1) * (x2 - x1) << endl;




    return 0;
}
