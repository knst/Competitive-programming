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

bool test(const vector<vector<int64_t>>& v)
{
    bool ok = false;
    for (const auto& i : v) {
        int64_t g = i[0];
        for (auto j : i)
            g = gcd(g, j);
        if (g < 0) g = -g;
        if (g != 1) {
            ok = true;
            for (auto j : i)
                cout << j << ' ';
            cout << endl;
        }
    }
    return ok;
}

int brute(const vector<int64_t>& v)
{
    int n = v.size();
    int count = 0;
    vector<vector<int64_t>> u{v};
    while (!test(u)) {
        ++count;
        vector<vector<int64_t>> u2;
        for (const auto& j : u) {
            for (size_t i = 1; i < n; ++i) {
                auto v2 = j;
                int x = v2[i-1];
                int y = v2[i];
                v2[i-1] = x - y;
                v2[i] = x + y;
                u2.push_back(v2);
            }
        }
        u = u2;
    }
    return count;
}

void ret(int count)
{
    cout << "YES" << endl;
    cout << count << endl;
    exit(0);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int64_t> v(n);
    for (auto& i : v) {
        cin >> i;
    }
//    cout << brute(v) << endl;

    int64_t g = v[0];
    for (auto i : v)
        g = gcd(g, i);
    if (g < 0) g = -g;
    if (g > 1) {
        ret(0);
    }

    v.push_back(2);
    int count = 0;
    int seq = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] % 2) {
            ++seq;
        } else {
            if (seq % 2 == 0) {
                count += seq / 2;
            } else {
                count += seq / 2 + 2;
            }
            seq = 0;
        }

    }
    ret(count);

}
