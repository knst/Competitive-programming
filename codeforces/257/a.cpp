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

    long long n;
    long long m;
    long long k;
    cin >> n >> m >> k;
    if (n < m)
        swap(n, m);

    if (n > k || m > k) {
        long long s1 = n > k ? m * (n / (k+1)) : 0;
        long long s2 = m > k ? n * (m / (k+1)) : 0;
        cout << max(s1, s2) << endl;
    } else {
        k -= (n-1);
        n = 1;
        if (m > k)
            cout << m / (k+1) << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
