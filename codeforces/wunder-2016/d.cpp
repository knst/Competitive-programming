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
    int64_t x, y;
    cin >> n >> x >> y;
    vector<size_t> mult(n);
    for (size_t i = 1; i < n; ++i) {
        size_t a, b;
        cin >> a >> b;
        mult[a-1]++;
        mult[b-1]++;
    }
    size_t minimal = 0;
    bool first = true;
    for (size_t i = 0; i < n; ++i) {
        if (mult[i] == n - 1)
            minimal ++;
        if (mult[i] == n - 2) {
            if (!first)
                minimal ++;
            else
                first = false;
        }
    }
    if (minimal == n)
        minimal = n-2;
    if (minimal == n-1)
        minimal = n - 2;
    size_t maximal = n - 1;
    for (size_t i = 0; i < n; ++i) {
        if (mult[i] > 2)
            maximal -= mult[i] - 2;
    }
    cerr << minimal << ' ' << maximal << endl;
    int64_t answer = y * n + x * n;
    for (int64_t count = minimal; count <= maximal; ++count) {
        int64_t v1 = count * x + (n - count - 1) * y;
        answer = min(answer, v1);
    }
    cout << answer << endl;
    return 0;
}
