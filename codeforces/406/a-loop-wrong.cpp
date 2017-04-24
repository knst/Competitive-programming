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

enum class Stat {
    Undef = 0,
    Lose = 1,
    Loop = 2,
    Win = 3,
};


std::string Get(Stat i) {
    switch (i) {
        case Stat::Undef: throw "can't be 0";
        case Stat::Win: return "Win";
        case Stat::Lose: return "Lose";
        case Stat::Loop: return "Loop";
    }
    throw "wtf?";
}


int process(map<pair<int, bool>, Stat>& m, vector<int>& s1, vector<int>& s2, int index, bool type, int n) {
    pair<int, bool> position{index, type};
//    cerr << index << ' '<< type << endl;
    if (m.find(position) != m.end())
        return static_cast<int>(m[position]);
    m[position] = Stat::Loop; // May be it's incorrect
    int best = (int)Stat::Lose;
    for (auto i : s1) {
        Stat ret = (Stat)process(m, s2, s1, (index + i) % n, !type, n);
        if (ret == Stat::Lose)
            best = 3;
        if (ret == Stat::Loop)
            best = max(2, best);
    }
    m[position] = static_cast<Stat>(best);
    return best;
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
    map<pair<int, bool>, Stat> m;
    m[{0, true}] = Stat::Lose;
    m[{0, false}] = Stat::Lose;


    for (size_t i = 1; i < n; ++i) {
        process(m, s1, s2, i, true, n);
        process(m, s2, s1, i, false, n);
    }

    for (size_t i = 1; i < n; ++i) {
        cout << Get(m[{i, true}]) << ' ';
    }
    cout << endl;
    for (size_t i = 1; i < n; ++i) {
        cout << Get(m[{i, false}]) << ' ';
    }
    cout << endl;



}
