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
    int m = 1;
    for (int i = 0;  i < n; ++i) {
        m *= 2;
    }
    vector<int> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> v[i];
    }
    vector<vector<int>> v2(n);
    v2[0] = v;
    vector<long long> inv(n);
    inv[0] = 0;

    int iterSize = m;
    for (int i = 1; i < n; ++i) {
        v2[i].resize(m);
        inv[i] = 0;
        iterSize /= 2;

        

    }

    return 0;
}
