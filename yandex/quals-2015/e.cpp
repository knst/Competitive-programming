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

    long long n;
    long long m;
    long long l;
    long long r;

    cin >> n >> m >> l >> r;

    vector<long long> a;
    vector<long long> b;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            a.push_back(i);
            if (i * i != n)
                a.push_back(n / i);
        }
    }
    for (int i = 1; i * i <= m; ++i) {
        if (m % i == 0) {
            b.push_back(i);
            if (i * i != m)
                b.push_back(m / i);
        }
    }
    size_t count = 0;
    for (auto i : a)
        for (auto j : b) {
            long long s = i * j;
            if (s > r || s < l)
                continue;
            ++count;


        }
    cout << count << endl;
    return 0;
}
