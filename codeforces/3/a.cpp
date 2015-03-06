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

    string s1;
    string s2;
    cin >> s1 >> s2;
    char x1 = s1[0];
    char x2 = s2[0];
    char y1 = s1[1];
    char y2 = s2[1];

    string result;
    int count = 0;
    while (y1 != y2 || x1 != x2) {
        if (x1 > x2) {
            result += 'L';
            --x1;
        } else if (x1 < x2) {
            result += 'R';
            ++x1;
        }
        if (y1 > y2) {
            result += 'D';
            y1--;
        } else if (y1 < y2) {
            result += 'U';
            y1++;
        }
        ++count;
        result += '\n';
    }
    cout << count << endl;
    cout << result << endl;

    return 0;
}
