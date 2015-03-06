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
    vector<pair<int, size_t>> q;
    for (size_t i = 0; i < n; ++i) {
        int value;
        cin >> value;
        q.push_back({value, i});
    }
    sort(q.begin(), q.end(), greater<pair<int, size_t>>());

    size_t m;
    cin >> m;
    vector<vector<pair<int, int>>> v(n);
    for (size_t i = 0; i < m; ++i) {
        int a;
        int b;
        int c;
        cin >> a >> b >> c;
        v[b-1].push_back({a, c});
    }
    long long sum = 0;
    for (size_t i = 1; i < n; ++i) {
        int Min = numeric_limits<int>::max();
        for (auto j : v[q[i].second]) {
            Min = min(Min, j.second);
        }
        if (Min == numeric_limits<int>::max()) {
            cout << "-1" << endl;
            return 0;
        }
        sum += Min;
    }
    cout << sum << endl;

    return 0;
}
