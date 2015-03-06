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

    int a;
    int m;
    cin >> a >> m;
    set<int> values;
    while (a % m != 0) {
        if (values.find(a) == values.end()) {
            values.insert(a);
        } else
            break;
        a = (a + a % m) % m;
    }
    if (a % m == 0) {
        cout << "Yes" << endl;
    } else
        cout << "No" << endl;

    return 0;
}

