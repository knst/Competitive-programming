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

    int m;
    int s;
    cin >> m >> s;
    if (m > 1 && s == 0) {
        cout << "-1 -1" << endl;
        return 0;
    }
    if (m * 9 < s) {
        cout << "-1 -1" << endl;
        return 0;
    }
    int S = s;
    string minimal;
    while (s > 9) {
        minimal = '9' + minimal;
        s -= 9;
    }
    if (minimal.size() + 1 < m && s > 1) {
        minimal = static_cast<char>('0' + s-1) + minimal;
        s = 1;
    }
    while (minimal.size() + 1 < m)
        minimal = '0' + minimal;
    minimal = static_cast<char>(s + '0') + minimal;

    string maximal;
    while (S > 9) {
        maximal = maximal + '9';
        S -= 9;
    }
    if (S)
        maximal = maximal + static_cast<char>(S + '0');
    while (maximal.size() < m)
        maximal = maximal + '0';

    cout << minimal << ' ' << maximal << endl;

    return 0;
}

