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

int R(int c, int k) {
    int r = 0;
    r += (c - 1) / k * 5;
    r += c;
    return r;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    size_t k;
    cin >> n >> k;
    vector<size_t> v(n);
    for(auto& i : v) {
        string s;
        cin >> s;
        i = s.size();
    }
    string pass;
    cin >> pass;
    size_t original = pass.size();
    int wcount = 0;
    int bcount = 0;
    for (size_t i = 0; i < n; ++i) {
        if (v[i] == original)
            ++wcount;
        if (v[i] < original) {
            ++bcount;
            ++wcount;
        }
    }
    cout << R(bcount + 1, k) << ' ' << R(wcount, k) << endl;
}
