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
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);


    size_t n;
    size_t k;
    cin >> n >> k;
    vector<int64_t> v(n);
    for (auto& i : v)
        cin >> i;

    sort(v.begin(), v.end());

    int64_t sum = 0;
    for (size_t i = 1; i < n; ++i)
        sum += v[i] - v[i-1];

    size_t d = n / k;
    size_t d1 = d + 1;
    size_t d_c = k - n % k;
    size_t d1_c = n % k;

    vector<int64_t> D(d1_c + 1);
    for (size_t i = 1; i < k; ++i) {
        vector<int64_t> D2(d1_c + 1);
        D2[0] = D[0] + v[i * d] - v[i * d - 1];
        for (size_t j = 1; j <= min(d1_c, i); ++j) {
            int64_t s1 = D[j] + v[i * d + j] - v[i * d + j - 1];
            int64_t s2 = D[j-1] + v[i * d + j] - v[i * d + j - 1];
            D2[j] = max(s1, s2);
        }
        D = D2;
    }
    if (d1_c && D[d1_c - 1] > D[d1_c])
        D[d1_c] = D[d1_c - 1];
    cout << sum - D[d1_c] << endl;


    return 0;
}
