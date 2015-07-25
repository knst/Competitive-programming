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

int main() {
    std::ios_base::sync_with_stdio(false);

    int test;
    cin >> test;
    while (test--) {
        int n;
        int m;
        int p;
        int q;
        int t;
        cin >> n >> m;
        cin >> p >> q;
        cin >> t;
        int minimal = 1000000;
        for (int i = 0; i <= min(n, t / p); ++i) {
            int j = i + (t - i * p) / q;
            if (j > m)
                j = m;
            minimal = min(minimal,
                1 + 
                (n - i + t / p - 1 ) / (t / p) +
                (m - j + t / q - 1 ) / (t / q));
        }

        cout << minimal << endl;
    }
    return 0;
}
