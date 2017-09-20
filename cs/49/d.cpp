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

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    int a;
    cin >> t >> a;
    vector<vector<double>> v(t, vector<double>(a));
    for (auto& i : v) {
        for (auto& j : i) {
            double x;
            cin >> x;
            j = x / 100.;
        }
    }
    v.push_back(vector<double>(a, 1));

    vector<double> probs(t + 1);
    vector<double> probs2(t + 1);
    probs[t - 1] = 1;
    probs[t] = 1;
    double answer = 0;
    int l = min(0, t - 2);
    int r = t;
    for (int tests = 0; tests < 1000000; ++tests) {
        double sum = 0;
        int next_a = tests % a;
        int nl = min(0, t - 2);
        int nr = 0;
        for (int i = l; i < r; ++i) {
            probs2[i] = probs[i] * v[i][next_a] + probs[i + 1] * (1 - v[i + 1][next_a]);
            if (probs2[i] > 1e-12) {
                nl = min(nl, i - 1);
                nr = max(nr, i + 1);
            }
//            if (probs2[i] != 0 && probs2[i] < 0.999) cout << probs2[i] << endl;
            sum += probs[i];
        }
        if (nl < 0) nl = 0;
        if (nr > t) nr = t;
//        l = nl;
 //       r = nr;
        answer += sum;
        swap(probs, probs2);
    }
    cout.precision(9);
    cout << fixed << answer << endl;

}
