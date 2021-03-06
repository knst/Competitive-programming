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

    size_t m;
    cin >> m;
    vector<pair<int,int>> roads(m);
    vector<int> counts(m);
    for (auto& i : roads)
        cin >> i.first >> i.second;
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; ++i) {
        size_t r;
        cin >> r;
        --r;
        counts[r]++;
    }
    for (size_t i = 0; i < m; ++i) {
        if (counts[i] < roads[i].first)
            cout << "Green" << endl;
        else if (counts[i] > roads[i].second)
            cout << "Red" << endl;
        else
            cout << "Orange" << endl;
    }



    return 0;
}
