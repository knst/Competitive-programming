/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <fstream>
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

    ifstream input("bestbuy.in");
    ofstream output("bestbuy.out");

    int c1;
    int c2;
    input >> c1 >> c2;
    size_t n;
    cin >> n;
    multiset<pair<int, pair<int, int>>> s;
    for (size_t i = 0; i < n; ++i) {
        int a;
        int t;
        input >> a >> t;
        s.insert({t, {0, a}});
    }
    size_t m;
    input >> m;
    vector<bool> v(m+1, true);
    for (size_t i = 1; i <= m; ++i) {
        int a;
        int b;
        input >> a >> b;
        s.insert({a, {1, i}});
        s.insert({b, {1, -i}});
    }
    int sum = 0;
    int result = 0;
    for (auto i : s) {
        if (i.second.first == 0) {
            sum += i.second.second;
        } else {
            if (i.second.second > 0 && c1 <= sum) {
                v[i.second.second] = false;
                sum -= c1;
                ++result;
            }
            if (i.second.second < 0 && c2 <= sum) {
                if (v[- i.second.second ]) {
                    sum -= c2;
                    ++result;
                }
            }
        }
    }

    output << result << endl;

    return 0;
}
