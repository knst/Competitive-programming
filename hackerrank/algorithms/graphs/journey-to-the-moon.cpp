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

int get_parent(vector<int>& v, int i) {
    int value = v[i];
    if (value != i) {
        value = get_parent(v, value);
        v[i] = value;
    }
    return v[i];
}

void merge(vector<int> &v, int i, int j) {
    int a = get_parent(v, i);
    int b = get_parent(v, j);
    if (rand() % 2) {
        v[a] = b;
    } else {
        v[b] = a;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    size_t p;
    cin >> p;
    vector<int> v(n);
    for (size_t i = 0; i < n; ++i) {
        v[i] = i;
    }
    for (size_t i = 0; i < p; ++i) {
        int x;
        int y;
        cin >> x >> y;
        merge(v, x, y);
    }

    map<int, int64_t> counter;
    for (size_t i = 0; i < n; ++i) {
        ++counter[get_parent(v, i)];
    }

    map<int64_t, int64_t> counter2;
    for (auto i : counter) {
        ++counter2[i.second];
    }
    int64_t result = 0;
    for (auto i : counter2) {
        for (auto j : counter2) {
            if (i.first == j.first) {
                result += i.first * j.first * i.second * (j.second - 1);
            } else {
                result += i.first * j.first * i.second * j.second;
            }
        }
    }
    cout << result / 2 << endl;
}
