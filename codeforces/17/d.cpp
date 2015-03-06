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

long long powMod(long long b, long long n, long long c) {
    if (n == 0)
        return 1;

    if (n % 2 == 1) {
        return powMod(b, n-1, c) * b % c;
    }
    long long p = powMod(b, n / 2, c);
    return p * p % c;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    string B;
    string N;
    int c;
    cin >> B >> N >> c;
    long long b = 0;
    for (auto i : B) {
        b = b * 10 + i - '0';
        b = b % c;
    }
    long long n = 0;
    for (auto i : N) {
        n = n * 10 + i - '0';
        n = n % c;
    }
    long long result = powMod(b, n, c) + c - powMod(b, n + c - 1, c);
    result = result % c;
    if (b == 0)
        cout << 0 << endl;
    else if (result == 0)
        cout << c << endl;
    else
        cout << result << endl;

    return 0;
}
