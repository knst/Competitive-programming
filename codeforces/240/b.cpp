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

    const int MOD = 1000 * 1000 * 1000 + 7;

    int n;
    int k;
    cin >> n >> k;
    vector<vector<int>> divisors(n+1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i % j == 0) {
                divisors[i].push_back(j);
            }
        }
    }

    vector<int> v(n+1);
    for (int i = 0; i <= n; ++i) {
        v[i] = 1;
    }
    for (int i = 1; i < k; ++i) {
        vector<int> v2(n+1);
        for (int j = 1; j <= n; ++j) {
            long long sum = 0;
            for (auto d : divisors[j])
                sum += v[d];
           v2[j] = sum % MOD; 
        }
        v = v2;
    }
    long long result = 0;
    for (int i = 1; i <= n; ++i) {
        result += v[i];
    }
    cout << result % MOD << endl;

    return 0;
}
