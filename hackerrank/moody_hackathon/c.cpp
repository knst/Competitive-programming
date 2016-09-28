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

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

bool wrongLine(const string& s) {
    size_t n = s.size();
    if (s[0] == '*')
        return true;
    if (s.back() == '*')
        return true;

    for (size_t i = 1; i < n; ++i) {
        if (s[i-1] == '*' && s[i] == '0')
            return true;
    }
    for (size_t i = 2; i < n; ++i) {
        if (s[i-1] == '*' && s[i] == '*' && s[i-2] == '*')
            return true;
    }
    return false;
}

const int64_t mod = 1000 * 1000 * 1000 + 7;

int64_t s64(const string& s, int64_t mod) {
    int64_t result = 0;
    for (auto i : s) {
        result = (result * 10 + i - '0') % mod;
    }
    return result;
}

int64_t mul(int64_t a, int64_t b, int64_t mod)
{
    return a % mod * (b % mod) % mod;
}

int64_t powMod(int64_t g, int64_t pow, int64_t mod)
{
    if (pow == 1)
        return g % mod;
    if (pow == 0)
        return 1;
    if (pow % 2 == 0)
        return powMod(g * g % mod, pow / 2, mod);
    return powMod(g, pow - 1, mod) * g % mod;
}

int64_t calculate(const string& s) {
    vector<string> terms;

    size_t n = s.size();
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '*') {
            if (s[i + 1] == '*') {
                terms.push_back("**");
                ++i;
            } else {
                terms.push_back("*");
            }
        } else {
            size_t j = i;
            while (s[j] >= '0' && s[j] <= '9')
                ++j;
            terms.push_back(s.substr(i, j - i));
            i = j - 1;
        }
    }
    int64_t result = 1;
    for (size_t i = 0; i < terms.size(); i += 2) {
        int64_t last = s64(terms[i], mod);
        while (i + 1 < terms.size() && terms[i + 1] == "**") {
            last = powMod(last, s64(terms[i + 2], mod - 1), mod);
            i += 2;
        }
        result = mul(result, last, mod);
    }
    return result;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (wrongLine(s)) {
            cout << "Syntax Error" << endl;
            continue;
        } else {
            cout << calculate(s) << endl;
        }
    }
}
