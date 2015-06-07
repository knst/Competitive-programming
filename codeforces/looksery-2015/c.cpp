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
    size_t k;
    cin >> n >> k;
    size_t a0 = 0;
    size_t a1 = 0;
    for (size_t i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x % 2)
            ++a1;
        else
            ++a0;
    }
    string D = "Daenerys";
    string S = "Stannis";
    size_t steps = n - k;
    size_t steps_s = (n - k + 1) / 2;
    size_t steps_d = (n - k) / 2;

    if (steps == 0) {
        if (a1 % 2 == 0)
            cout << D << endl;
        else
            cout << S << endl;
        return 0;
    }

    if (steps_d >= a1) {
        cout << D << endl;
        cerr << 1 << endl;
        return 0;
    }
    if (steps_d >= a0 && k % 2 == 0) {
        cout << D << endl;
        cerr << 1.5 << endl;
        return 0;
    }
    if (steps_s >= a0 && k % 2 == 1) {
        cout << S << endl;
        cerr << 2 << endl;
        return 0;
    }

    if (steps_s > steps_d)
        cout << S << endl;
    else
        cout << D << endl;



    return 0;
}
