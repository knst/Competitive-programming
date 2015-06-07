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
    vector<string> v(n);
    for (auto & i : v)
        cin >> i;
    size_t count = 0;
    for (size_t i = 1; i < n; ++i)
        for (size_t j = 1; j < m; ++j) {
            set<char> s;
            s.insert(v[i][j]);
            s.insert(v[i-1][j]);
            s.insert(v[i][j-1]);
            s.insert(v[i-1][j-1]);
            if (s.find('f') != s.end() && s.find('a') != s.end() && s.find('c') != s.end() && s.find('e') != s.end())
                ++count;
        }
    cout << count << endl;
    return 0;
}
