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

    double h;
    double l;
    double h1, h2;
    double l1, l2;
    cin >> h >> l;
    cin >> h1 >> h2;
    cin >> l1 >> l2;

    double alpha = const_pi() / 2 - atan(h / l);
    double beta = const_pi() / 2 - atan(l / h);
    double sum = 0;
    sum += alpha * (l1 + l2) / const_pi();
    sum += beta * (h1 + h2) / const_pi();
    cout.precision(15);
    cout << fixed << sum << endl;


    return 0;
}
