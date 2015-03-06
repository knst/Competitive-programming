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

namespace std {
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
}

long long Pow(long long a, long long p, long long mod) {
    a = a % mod;
    if (p == 0)
        return 1;
    if (p % 2 == 1)
        return Pow(a, p-1, mod) * a % mod;
    long long b = Pow(a, p / 2, mod) % mod;
    return b * b % mod;
}
long long Inv (long long x, long long phi, long long mod) {
    return Pow(x, phi - 1, mod);
}

long long gcd(long long a, long long b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int mod;
    int n;
    int dx;
    int dy;
    cin >> mod >> n >> dx >> dy;
    map<int,int> m;
    map<int,pair<int,int>> Ret;
    int phi = 0;
    for (int i = 1; i < mod; ++i) {
        if (gcd(i, mod) == 1)
            ++phi;

    }
    for (int i = 0; i < n; ++i) {
        int x;
        int y;
        cin >> x >> y;
        long long k = (mod - x) * Inv(dx, phi, mod) % mod;
        long long y0 = (y + k * dy) % mod;
        m[y0]++;
        Ret[y0] = {x,y};

    }
    int Max = -1;
    int maxy = -1;
    for (auto i : m) {
        if (i.second > Max) {
            Max = i.second;
            maxy = i.first;
        }
    }
    cout << Ret[maxy].first << ' ' << Ret[maxy].second << endl;
    return 0;
}
