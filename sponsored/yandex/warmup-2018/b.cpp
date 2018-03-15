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

int comp(std::string a, std::string b) {
    return a < b;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    size_t n = s.size();

    set<string> sols2;
    set<string> sols3;

    for (size_t i = 0; i + 1 < n; ++i) {
        char a = s[i];
        char b = s[i + 1];
        if (a == b) {
            sols2.insert(string("") + a + b);
        }
        if (i + 2 < n) {
            char c = s[i + 2];
            if (a == c) {
                sols3.insert(string("") + a + b + c);
            }
        }
    }
    if (sols2.size() > 0) {
        cout << *sols2.begin() << endl;
    } else if (sols3.size() > 0) {
        cout << *sols3.begin() << endl;
    } else {
        cout << "-1" << endl;
    }



}
