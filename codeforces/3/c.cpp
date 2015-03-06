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
//test speed
/*
namespace std {
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}; */
namespace std {
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
};

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

char check(char c1, char c2, char c3) {
    if (c1 == c2 && c1 == c3)
        return c1;
    return 0;
}

bool is(const set<int>& s, int index) {
    if (s.find(index) == s.end())
        return false;
    return true;
}

bool checkIllegal(const set<int>& won) {
    int count1 = 0;
    count1 += is(won, 0);
    count1 += is(won, 1);
    count1 += is(won, 2);

    if (count1 > 1)
        return true;
    count1 = 0;
    count1 += is(won, 3);
    count1 += is(won, 4);
    count1 += is(won, 5);
    if (count1 > 1)
        return true;
    return false;
}
int main() {
    std::ios_base::sync_with_stdio(false);

    char f[3][3];
    int countX = 0;
    int countY = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> f[i][j];
            if (f[i][j] == 'X')
                countX++;
            if (f[i][j] == '0')
                countY++;
        }

    }

    set<int> wonX;
    set<int> wonY;
    for (int i = 0; i < 3; ++i) {
        if (check(f[i][0], f[i][1], f[i][2]) == 'X')
            wonX.insert(i);

        if (check(f[0][i], f[1][i], f[2][i]) == 'X')
            wonX.insert(i + 3);

        if (check(f[i][0], f[i][1], f[i][2]) == '0')
            wonY.insert(i);

        if (check(f[0][i], f[1][i], f[2][i]) == '0')
            wonY.insert(i + 3);
    }
    if (check(f[0][0], f[1][1], f[2][2]) == 'X')
        wonX.insert(10);
    if (check(f[0][2], f[1][1], f[2][0]) == 'X')
        wonX.insert(11);
    if (check(f[0][0], f[1][1], f[2][2]) == '0')
        wonY.insert(10);
    if (check(f[0][2], f[1][1], f[2][0]) == '0')
        wonY.insert(11);

    bool illegal = false;
    if (!wonX.empty() && !wonY.empty()) {
        illegal = true;
    }

    if (checkIllegal(wonX))
        illegal = true;
    if (checkIllegal(wonY))
        illegal = true;


    if (countX > countY + 1)
        illegal = true;
    if (countX == countY && !wonX.empty())
        illegal = true;
    if (countX == countY + 1 && !wonY.empty())
        illegal = true;
    if (countX < countY)
        illegal = true;
    if (illegal) {
        cout << "illegal" << endl;
        return 0;
    }
    if (!wonX.empty()) {
        cout << "the first player won" << endl;
        return 0;
    }
    if (!wonY.empty()) {
        cout << "the second player won" << endl;
        return 0;
    }
    if (countX + countY == 9) {
        cout << "draw" << endl;
        return 0;
    }
    if (countY < countX) {
        cout << "second" << endl;
        return 0;
    }
    cout << "first" << endl;


    return 0;
}
