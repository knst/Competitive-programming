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
//test speed
/*
namespace std {
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}; */
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
    cin >> n;
    map<string, int> m;
    vector<pair<string,int>> v;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        int score;
        cin >> score;
        v.push_back({s, score});
        m[s] += score;
    }
    int maximal = -1;
    string maximalName = "";
    int count = 0;
    for (const auto& i : m) {
        if (i.second > maximal) {
            maximal = i.second;
            maximalName = i.first;
            count = 0;
        }
        if (i.second == maximal)
            ++count;
    }
    if (count > 1) {
        map<string, int> m2;
        for (const auto &i : v) {
            m2[i.first] += i.second;
            if (m2[i.first] >= maximal && m[i.first] == maximal) {
                cout << i.first << endl;
                return 0;
            }
        }
    } else {
        cout << maximalName << endl;
    }

    return 0;
}
