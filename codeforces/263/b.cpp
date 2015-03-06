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
    string s;
    cin >> s;

    vector<long long> V(256, 0);
    for (auto i : s) {
        V[i]++;
    }

    sort(V.begin(), V.end());
    reverse(V.begin(), V.end());
    long long count = k;
    long long result = 0;
    for (int i = 0; count > 0 && i < 256; ++i) {
        long long r = min(count, V[i]);
        result += r * r;
        count -= V[i];
    }

    cout << result << endl;


    return 0;
}

