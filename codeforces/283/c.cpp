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
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    size_t m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto& i : v) {
        cin >> i;
    }

    vector<size_t> values(n, 0);
    int count = 0;
    for (size_t i = 0; i < m; ++i) {
        bool ok = true;
        for (size_t j = 1; j < n; ++j) {
            if (v[j][i] < v[j-1][i] && values[j] == values[j-1])
                ok = false;
        }
        if (!ok) {
            ++count;
        } else {
            int shift = 0;
            for (size_t j = 1; j < n; ++j) {
                if (v[j][i] != v[j-1][i] && values[j] + shift == values[j-1])
                    ++shift;
                values[j] += shift;
            }
        }
/*        cout << "values: ";
        for (auto i : values)
            cout << i << ' ';
        cout << endl;
 */   }
    cout << count << endl;


    return 0;
}

