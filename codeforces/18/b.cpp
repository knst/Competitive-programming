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
}

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

long long Top(size_t index, long long m, long long l, long long d) {
    long long t = (index * m + l + d) / d;
    return t * d;
}

long long Bot(size_t index, long long m, long long d) {
    long long t = (index * m -1) / d;
    return d * t;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    long long d;
    long long m;
    long long l;
    cin >> n >> d >> m >> l;

    size_t index = 1;
    for (; index <= n; ++index) {
        long long top = Top(index-1, m, l, d);
        long long bot = Bot(index, m, d);
        if (top <= bot) {
            cout << top << endl;
            return 0;
        }
    }
    if (index > n)
        cout << Top(n-1, m, l, d) << endl;


    return 0;
}
