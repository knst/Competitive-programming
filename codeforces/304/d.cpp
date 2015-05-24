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

    size_t M = 5000 * 1000;
    vector<bool> prime(M + 1, true);
    vector<int> sum(M + 1, 1);
    prime[0] = false;
    prime[1] = false;
    for (uint64_t i = 2; i <= M; ++i) {
        if (prime[i])
            for (uint64_t j = i * i; j <= M; j += i) {
                prime[j] = false;
                sum[j] = sum[j / i] + 1;
            }
    }
    for (size_t i = 2; i < sum.size(); ++i) {
        sum[i] += sum[i-1];
    }

    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        int a;
        int b;
        cin >> a >> b;
        cout << sum[a] - sum[b] << '\n';
    }

    return 0;
}
