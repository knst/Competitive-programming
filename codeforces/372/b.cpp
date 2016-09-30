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

    string s;
    cin >> s;
    string result = "-1";
    for (size_t i = 25; i < s.size(); ++i) {
        bool mask[26] = {};
        bool ok = true;
        for (size_t j = 0; j < 26; ++j) {
            char c = s[i - j];
            if (c != '?') {
                if (mask[c - 'A'])
                    ok = false;
                mask[c - 'A'] = true;
            }
        }
        if (ok) {
            size_t next = 0;
            for (size_t j = 0; j < 26; ++j) {
                if (s[i - j] == '?') {
                    while (mask[next])
                        ++next;
                    s[i - j] = 'A' + next++;
                }
            }
            replace(s.begin(), s.end(), '?', 'A');

            result = s;
        }
    }
    cout << result << endl;
}
