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

bool More(const vector<int>& f, const vector<int>& s) {
    long long s1 = 0;
    long long s2 = 0;
    for (auto i : f)
        s1 += i;
    for (auto j : s)
        s2 += j;

    if (s1 > s2) {
        return true;
    }
    if (s1 < s2) {
        return false;
    }
    if (f == s)
        return false;
    for (int i = 0; i < f.size(); ++i) {
        if (f[i] > s[i])
            return true;
        if (f[i] < s[i])
            return false;
    }
    if (f.size() > s.size())
        return true;
    return false;
}
int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> f;
    vector<int> s;
    bool last = false;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        if (value > 0) {
            f.push_back(value);
            last = true;
        } else {
            s.push_back(-value);
            last = false;
        }
    }
    if (More(f, s)) {
        cout << "first" << endl;
        return 0;
    }
    if (More(s, f)) {
        cout << "second" << endl;
        return 0;
    }
    if (last) {
        cout << "first" << endl;
    } else
        cout << "second" << endl;


    return 0;
}

