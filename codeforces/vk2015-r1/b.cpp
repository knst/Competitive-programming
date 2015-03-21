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

uint64_t MAX = 1000L * 1000 * 1000 * 1000 + 1;
uint64_t test(vector<pair<int, int>>& v, int maxH) {
    size_t n = v.size();
    size_t m = (n + 1) / 2;
    vector<uint64_t> dyn(m + 1);
    for (auto i : v) {
        if (i.first > maxH && i.second > maxH)
            return MAX;
        if (i.first > maxH) {
            for (size_t j = 0; j <= m; ++j)
                dyn[j] += i.first;
        } else if (i.second > maxH) {
            for (size_t j = m; j > 0; --j) {
                dyn[j] = dyn[j - 1] + i.second;
            }
            dyn[0] = MAX;
        } else {
            for (size_t j = m; j > 0; --j) {
                dyn[j] = min(dyn[j - 1] + i.second,  dyn[j] + i.first);
            }
            dyn[0] += i.first;
        }
    }
    uint64_t minimal = MAX;
    for (auto i : dyn)
        minimal = min(minimal, i);
    return minimal;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    vector<pair<int,int>> v;
    set<int> hs;
    for (size_t i = 0;  i< n; ++i) {
        int w;
        int h;
        cin >> w >> h;
        hs.insert(h);
        v.push_back({w, h});
    }
    uint64_t minimal = MAX;

    for (auto i : hs) {
        uint64_t x = test(v, i);
        if (x == MAX)
            continue;
        minimal = min(minimal, x * i);
    }
    cout << minimal << endl;
    return 0;
}
