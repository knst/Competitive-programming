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

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

long long Abs(long long n) {
    if (n < 0)
        return -n;
    return n;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> values;
    for (auto& i : v) {
        cin >> i;
        values.push_back(i);
    }
    sort(values.begin(), values.end());
    values.resize(distance(values.begin(), unique(values.begin(), values.end())));

    vector<long long> changes(values.size(), 0);
    changes[0] = Abs(v[0] - values[0]);
    for (size_t i = 1; i < changes.size(); ++i) {
        changes[i] = min(changes[i-1], Abs(values[i] - v[0]));
    }
    for (int i = 1; i < n; ++i) {
        vector<long long> changes2(values.size());
        changes2[0] = changes[0] + Abs(v[i] - values[0]);
        for (size_t j = 1; j < values.size(); ++j) {
            changes2[j] = min(changes[j] + Abs(values[j] - v[i]), changes2[j-1]);
        }
        changes = changes2;
    }
    cout << changes[values.size() - 1] << endl;;
    return 0;
}
