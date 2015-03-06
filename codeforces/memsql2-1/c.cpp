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
#include <unordered_map>
#include <unordered_set>


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

long double C(int n, int m) {
    long double result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    for (int j = 1; j <= m; ++j) {
        result /= j;
    }
    for (int j = 1; j <= (n - m); ++j) {
        result /= j;
    }
    return result;
}
long double C24(int start, int end, int n) {
    long double res = 1;
//    cout << start << ' ' << end << endl;
    for (int i = start + 1; i <= end; ++i) {
        res *= (double)(i-n) / (i) ;
    }
    return res;
}
long double C2(int start, int end) {
    long double res = 1;
//    cout << start << ' ' << end << endl;
    for (int i = start + 1; i <= end; ++i) {
        res *= i;
    }
    return res;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cout<<fixed;
    cout.precision(20);
    int n;
    int m;
    cin >> n >> m;
    long double sum = 0;
    long double ki = 1;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (m == 1) {
        cout << 1.0 / n << endl;
        return 0;
    }
    for (int k = 1; k <= min(n, m); ++k) {
        long double c1 = C2(m-k, m);
        long double c2 = C24(n * m - m, n * m, n);
        long double c3 = C2(n-k, n);
//        long double c4 = C2(n * m - m - n, n * m - m - n + k+1);
        long double c4 = 1;
//        long double c24 = C24(n * m - m - n + k, n
//        cout << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4 << endl;
        ki *= (double)k * (n * m - m - n + k);
//        long double c1 = C(m, k) * C((n-1) * m, n-k) / C(n * m, n);
        long double delta = c1 * c2 * c3 / c4 / ki;
        if (delta < 1e-20)
            break;
        sum += delta * k * k / n;
    }
    cout << sum << endl;



    return 0;
}
