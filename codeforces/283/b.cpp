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

    int n;
    cin >> n;
    string s;
    cin >> s;

    string minimal = s;
    for (int i = 0;i < n; ++i) {
        string s2 = s;
        for (int k = 0; k < 10; ++k) {
            for (size_t j = 0;j < s.size(); ++j) {
                s2[j] = (s[(j + i) % n] + k - '0') % 10 + '0';
            }
            if (s2 < minimal)
                minimal = s2;
        }
    }
    cout << minimal << endl;

    return 0;
}

