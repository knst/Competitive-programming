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

long long get(long long _a, long long _b, long long m) {
    long long a = _a % m;
    long long b = _b % m;
    long long A = _a - a;
    long long B = _b - b;
    long long r = 0;
    r += A / m * B;
    r += A / m * b;
    r += B / m * a;
    r += a * b / m;
    return r;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    long long x;
    long long y;
    cin >> x >> y;
    for (int i = 0; i < n; ++i) {
        long long ai;
        cin >> ai;
        long long r = get(x * y, ai, (x + y));

        if (r / y + r / x >= ai) {
            cout << "Both" << endl;
        } else {
            long long rx = x- r % x;
            long long ry = y- r % y;
/*            if (rx == x)
                rx = 0;
            if (ry == y)
                ry = 0;
 */           long long Rx = r + rx;
            long long Ry = r + ry;
            if (Rx < Ry && Rx / x + Rx / y >= ai) {
                cout << "Vova" << endl;
            } else if (Ry < Rx && Ry / x + Ry / y >= ai) {
                cout << "Vanya" << endl;
            } else if (Ry == Rx) {
                cout << "Both" << endl;
            } else if (Rx > Ry && Rx / x + Rx / y >= ai) {
                cout << "Vova" << endl;
            } else if (Ry > Rx && Ry / x + Ry/ y >= ai) {
                cout << "Vanya" << endl;
            } else {
                cout << "Both" << endl;
            }
        }

    }

    return 0;
}

