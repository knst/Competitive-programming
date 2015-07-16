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

namespace std {
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
};

void solve(long long n) {
    if (n == 1 || n == 3 || n == 4 || n == 6 || n == 9) {
        cout << "0" << endl;
        return;
    }
    if (n == 2 || n == 5 || n == 7 || n == 8 || n == 12 || n == 10 || n == 15 || n == 18) {
        cout << "1" << endl;
        return;
    }

    int count = 0;
    if (n % 3 == 2)
        count = 0;
    if (n % 3 == 1)
        count = 1;
    if (n % 3 == 0)
        count = 2;
    long long sum = 2;
    int count2 = 0;
    while (sum + count2 * 3 < n) {
        sum += count2 * 3;
        ++count2;
    }
    cout << (count2 +1 - count) / 3 << endl;
//    cout << n << ' ' << count2 << ' ' << count << endl;



}
int main() {
    std::ios_base::sync_with_stdio(false);

    long long n;
    cin >>n;
    solve(n);
    return 0;
    for (int i = 1; i < 100; ++i) {
        cout << i << ' ';
        solve(i);
    }

    return 0;
}

