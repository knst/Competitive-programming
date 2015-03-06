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
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    double p;
    size_t t;
    cin >> n >> p >> t;
    vector<double> v(n + 1, 0);
    v[0] = 1;
    for (size_t i = 0; i < t; ++i) {
        vector<double> vn(n + 1, 0);
        vn[0] = v[0] * (1 - p);
        for (size_t j = 1; j <= n; ++j) {
            vn[j] += v[j-1] * p;
            if (j != n)
                vn[j] += v[j] * (1 - p);
            else
                vn[j] += v[j];
        }
        v = vn;
    }
    double result = 0;
    for (size_t i = 1; i <= n; ++i)
        result += v[i] * i;
    cout.precision(10);
    cout << fixed << result  << endl;

    return 0;
}

