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

    int d;
    int sum;
    cin >> d >> sum;
    vector<pair<int,int>> v;
    for (int i = 0; i < d; ++i) {
        int a;
        int b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    vector<int> result(d);
    for (int i = 0; i < d; ++i) {
        result[i] = v[i].first;
        sum -= v[i].first;
    }
    if (sum < 0) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; sum && i < d; ++i) {
        sum += v[i].first;
        result[i] = min(sum, v[i].second);
        sum -= result[i];
    }
    if (sum > 0) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for (auto i : result) {
        cout << i << ' ';
    }


    return 0;
}
