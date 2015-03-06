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

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int k;
    cin >> n >> k;
    vector<int> v;
    if (k == 1) {
        for (int i=  0; i < n; ++i) {
            v.push_back(i);
        }
    } else {
        int mid = k / 2;
        int delta = 0;
        for (int i = 0; i < k; ++i) {
            if (k % 2)
                v.push_back(mid - delta);
            else
                v.push_back(mid + delta);

            if (delta >= 0)
                delta = -delta - 1;
            else
                delta = - delta;
        }
        for (int i = k ; i < n; ++i) {
            v.push_back(i);
        }

    }
/*    set<int> total;
    set<int> values;
    for (auto i : v) {
        total.insert(i);
        if (i < 0 || i >= n) {
            cout << "ERRRRRR" << endl;
        }
    }
    for (int i = 1; i < n; ++i)
        values.insert(abs(v[i]-v[i-1]));
    cout << values.size() << endl;
    */
    for (int i = 0; i < n; ++i)
        cout << v[i] + 1 << ' ';
   // if (values.size() != k || total.size() != n) {
  //      cout << "ERRR" << endl;
  //  }
    return 0;
}
