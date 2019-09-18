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

#include <cmath>

using namespace std;

namespace std { template <class T1, class T2> struct hash<pair<T1, T2>> {
    size_t operator()(const pair<T1, T2>& p) const { return hash<T1>()(p.first) ^ hash<T2>()(p.second); }
};}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1)) * 4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

template<class T> T gcd(T A, T B) { return B == 0 ? A : gcd(B, A % B); }

uint64_t powMod(uint64_t G, uint64_t pow, uint64_t M) {
    if (pow == 0) return 1;
    return pow % 2 == 0 ? powMod(G * G % M, pow / 2, M) : powMod(G, pow - 1, M) * G % M;
}

uint64_t inverse(uint64_t X, uint64_t M) { return X == 1 ? 1 : powMod(X, M - 2, M); }

void swap_more(std::string& s, std::string& t, size_t i, size_t j, std::vector<pair<size_t, size_t>>& answer) {
    swap(s[i], t[j]);
    answer.push_back({i, j});
}
void apply(std::string& s, std::string& t, std::vector<pair<size_t, size_t>>& answer, bool &changed) {
    size_t n = s.size();
    for (size_t i = 0; i < n; ) {
        if (s[i] == t[i]) {
            ++i;
            continue;
        }
        size_t j = i + 1;
        while (j < n && (s[j] == t[j] || t[j] == s[i])) {
            ++j;
        }
        if (j < n) {
            swap_more(s, t, i, j, answer);
            changed = true;
        }
        i = j + 1;
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;

    string s;
    string t;
    cin >> s >> t;


    size_t acount_s = 0;
    for (auto i : s) {
        if (i == 'a') ++acount_s;
    }
    size_t acount_t = 0;
    for (auto i : t) {
        if (i == 'a') ++acount_t;
    }

    size_t acount = acount_s + acount_t;
    if (acount % 2 != 0) {
        cout << "-1" << endl;
        return 0;
    }
    std::vector<pair<size_t, size_t>> answer;
    bool changed = false;
    do {
        changed = false;
        apply(s, t, answer, changed);
        apply(t, s, answer, changed);
        if (!changed) {
            for (size_t i = 0; i < n; ++i) {
                if (s[i] != t[i]) {
                    swap_more(s, t, i, i, answer);
                    changed = true;
                    break;
                }
            }
        }
    } while (changed);
    cout << answer.size() << endl;
    for (auto i : answer) {
        cout << i.first + 1<< ' ' << i.second + 1 << '\n';
    }

}
