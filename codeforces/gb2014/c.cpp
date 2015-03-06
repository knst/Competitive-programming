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
    vector<int> w(n);
    for (auto& i : w)
        cin >> i;
    vector<size_t> books(m);
    for (auto& i : books)
        cin >> i;
    long long sum = 0;
    for (size_t i = 0; i < m; ++i) {
        vector<bool> used(n, false);
        for (size_t j = i - 1; j < m && books[j] != books[i]; --j) {
            size_t index = books[j]-1;
            if (!used[index])
                sum += w[index];
            used[index] = true;
        }
    }
    cout << sum << endl;


    return 0;
}

