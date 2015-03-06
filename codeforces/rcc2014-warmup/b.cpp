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
    int m;
    long long b;
    cin >> n >> m >> b;
    vector<int> x(n);
    vector<int> k(n);
    vector<long long> fm(n);
    set<int> ks;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> k[i];
        ks.insert(k[i]);
        int mi;
        cin >> mi;
        for (int j = 0; j < mi; ++j) {
            int val;
            cin >> val;
            --val;
            if (val == 0)
                fm[i] |= 1;
            else 
                fm[i] |= 1 << val;
        }
    }
    long long minimal = numeric_limits<long long>::max();

    unsigned int M = 1 << m;
    vector<long long> v(M);
    for (size_t i = 0; i < M; ++i)
        v[i] = numeric_limits<long long>::max();
    v[0] = 0;

    for (auto K : ks) {
        for (int i = 0; i < n; ++i) {
            if (k[i] != K)
                continue;
            for (size_t j = 0; j < M-1; ++j) {
                if (v[j] != numeric_limits<long long>::max() && v[j | fm[i]] > v[j] + x[i]) {
                    v[j | fm[i]] = v[j] + x[i];
                }
            }
        }
        if (v[M-1] != numeric_limits<long long>::max())
            minimal = min(minimal, v[M-1] + b * K);
    }
    
    if (minimal != numeric_limits<long long>::max()) {
        cout << minimal << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
