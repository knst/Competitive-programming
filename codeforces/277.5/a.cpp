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
    cin >> n;
    vector<int> v(n);
    for (auto& i : v)
        cin >> i;
    vector<pair<int, int>> result;
    for (int i = 0; i < n-1; ++i) {
        int minimal = v[i];
        int minimalI = i;
        for (int j = i + 1; j < n; ++j) {
            if (minimal > v[j]) {
                minimal = v[j];
                minimalI = j;
            }
        }
        swap(v[minimalI], v[i]);
        result.push_back({i, minimalI});
    }
    cout << result.size() << endl;
    for (auto i : result)
        cout << i.first << ' ' << i.second << endl;


    return 0;
}

