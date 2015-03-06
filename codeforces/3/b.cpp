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

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int V;
    cin >> n >> V;
    vector<pair<int,int>> v1;
    vector<pair<int,int>> v2;
    for (int i = 0; i < n; ++i) {
        int type;
        int m;
        cin >> type >> m;
        if (type == 1) {
            v1.push_back({m, i});
        } else
            v2.push_back({m, i});
    }
    long long sum = 0;
    vector<int> result;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    int last1 = -1;
    pair<int,int> l1;
    while (V > 1 && (!v1.empty() || !v2.empty())) {
        if (v2.empty() || (!v1.empty() && v1.back().first * 2 > v2.back().first)) {
            last1 = result.size();
            l1 = v1.back();
            result.push_back(l1.second);
            sum += l1.first;
            v1.pop_back();
            --V;
        } else {
            auto l2 = v2.back();
            result.push_back(l2.second);
            sum += l2.first;
            v2.pop_back();
            V -= 2;
        }
    }
    if (last1 != -1) {
        v1.push_back(l1);
        sum -= l1.first;
        V++;
    }
    vector<int> result2;
    for (size_t i = 0; i < result.size(); ++i) {
        if (i != last1)
            result2.push_back(result[i]);
    }
    result = result2;

    reverse(v1.begin(), v1.end());
    reverse(v2.begin(), v2.end());

    vector<pair<int, int>> v;
    for (size_t i =0; i < 2 && i < v1.size(); ++i)
        v.push_back(v1[i]);
    for (size_t i = v1.size(); i < 2; ++i)
        v.push_back({-1, -1});

    if (!v2.empty())
        v.push_back(v2[0]);
    else
        v.push_back({-1, -1});

    vector<int> result_maximal;
    int p_maximal = -1;
    for (unsigned char mask = 0; mask < 8; ++mask) {
        int V_t = V;
        int p = 0;
        vector<int> result_p;
        if ((mask & 0x1) && V_t > 0) {
            V_t--;
            result_p.push_back(v[0].second);
            p += v[0].first;
        }
        if ((mask & 0x2) && V_t > 0) {
            V_t--;
            result_p.push_back(v[1].second);
            p += v[1].first;
        }
        if ((mask & 0x4) && V_t > 1) {
            V_t -= 2;
            result_p.push_back(v[2].second);
            p += v[2].first;
        }
        if (p > p_maximal) {
            p_maximal = p;
            result_maximal = result_p;
        }
    }

    if (p_maximal <= 0) {
        p_maximal = 0;
        result_maximal.resize(0);
    }

    for (const auto& i : result_maximal)
        result.push_back(i);
    sum += p_maximal;


    cout << sum << endl;
    for (const auto& i : result)
        cout << i+1 << ' ';
    cout << endl;
    return 0;
}
