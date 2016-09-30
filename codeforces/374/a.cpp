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

uint64_t powMod(uint64_t g, uint64_t pow, uint64_t mod)
{
    if (pow == 1)
        return g % mod;
    if (pow == 0)
        return 1;
    if (pow % 2 == 0)
        return powMod(g * g % mod, pow / 2, mod);
    return powMod(g, pow - 1, mod) * g % mod;
}

uint64_t inverse(uint64_t value, uint64_t mod) {
    if (value == 1)
        return 1;
    return powMod(value, mod - 2, mod);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    string s;
    cin >> s;
    s = s + 'W';
    vector<size_t> result;
    int count = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == 'W' && count) {
            result.push_back(count);
            count = 0;
        }
        if (s[i] == 'B')
            ++count;
    }
    cout << result.size() << endl;
    for (auto i : result)
        cout << i << ' ';


    return 0;
}
