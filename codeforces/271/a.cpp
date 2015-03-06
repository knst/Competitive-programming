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

    vector<string> ss = {"qwertyuiop", "asdfghjkl;", "zxcvbnm,./"};
    char c;
    cin >> c;
    string s;
    cin >> s;
    int diff = c == 'R'? -1 : 1;
    for (auto i : s) {
        for (auto k : ss)
            for (size_t j = 0; j < k.size(); ++j) {
                if (i == k[j])
                    cout << k[j+diff];
        }
    }
    cout << endl;
    return 0;
}

