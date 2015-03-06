#include <algorithm>
#include <iostream>
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
    if (n == 1 && k != 0) {
        cout << -1 << endl;
        return 0;
    }
    if (n != 1 && k == 0) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 1 && k == 0) {
        cout << 1 << endl;
        return 0;
    }
    if (n / 2 > k) {
        cout << -1 << endl;
        return 0;
    }
    int t = k - n / 2 + 1;
    int t2 = t * 2;
    while (t2 <= n+2)
        t2 *= 2;
    cout << t2 << ' ' << t;
    int count = 2;
    int i = 1;
    while (count < n) {
        if (i == t)
            ++i;
        ++count;
        cout << ' ' << i;
        ++i;
    }
    cout << endl;


    return 0;
}
