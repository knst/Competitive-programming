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

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int k;
    int d;
    cin >> n >> k >> d;
    if (n > 1 && k == 1) {
        cout << -1 << endl;
        return 0;
    }
    int D = (n + k - 1) / k;
    if (D > d) {
        cout << -1 << endl;
        return 0;
    }


    for (int day=  0; day < d; ++day) {
        int index = day;
        for (int i = 0; i < n; ++i) {
            cout << (i + index) / D % k + 1 << ' ';

        }
        cout << endl;
    }

    return 0;
}

