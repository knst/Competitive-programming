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
    int p;
    cin >> n >> p;
    string s;
    cin >> s;

    bool fail = false;

    int index = n-1;
    bool over = true;
    while (over && index >= 0) {
        while (s[index] - 'a' != p &&
                (
                    over ||
                    (index > 0 && s[index] == s[index-1]) ||
                    (index > 1 && s[index] == s[index-2])
                )
            ) {
            s[index]++;
            over = false;
        }
        if (s[index] - 'a' == p) {
            s[index] = 'a';
            --index;
            over = true;
        }
    }
    if (index < 0) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = index + 1; i < n; ++i) {
        s[i] = 'a';
        while (s[i] < 'a' + p && ((i > 0 && s[i] == s[i-1]) || (i > 1 && s[i] == s[i-2])))
            s[i]++;
        if (s[i] == 'a' + p) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << s << endl;



    return 0;
}

