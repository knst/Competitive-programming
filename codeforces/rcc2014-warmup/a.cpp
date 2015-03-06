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
    int k;
    cin >> n >> k;
    if (k > (n - 1) / 2) {
        cout << -1 << endl;
        return 0;
    }
    int count = n * k;
    cout << count << endl;
    for (int s = 1; count && s < n; ++s) {
        for (int i = 0; i < n; ++i) {
            cout << i + 1 << ' ' << (i + s) % n + 1 << endl;
            --count;
        }
    }

    return 0;
}
