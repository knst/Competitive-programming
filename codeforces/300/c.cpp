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
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    const string IMP = "IMPOSSIBLE";
    size_t n;
    size_t m;
    cin >> n >> m;
    vector<pair<int,int>> values(m);
    for (auto& i : values)
        cin >> i.first >> i.second;

    int maximal = -1;
    for (size_t i = 1; i < values.size(); ++i) {
        int times = values[i].first - values[i - 1].first;
        int deltas = values[i].second - values[i - 1].second;
        if (times < 0)
            times = -times;
        if (deltas < 0)
            deltas = -deltas;
        if (times < deltas) {
            cout << IMP << endl;
            return 0;
        }
        maximal = max(maximal, (times - deltas) / 2 + values[i].second);
        maximal = max(maximal, (times - deltas) / 2 + values[i-1].second);
    }
    maximal = max(maximal, static_cast<int>(values[0].second + values[0].first - 1));
    maximal = max(maximal, static_cast<int>(values[m-1].second + n - values[m-1].first));
    cout << maximal << endl;
    return 0;
}
