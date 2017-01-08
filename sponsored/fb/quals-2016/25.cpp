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

void W() {
    cout << "white" << endl;
}
void B() {
    cout << "black" << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t t;
    cin >> t;
    for (int T = 1; T <= t; ++T) {
        double p;
        double x;
        double y;
        cin >> p >> x >> y;
        cout << "Case #" << T << ": ";
        x -= 50;
        y -= 50;

        /*
        if (x == 0 && y == 0) {
            if (p == 0) {
                cout << 1 << endl;
                W();
            } else {
                cout << 2 << endl;
                B();
            }
        } else
            */
        if (x * x + y * y > 50 * 50) {
//            cout << x * x << ' ' << y * y << ' ' << x * x + y * y << endl;
 //               cout << 3 << endl;
            W();
        } else {
            if (atan2(y, x) < p / 100 * 2 * const_pi()) {
  //              cout << 4 << endl;
                B();
            } else {
   //             cout << 5 << endl;
                W();
            }
        }
    }
}
