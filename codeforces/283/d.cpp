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

size_t Search(vector<int>& sum, size_t start, size_t end, int value) {
    auto it = lower_bound(sum.begin() + start, sum.begin() + end, value);
    return distance(sum.begin(), it);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    vector<int> v(n);
    vector<int> sum1(n, 0);
    vector<int> sum2(n, 0);
    for (size_t i = 0; i < n; ++i) {
        cin >> v[i];
        if (i > 0) {
            sum1[i] = sum1[i-1];
            sum2[i] = sum2[i-1];
        }
        if (v[i] == 1)
            ++sum1[i];
        else
            ++sum2[i];
    }
/*
    for (auto i : sum1)
        cout << i << ' ';
    cout << endl;
    for (auto i : sum2)
        cout << i << ' ';
    cout << endl;
*/
    vector<pair<int,int>> result;
    for (size_t t = 1; t <= n; ++t) {
        bool ok = true;
        size_t last = 0;
        size_t count1 = 0;
        size_t count2 = 0;
        size_t lastWin = 0;
        while (ok && last < n) {
            int value1 = sum1[last];
            int value2 = sum2[last];
            if (v[last] == 1)
                value1--;
            if (v[last] == 2)
                value2--;
            size_t next1 = Search(sum1, last, n, value1 + t);
            size_t next2 = Search(sum2, last, n, value2 + t);
//            cout << "search? " << last << ' ' << next1 << ' ' << next2 << endl;
            size_t next = min(next1, next2);
            if (next == n)
                ok = false;
            else {
                last = next+1;
                if (next == next1) {
                    lastWin = 1;
                    ++count1;
                } else {
                    lastWin = 2;
                    ++count2;
                }
            }
        }
//        cout << t << ": " << last << ' ' << count1 << ':' << count2 << ' ' << lastWin << endl;
        if (last == n) {
            if (lastWin == 1 && count1 > count2)
                result.push_back({count1, t});
            if (lastWin == 2 && count1 < count2)
                result.push_back({count2, t});
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (auto i : result) {
        cout << i.first << ' ' << i.second << endl;
    }


    return 0;
}

