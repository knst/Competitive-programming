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

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int test = 1; test <= t; ++test) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int maximal = -1;
        int maximalCount = 0;
        for (int i = 0; i < s.size(); ++i) {
            int count = 0;
            for (int j = 0; j < s.size(); ++j) {
                if (s[i] == 'R' && s[j] == 'S')
                    ++count;
                if (s[i] == 'S' && s[j] == 'P')
                    ++count;
                if (s[i] == 'P' && s[j] == 'R')
                    ++count;
            }
            if (count > maximal) {
                maximal = count;
                maximalCount = 0;
            }
            if (count == maximal)
                ++maximalCount;
        }
        cout << "Case #" << test << ":" << endl;
        cout << maximalCount << endl;
    }
    return 0;
}
