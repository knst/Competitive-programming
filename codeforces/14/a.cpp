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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto&i : v)
        cin >> i;
    int starti = n;
    int endi = 0;
    int startj = m;
    int endj = 0;
    for (int i = 0; i< n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] != '*') {
                continue;
            }
            endi = max(endi, i);
            starti = min(starti, i);
            endj = max(endj, j);
            startj = min(startj, j);
        }
    }

    for (int i=  starti; i <=endi; ++i) {
        for (int j = startj; j <= endj; ++j) {
            cout << v[i][j];
        }
        cout << endl;
    }

    return 0;
}
