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

enum Stat {
    Undef = 0,
    Lose = 1,
    Loop = 2,
    Win = 3,
};


std::string Get(Stat i) {
    switch (i) {
        case Stat::Undef: return "Loop";
        case Stat::Win: return "Win";
        case Stat::Lose: return "Lose";
        case Stat::Loop: return "Loop";
    }
    throw "wtf?";
}

bool changed = false;
int process(vector<vector<Stat>>& m, vector<int>& s1, vector<int>& s2, int index, bool type, int n, bool occupied = false) {
    pair<int, bool> position{index, type};
    if (m[type][index] != Stat::Undef)
        return m[type][index];

    if (occupied) {
        for (auto i : s1) {
            if (ret == Stat::Lose) {
                changed = true;
                return m[type][index] = Stat::Win;
            }
        }
        return 0;
    }
    int best = (int)Stat::Undef;
    for (auto i : s1) {
        Stat ret = (Stat)process(m, s2, s1, (index + i) % n, !type, n, true);
        if (ret != Stat::Win) {
            best = 2;
        }
    }
    if (best == 0) {
        changed = true;
        return m[type][index] = Stat::Lose;
    }
    best = 0;

    for (auto i : s1) {
        Stat ret = (Stat)process(m, s2, s1, (index + i) % n, !type, n, true);
        if (ret == Stat::Lose)
            best = 3;
    }
    if (best == 3) {
        changed = true;
        return m[type][index] = Stat::Win;
    }
    return 0;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    int k1;
    cin >> k1;
    vector<int> s1(k1);
    for (auto& i : s1)
        cin >> i;
    int k2;
    cin >> k2;
    vector<int> s2(k2);
    for (auto& i : s2)
        cin >> i;

    // position, Rick/Morty
    // true - s1;
    vector<vector<Stat>> m(2, vector<Stat>(n, Stat::Undef));
    m[true][0] = Stat::Lose;
    m[false][0] = Stat::Lose;


    int iter = 0;
    do {
        changed = false;
        for (size_t i = 0; i < n; ++i) {
            int l1 = (i + n - s1[iter % s1.size()] + iter) % n;
            int l2 = (i + n - s2[iter % s1.size()] + iter) % n;
            if (l1 != 0) process(m, s1, s2, l1, true, n);
            if (l2 != 0) process(m, s2, s1, l2, false, n);
        }
        ++iter;
    } while (changed);

    for (size_t i = 1; i < n; ++i) {
        cout << Get(m[true][i]) << ' ';
    }
    cout << endl;
    for (size_t i = 1; i < n; ++i) {
        cout << Get(m[false][i]) << ' ';
    }
    cout << endl;



}
