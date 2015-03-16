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
    vector<string> namelist(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> namelist[i];
    }

    map<string, int> points;
    map<string, int> diffs;
    map<string, int> pulled;

    for (size_t i = 0; i < n * (n - 1) / 2; ++i) {
        string names;
        cin >> names;
        bool type = false;
        string name1;
        string name2;
        for (auto j : names) {
            if (j == '-') {
                type = true;
            } else {
                if (!type) {
                    name1 = name1 + j;
                } else
                    name2 = name2 + j;
            }
        }
        string scores;
        cin >> scores;
        int score1 = 0;
        int score2 = 0;
        for (auto j : scores) {
            if (j == ':') {
                type = false;
            } else {
                if (type) {
                    score1 = score1 * 10 + (j - '0');
                } else
                    score2 = score2 * 10 + (j - '0');
            }
        }
        cerr << names << ' ' << scores << endl;
        cerr << name1 << ' ' << name2 << ' ' << score1 << ' ' << score2 << endl;
        if (score1 > score2) {
            points[name1] += 3;
        } else if (score1 == score2) {
            points[name1]++;
            points[name2]++;
        } else {
            points[name2] += 3;
        }
        diffs[name1] += score1 - score2;
        diffs[name2] += score2 - score1;
        pulled[name1] += score1;
        pulled[name2] += score2;
    }

    vector<pair<int, pair<int, pair<int, string>>>> v;
    for (auto i : namelist) {
        v.push_back({points[i], {diffs[i], {pulled[i], i}}});
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (size_t i = 0; i < n; ++i) {
        cerr << i << ' ' << v[i].second.second.second << ' ' << v[i].first << ' ' << v[i].second.first << ' ' << v[i].second.second.first << endl;
    }
    vector<string> result;
    for (size_t i = 0; i < n / 2; ++i) {
        result.push_back(v[i].second.second.second);
    }
    sort(result.begin(), result.end());
    for (auto i : result)
        cout << i << endl;
    return 0;
}
