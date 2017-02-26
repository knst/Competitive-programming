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

char Do(char p, char q, const string& op) {
    int x = p - '0';
    int y = q - '0';
    int z = 0;
    if (op == "AND") {
        z = x & y;
    }
    if (op == "OR") {
        z = x | y;
    }
    if (op == "XOR") {
        z = x ^ y;
    }
    return z + '0';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    size_t m;
    cin >> n >> m;
    map<string, string> values0;
    map<string, string> values1;
    string e0;
    string e1;
    for (size_t i = 0;i < m; ++i) {
        e0 += '0';
        e1 += '1';
    }

    values0["?"] = e0;
    values1["?"] = e1;

    vector<int> sum0(m);
    vector<int> sum1(m);
    for (size_t iter = 0; iter < n; ++iter) {
        string a;
        string eq;
        string p;
        cin >> a >> eq >> p;
        if (p[0] == '0' || p[0] == '1') {
            values0[a] = p;
            values1[a] = p;
        } else {
            string op;
            string q;
            cin >> op >> q;
            string v0;
            string v1;
            string p0 = values0[p];
            string q0 = values0[q];
            string p1 = values1[p];
            string q1 = values1[q];
            for (size_t i = 0; i < m; ++i) {
                int x0 = Do(p0[i], q0[i], op);
                int x1 = Do(p1[i], q1[i], op);
                if (x0 < x1) {
                    sum1[i]++;
                }
                if (x0 > x1) {
                    sum0[i]++;
                }
                v0 += x0;
                v1 += x1;
            }
            values0[a] = v0;
            values1[a] = v1;
        }
    }
    string r0;
    string r1;
    for (size_t i = 0; i < m; ++i) {
        if (sum0[i] < sum1[i]) {
            r0 += '0';
            r1 += '1';
        } else if (sum0[i] > sum1[i]) {
            r0 += '1';
            r1 += '0';
        } else {
            r0 += '0';
            r1 += '0';
        }
    }
    cout << r0 << endl;
    cout << r1 << endl;

}
