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

const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, -1, 0, 1};

const int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int k;
    cin >> n >> k;
    vector<int> f(n);
    for (auto& i : f) {
        cin >> i;
        --i;
    }

    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());
    int count = 0;
    int last = 0;
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        if (count == k) {
            count = 0;
            result += last * 2;
            last = 0;
        }
        if (f[i] > last) {
            last = f[i];
        }
        ++count;
    }
    result += last * 2;
    cout << result << endl;
    return 0;
}
