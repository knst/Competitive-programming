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

int test(const vector<string>& v, int i, int j, int m, int n, char c) {
    if (i >= 0 && j >= 0 && i < m && j < n) {
        if (v[j][i] == c)
            return 1;
        return 0;
    }
    return 0;
}
int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<string> v(n);
    for (int i =  0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < m; ++i) {
        int count = 0;
        for (int j = 0; j < n; ++j) {
            count += test(v, i, 2 * j, m, n, 'U');
            count += test(v, i-j, j, m, n, 'R');
            count += test(v, i+j, j, m, n, 'L');
        }
        cout << count << ' ';
    }
    cout << endl;


    return 0;
}
