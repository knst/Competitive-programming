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

void print(const std::vector<char>& buf) {

    for (auto& i : buf) {
        if (i) {
            cout << i;
        } else {
            cout << 'a';
        }
    }
    cout << endl;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int b = 0;
    vector<string> t(n);
    vector<pair<int, pair<int, int>>> q;
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
        int l = t[i].size();
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            --x;
            b = max<int>(b, x + l);
            q.push_back({x, {l, i}});
        }
    }
    sort(q.begin(), q.end());
    vector<char> buf(b);
    int last = 0;
    for (auto i : q) {
//        cout << i.first << ' ' << i.second.first << ' ' << i.second.second << endl;
        while (last < i.first) {
            ++last;
        }
        while (last < i.first + i.second.first) {
            buf[last] = t[i.second.second][last - i.first];
            ++last;
        }
    }
    print(buf);

}
