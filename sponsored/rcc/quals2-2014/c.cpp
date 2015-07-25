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

void test(vector<long long> &areas, long long a, long long b) {
    if (a <= 0 || b <= 0)
        return;
    if (a < b) {
        swap(a, b);
    }
    long long x = (b-1) * (b ) / 2;
    long long y = (a - b) * (b);
    if (x > 0) {
        areas.push_back(x);
    }
    if (x + y > 0) {
        areas.push_back(x + y);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int _test;
    cin >> _test;
    while (_test--) {
        long long n;
        long long m;
        cin >> n >> m;
        long long x;
        long long y;
        cin >> x >> y;
        vector<long long> areas;
       
        test(areas, x-1, y-1);
        test(areas, n+1-x-1, y-1);
        test(areas, x-1, m+1-y-1);
        test(areas, n+1-x-1, m+1-y-1);
        sort(areas.begin(), areas.end());
        cout << areas.size();
        for (size_t i = 0; i < areas.size(); ++i) {
            cout << ' ' << areas[i];
        }
        cout << endl;
        
    }
    return 0;
}
