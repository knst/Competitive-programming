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

constexpr uint64_t MOD = 1000 * 1000 * 1000 + 7;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    size_t m;
    cin >> m;
    size_t m2 = m;
    uint64_t count = 1;
    vector<int> v(n, -1);
    vector<pair<int,int>> M;
    while (m2--) {
        size_t i;
        size_t j;
        size_t t;
        cin >> i >> j >> t;
        if (t == 0) {
            M.push_back({i, j});
            if (v[i] == 1 && v[j] == 1) {
                cout << 0 << endl;
                return 0;
            }
        }
        if (t == 1) {
            v[i] = 1;
            v[j] = 1;
        }
    }
    for (auto i : M) {
        if (v[i.first] == 1 && v[i.second] == 1) {
            cout << 0 << endl;
            return 0;
        }
        if (v[i.first] == 1)
            v[i.second] = 0;
        if (v[i.second] == 1)
            v[i.first] = 0;
    }
    int c0 = 0;
    for (auto i : v) {
        if (i == 0)
            ++c0;
    }
    if (c0 > 2) {
        cout << 0 << endl;
        return 0;
    }
    for (auto i : v)
        if (i == -1)
            ++count;
    if (count == 3)
        count = 4;
    else
        count = 1 + count + count * (count - 1);
    count = count % MOD;
    cout << count << endl;
    return 0;
}
