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

int s2i(char a, char b, char c) {
    int r = a - 'A';
    r = r * 26 + b - 'A';
    r = r * 26 + c - 'A';
    return r;
}

string i2s(int x) {
    char c = x % 26 + 'A';
    x /= 26;
    char b = x % 26 + 'A';

    char a = x / 26 + 'A';
    return string() + a + b + c;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    vector<pair<int, int>> v;
    for (size_t i = 0; i < n; ++i) {
        string a;
        string b;
        cin >> a >> b;
        int s1 = s2i(a[0], a[1], a[2]);
        int s2 = s2i(a[0], a[1], b[0]);
        v.push_back({s1, s2});
    }
    int Max = 20000;

    vector<int> choose(n);
    while (true) {
        bool wrongs = false;
        vector<int> count(Max, 0);
        for (size_t i = 0; i < n; ++i) {
            if (choose[i] == 0) {
                count[v[i].first]++;
            } else {
                count[v[i].second]++;
            }
        }
        for (auto i : count) {
            if (i > 1) {
                wrongs = true;
            }
        }
        if (wrongs == false) {
            break;
        }
        bool changed = false;
        for (size_t i = 0; i < n; ++i) {
            if (choose[i] == 0) {
                if (count[v[i].first] > 1) {
                    choose[i] = 1;
                    changed = true;
                }
            } else {
                if (count[v[i].second] > 1) {
                }
            }
        }
        if (!changed) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for (size_t i = 0; i < n; ++i) {
        string s = i2s(v[i].first);
        if (choose[i] == 1)
            s = i2s(v[i].second);
        cout << s << endl;
    }


}
