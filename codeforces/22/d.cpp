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

    size_t n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for (auto& i : v) {
        cin >> i.first >> i.second;
        if (i.first > i.second)
            swap(i.first, i.second);
    }


    vector<bool> mask(n, false);
    vector<int> result;
    for (int x = -10000; x <= 10000; ++x) {
        bool need = false;
        for (size_t i = 0; i < n; ++i) {
            if (!mask[i] && v[i].second == x)
                need = true;
        }
        if (need) {
            result.push_back(x);
            for (size_t i = 0; i < n; ++i) {
                if (v[i].first <= x && v[i].second >= x)
                    mask[i] = true;
            }
        }
    }

    cout << result.size() << endl;
    for (auto i : result)
        cout << i << ' ';
    cout << endl;

    return 0;
}
