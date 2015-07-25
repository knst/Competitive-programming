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

    long long test;
    cin >> test;
    while (test--) {
        long long n;
        long long m;
        long long k;
        cin >> n >> m;
        cin >> k;
        if (n > 2 && m > 2 && (n + m - 2) * 3 - 6 == k) {
            cout << "1 1 2 2 3 3\n";
        }else if (n > 1 && m > 2 && 3 * n + 2 * m - 6 - 3 == k) {
            cout << "1 1 2 2 1 3\n";
        }else if (n > 2 && m > 1 && 2 * n + 3 * m -6  - 3== k) {
            cout << "1 1 2 2 3 1\n";
        }else if (n > 1 && m > 1 && 2 * n + 2 * m - 6 - 1 == k) {
            cout << "1 1 2 1 1 2\n";
        }else if (n > 2 && 3 * m + n - 6 == k) {
            cout << "1 1 2 1 3 1\n";
        }else if (m > 2 && 3 * n + m - 6 == k) {
            cout << "1 1 1 2 1 3\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}
