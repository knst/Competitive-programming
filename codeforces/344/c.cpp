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
    vector<int> values(n);
    for (auto & i: values)
        cin >> i;

    vector<pair<int, size_t>> s;
    for (size_t i = 0; i < m; ++i) {
        int t;
        size_t r;
        cin >> t >> r;
        while (!s.empty() && s.back().second <= r) {
            s.pop_back();
        }
        if (s.empty() || s.back().first != t) {
            s.push_back({t, r});
        }
//        for (auto i : s)
//            cerr << "A: " << i.first << ' ' << i.second << endl;
//        cerr << endl;
    }
    if (s.back().first == 1)
        s.push_back({2, 0});
    else
        s.push_back({1, 0});

    size_t l = 0;
    size_t r = s[0].second;
    vector<int> result(n);
    for (size_t i = r; i < n; ++i)
        result[i] = values[i];
    sort(values.begin(), values.begin() + r);
//    if (s[0].first == 2)
//        reverse(values.begin(), values.begin() + r);
    size_t last = r;
    for (size_t i = 1; i < s.size(); ++i) {
        for (size_t k = s[i].second; k < s[i-1].second; ++k) {
            if (s[i-1].first == 1) {
                r--;
                last--;
                result[last] = values[r];
            } else {
                last--;
                result[last] = values[l];
                l++;
            }
        }
    }
    for (auto i : result)
        cout << i << ' ';
    cout << endl;

    return 0;
}
