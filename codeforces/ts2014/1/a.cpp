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
    cin >> n >> k;
    vector<int> v;
    map<int, bool> m;
    m[0] = true;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        value = ((value % k) + k) % k;
        map<int, bool> m2;
        for (const auto& j : m) {
            int x = ((j.first + value) % k + k) % k;
            int y = ((j.first - value) % k + k) % k;
            m2[x] = true;
            m2[y] = true;
        }
        m = m2;
    }
    if (m[0])
        cout << "Divisible" << endl;
    else
        cout << "Not divisible" << endl;


    return 0;
}

