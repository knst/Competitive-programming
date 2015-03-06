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
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    map<int,int> m;
    int sum2 = 0;
    for (size_t i = v.size() - 1; i < v.size(); --i) {
        sum2 += v[i];
        m[sum2]++;
    }
    int sum = 0;
    long long count = 0;
    for (size_t i = 0; i < v.size() - 2 && i < v.size(); ++i) {
        sum += v[i];
        m[sum2]--;
        sum2 -= v[i];
        if (sum * 2 != sum2)
            continue;
        if (m[sum] != 0) {
            count += m[sum];
            if (sum == sum2)
                --count;
        }

    }

    cout << count << endl;





    return 0;
}
