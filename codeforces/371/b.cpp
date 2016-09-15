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
    struct hash<pair<T1, T2>> {
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}

//constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    set<int> values;
    for (size_t i = 0; i < n; ++i) {
        int x;
        cin >> x;
        values.insert(x);
    }
    vector<int> v;
    for (auto i : values)
        v.push_back(i);
    sort(v.begin(), v.end());
    if (v.size() <= 2) {
        cout << "YES\n";
        return 0;
    }
    if (v.size() > 3) {
        cout << "NO" << endl;
        return 0;
    }
    if (v.size() == 3) {
        if (v[0] - v[1] == v[1] - v[2]) {
            cout << "YES" << endl;
        }else {
            cout << "NO" << endl;
        }
    }


    return 0;
}
