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
    vector<int> v(n);
    for (auto& i : v)
        cin >> i;

    v[0] = 1;
    v[n - 1] = 1;
    bool changed;
    do {
        changed = false;
        for (size_t i = 1; i < n; ++i) {
            if (v[i] > v[i - 1] + 1) {
                v[i] = v[i - 1] + 1;
                changed = true;
            }
        }
        for (size_t i = n - 1; i > 0; --i) {
            if (v[i - 1] > v[i] + 1) {
                v[i - 1] = v[i] + 1;
                changed = true;
            }
        }
    } while (changed);
    int M = 0;
    for (auto i : v)
        M = max(M, i);
    cout << M << endl;

    return 0;
}
