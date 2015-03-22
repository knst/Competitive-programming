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

const int DayLen = 86400;

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    size_t m;
    size_t t;
    cin >> n >> m >> t;
    vector<int> v;
    for (size_t i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int result = s[0] - '0';
        result = result * 10 + s[1] - '0';
        result = result * 6 + s[3] - '0';
        result = result * 10 + s[4] - '0';
        result = result * 6 + s[6] - '0';
        result = result * 10 + s[7] - '0';
        v.push_back(result);
    }

    sort(v.begin(), v.end());

    vector<size_t> mask(DayLen);
    for (auto i : v)
        mask[i]++;

    bool ok = false;

    vector<int> result;
    queue<int> used;

    size_t last = 0;
    for (size_t i = 0; i < DayLen; ++i) {
        if (i >= t) {
            for (size_t j = 0; j < mask[i - t]; ++j)
                used.pop();
        }
        for (size_t j = 0; j < mask[i]; ++j) {
            if (used.empty() || (last - used.front() + 1 < m))
                ++last;
            result.push_back(last);
            used.push(last);
            if (last - used.front() + 1 == m)
                ok = true;
        }
    }

    if (!ok) {
        cout << "No solution" << endl;
        return 0;
    }

    cout << last << endl;
    for (auto i : result)
        cout << i << '\n';
    cout.flush();

    return 0;
}
