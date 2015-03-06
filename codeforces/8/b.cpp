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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int main() {
    std::ios_base::sync_with_stdio(false);

    string s;
    cin >> s;

    map<pair<int, int>, int> m;
    m[{0,0}] = 1;
    int x = 0;
    int y = 0;
    int n = s.size();
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        switch(c) {
            case 'U':
                ++y;
                break;
            case 'R':
                ++x;
                break;
            case 'D':
                --y;
                break;
            case 'L':
                --x;
                break;
        }
        if (m[{x,y}])
            ok = false;
        for (int j = 0; j < 4; ++j) {
            int x1 = x + dx[j];
            int y1 = y + dy[j];
            int step = m[{x1,y1}];
            if (step && step < i + 1)
                ok = false;
        }
        m[{x, y}] = i + 2;
    }
    if (ok) {
        cout << "OK" << endl;
    } else
        cout << "BUG" << endl;

    return 0;
}
