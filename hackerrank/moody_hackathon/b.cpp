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
    size_t n;
    size_t k;
    cin >> n >> k;
    vector<double> p(n);
    vector<double> x(n);
    vector<double> y(n);
    for (auto& i : p)
        cin >> i;
    for (auto& i : x)
        cin >> i;
    for (auto& i : y)
        cin >> i;
    vector<double> v;
    for (size_t i = 0; i < n; ++i) {
        v.push_back(x[i] * p[i] - y[i] * (1 - p[i]));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    double sum = 0;
    for (size_t i = 0; i < k; ++i) {
        if (v[i] > 0)
            sum += v[i];
    }
    cout.precision(2);
    cout << fixed << sum << endl;
}
