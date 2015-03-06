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

int main() {
    std::ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    size_t n = s.size();
    int c1 = 0;
    int c0 = 0;
    int x = 0;
    for (auto i : s) {
        if (i == '1')
            c1++;
        if (i == '0')
            c0++;
        if (i == '?')
            x++;
    }
    bool b00 = false;
    bool b01 = false;
    bool b10 = false;
    bool b11 = false;
    if (c1 + x > c0 + 1)
        b11 = true;
    if (c0 + x > c1)
        b00 = true;


    for (int x1 = 0; x1 <= x; ++x1) {
        int x0 = x - x1;
        if (c1 + x1 >= c0 + x0 && c1 + x1 <= c0 + x0 + 1) {
            if (s[n-1] == '1' || (x1 > 0 && s[n-1] == '?'))
                b01 = true;
            if (s[n-1] == '0' || (x0 > 0 && s[n-1] == '?'))
                b10 = true;
        }
    }

    if (b00)
        cout << "00\n";
    if (b01)
        cout << "01\n";
    if (b10)
        cout << "10\n";
    if (b11)
        cout << "11\n";
    return 0;
}
