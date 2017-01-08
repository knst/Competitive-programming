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

vector<string> f(4);
bool test(vector<pair<int,int>> v) {
    if (v.size() == 4) {
        bool ok = test({v[0], v[1], v[2]});
        ok |= test({v[1], v[2], v[3]});
        return ok;
    }
    int xcount = 0;
    int ecount = 0;
    for (auto& i : v) {
        if (f[i.first][i.second] == 'x') {
            xcount++;
        }
        if (f[i.first][i.second] == '.') {
            ecount++;
        }
        i.first = 3 - i.first;
    }
    if (xcount == 2 && ecount == 1)
        return true;
    xcount = ecount = 0;
    for (auto i : v) {
        if (f[i.first][i.second] == 'x') {
            xcount++;
        }
        if (f[i.first][i.second] == '.') {
            ecount++;
        }
    }
    if (xcount == 2 && ecount == 1)
        return true;
    return false;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (auto& i : f)
        cin >> i;

    bool ok = false;
    for (int x = 0; x < 4; ++x) {
        ok |= test({{x,0}, {x, 1}, {x, 2}, {x, 3}});
        ok |= test({{0,x}, {1, x}, {2, x}, {3, x}});
        ok |= test({{0,0}, {1, 1}, {2, 2}});
        ok |= test({{1,0}, {2, 1}, {3, 2}});
        ok |= test({{0,1}, {1, 2}, {2, 3}});
        ok |= test({{1,1}, {2, 2}, {3, 3}});
    }
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
