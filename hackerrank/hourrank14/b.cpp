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

int s(vector<int> v) {
    int n = v.size();
    int r = 0;
    for (int i = 0; i < n; ++i) {
        int j = v[i];
        int p = i;
        if (j != p) {
            while (j != p) {
                v[p] = p;
                int np = j;
                int nj = v[j];
                j = nj;
                p = np;
                ++r;
            }
            --r;
        }
    }
    return r;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    size_t n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int,size_t>> t;
    for (auto& i : v) {
        cin >> i;
        --i;
        t.push_back({i, t.size()});
    }
    sort(t.begin(), t.end());
    for(size_t i = 0; i < n; ++i) {
        v[t[i].second] = i;
    }

    vector<int> u = v;
    reverse(u.begin(), u.end());
    int r1 = s(v);
    int r2 = s(u);
    cout << min(r1, r2) << endl;


}
