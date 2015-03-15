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
    set<int> s;
    multiset<int> s2;
    for (size_t i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
        s2.insert(x);
    }
    int count = 0;
    for (auto i : s) {
        cout << i << ' ';
        auto j = s2.find(i);
        s2.erase(j);
        ++count;
        if (count == k)
            break;
    }
    for (auto i : s2) {
        if (count == k)
            break;
        cout << i << ' ';
        ++count;
    }



    return 0;
}
