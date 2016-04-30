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
    int32_t c;
    cin >> n >> c;
    vector<int> p(n);
    vector<int> t(n);
    for (auto& i : p)
        cin >> i;
    for (auto& i : t)
        cin >> i;

    int t1 = 0;
    int t2 = 0;
    int s1 = 0;
    int s2 = 0;
    for (size_t i = 0; i < n; ++i) {
        t1 += t[i];
        s1 += max(0, p[i] - c * t1);
    }

    for (size_t i = n - 1; i < n; --i) {
        t2 += t[i];
        s2 += max(0, p[i] - c * t2);
    }
    if (s1 > s2) {
        cout << "Limak" << endl;
    }
    if (s1 == s2) {
        cout << "Tie" << endl;
    }
    if (s1 < s2) {
        cout << "Radewoosh" << endl;
    }

    return 0;
}
