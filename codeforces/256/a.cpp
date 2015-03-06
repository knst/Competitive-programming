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
#include <unordered_map>
#include <unordered_set>
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

    int a[3];
    int b[3];
    int A = 0;
    int B = 0;
    for (auto i : {0,1,2}) {
        cin >> a[i];
        A += a[i];
    }
    for (auto i : {0,1,2}) {
        cin >> b[i];
        B += b[i];
    }
    int n;
    cin >> n;
    int k = 0;
    k += (A + 4) / 5;
    k += (B + 9) / 10;
    if (k > n)
        cout << "NO";
    else
        cout << "YES";
    cout << endl;

    return 0;
}

