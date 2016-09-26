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

//constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int solve(size_t n, const string& s) {
    int result = 0;
    int bc = 0;
    int rc = 0;
    for (size_t i = 0; i < n; ++i) {
        if ((s[i] == 'r') ^ (i % 2 == 0)) {
            if (s[i] == 'r')
                ++rc;
            else
                ++bc;
        }
    }
    result += min(bc, rc);
    bc -= result;
    rc -= result;
    result += bc;
    result += rc;
    return result;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    string s;
    cin >> s;
    int result = solve(n, s);
    for (auto& i : s)
        if (i == 'b')
            i = 'r';
        else
            i = 'b';
    result = min(result, solve(n, s));
    cout << result << endl;

    return 0;
}
