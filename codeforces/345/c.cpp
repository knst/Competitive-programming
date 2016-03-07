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
    map<int, multiset<int>> xm;
    map<int, multiset<int>> ym;
    map<pair<int, int>, size_t> ms;

    for (size_t i = 0; i < n; ++i) {
        int x;
        int y;
        cin >> x >> y;
        xm[x].insert(y);
        ym[y].insert(x);
        ms[{x, y}]++;
    }
    uint64_t count = 0;
    for (auto i : xm) {
        uint64_t c1 = i.second.size();
        count += c1 * (c1 - 1) / 2;
    }
    for (auto i : ym) {
        uint64_t c2 = i.second.size();
        count += c2 * (c2 - 1) / 2;
    }
    for (auto i : ms) {
        uint64_t c3 = i.second;
        count -= c3 * (c3 - 1) / 2;
    }
    cout << count << endl;


    return 0;
}
