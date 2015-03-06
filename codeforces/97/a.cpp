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
    cin >> n;
    vector<int> v(n);
    for (auto& i : v)
        cin >> i;
    sort(v.begin(), v.end());
    if (v.back() == 1) {
        for (int i = 1; i < n; ++i) {
            cout << "1 ";
        }
        cout << 2 << endl;
        return 0;
    }
    cout << 1;
    for (size_t i = 1; i < n; ++i) {
        cout << " " << v[i-1];

    }
    cout << endl;

    return 0;
}
