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
//##include <multiset>
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
    size_t k = n * n;
    multiset<int> v;
    for (size_t i = 0; i < k; ++i) {
        int x;
        cin >> x;
        x = -x;
        v.insert(x);
    }
    vector<int> result;

    for (size_t i = 0; i < n; ++i) {
        int next = -*v.begin();
        v.erase(v.find(-next));
        for (auto j : result) {
            int g = gcd(next, j);
            v.erase(v.find(-g));
            v.erase(v.find(-g));
        }
        result.push_back(next);
    }
    for (auto i : result)
        cout << i << ' ';
    cout << endl;


    return 0;
}
