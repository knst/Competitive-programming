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

#include <time.h>
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

    srand(time(0));
    int n;
    int start;
    int x;
    cin >> n >> start >> x;

    cout << "? " << start << endl;
    cout.flush();
    int best;
    int best_next;
    cin >> best >> best_next;
    if (best >= x) {
        cout << "! " << start << endl;
        cout.flush();
        return 0;
    }

    cout.flush();
    for (int i = 0; i < 1000; ++i) {
        cout << "? " << (rand() % n) + 1 << endl;
        cout.flush();
        int value;
        int next;
        cin >> value >> next;
        if (value > best && value < x) {
            best = value;
            best_next = next;
        }
    }
    int value = best;
    int next = best_next;
    if (next != -1) {
        do {
            cout << "? " << next << endl;
            cout.flush();
            cin >> value >> next;
            if (value == -1 && next == -1) throw "abc";
            best = value;
            best_next = next;
        } while (best < x && next != -1);
    }
    if (best < x) {
        cout << "! -1" << endl;
    } else {
        cout << "! " << best << endl;
    }

}
