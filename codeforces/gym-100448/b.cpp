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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v)
        cin >> i;
    v.push_back(numeric_limits<int>::min());
    sort(v.begin(), v.end());

    long long result0 = 0;
    long long _resultUp = 0;
    long long _resultDown = 0;
    for (int i = 0; i <= n; ++i) {
        long long _result0;
        long long _resultUp;
        long long _resultDown;
        if (v[i-1] == v[i]) {
            _result0 = result0;
        } else {
            _result0 = numeric_limits<int>::max();
            _resultUp = _resultDown + v[i] - v[i-1];
            _resultDown = min(_result0, _resultUp);
        }
    }
    cout << min(min(result0, _resultDown)<< endl;


    return 0;
}
