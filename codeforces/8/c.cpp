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

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

map<int, pair<int, vector<int>>> M;
pair<int, vector<int>> getMin(const vector<pair<int,int>>& v, vector<bool>& used);

pair<int, vector<int>> Check(const vector<pair<int,int>>& v, vector<bool>& used) {
    int mask = 0;
    for (const auto& i : used) {
        mask = mask * 2 + i;
    }
    if (M.find(mask) == M.end())
        return M[mask] = getMin(v, used);
    else
        return M[mask];
}
pair<int, vector<int>> getMin(const vector<pair<int,int>>& v, vector<bool>& used) {
    int n = v.size();
    int index = 0;
    while (index < n && used[index])
        ++index;
    if (index == n)
        return {0, {}};

    int first = index;
    used[first] = true;
    auto res_1 = Check(v, used);
    int x = v[first].first;
    int y = v[first].second;
    res_1.first += (x * x + y * y) * 2;
    res_1.second.push_back(first+1);
    res_1.second.push_back(0);

    // cerr << "res_1 " << res_1.first << endl;
    for (; index < n; ++index) {
        if (used[index])
            continue;

        int second = index;
        used[second] = true;
        auto res_2 = Check(v, used);
        int x2 = v[second].first;
        int y2 = v[second].second;
        res_2.first += x * x + y* y + x2 * x2 + y2 * y2 + (x - x2) * (x - x2) + (y - y2) * (y - y2);
//        cerr << "res_2 " << res_2.first << endl;
        if (res_2.first < res_1.first) {
            res_2.second.push_back(first + 1);
            res_2.second.push_back(second + 1);
            res_2.second.push_back(0);
            res_1 = res_2;
        }
        used[second] = false;
    }
    used[first] = false;
    return res_1;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int x;
    int y;
    cin >> x >> y;
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        int X;
        int Y;
        cin >> X >> Y;
        X -= x;
        Y -= y;
        v.push_back({X, Y});
    }
    vector<bool> used(n, false);
    pair<int, vector<int>> minimal = getMin(v, used);
    cout << minimal.first << endl;
    cout << "0";
    for (auto i : minimal.second) {
        cout << ' ' << i;
    }
    cout << endl;



    return 0;
}
