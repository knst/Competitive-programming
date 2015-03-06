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
    int m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (auto& i : a)
        cin >> i;
    for (auto& i : b)
        cin >> i;
    if (m == 1) {
        cout << n << endl;
        return 0;
    }
    for (int i = 1; i < n; ++i)
        a[i-1] -= a[i];
    for (int j = 1; j < m; ++j)
        b[j-1] -= b[j];
    --n;
    --m;
    a.resize(n);
    b.resize(m);


    vector<int> prefix(m);
    for (int i = 1;  i < m; ++i) {
        int j = prefix[i-1];
        while (j > 0 && b[i] != b[j])
            j = prefix[j-1];
        if (b[i] == b[j])
            ++j;
        prefix[i] = j;
    }
    int count = 0;
    int i = 0;
    int j = 0;
    while (i < n) {
        while (j > 0 && a[i] != b[j])
            j = prefix[j-1];
        if (a[i] == b[j])
            ++j;
        ++i;
        if (j >= m) {
            ++count;
            j = prefix[j-1];
        }
    }
    cout << count << endl;



    return 0;
}
