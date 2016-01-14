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
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
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

int64_t len(pair<int64_t, int64_t> a, pair<int64_t, int64_t> b) {
    int64_t x1 = a.first;
    int64_t y1 = a.second;
    int64_t x2 = b.first;
    int64_t y2 = b.second;
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

pair<int64_t,int64_t> Sub(pair<int64_t, int64_t> a1, pair<int64_t, int64_t> a2)
{
    pair<int64_t, int64_t> res = {a2.first - a1.first, a2.second - a1.second};
    return res;
}

int64_t Mul(pair<int64_t, int64_t> a1, pair<int64_t, int64_t> a2, pair<int64_t, int64_t> b1, pair<int64_t, int64_t> b2) {
    pair<int64_t, int64_t> a = Sub(a2, a1);
    pair<int64_t, int64_t> b = Sub(b2, b1);

    return a.first * b.first + a.second *  b.second;

}
int64_t Mul2(pair<int64_t, int64_t> a1, pair<int64_t, int64_t> a2, pair<int64_t, int64_t> b1, pair<int64_t, int64_t> b2) {
    pair<int64_t, int64_t> a = Sub(a2, a1);
    pair<int64_t, int64_t> b = Sub(b2, b1);

    return a.first * b.second - a.second * b.first;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    int64_t px, py;
    cin >> px >> py;
    pair<int64_t, int64_t> P = {px, py};
    vector<pair<int64_t, int64_t>> v;
    for (size_t i = 0; i < n; ++i) {
        int64_t x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    v.push_back(v.front());

    double minLen;
    double maxLen;
    maxLen = minLen = len(v[0], P);
    for (size_t i = 1; i < v.size(); ++i) {
        double len1 = len(v[i-1], P);
        double len2 = len(v[i], P);
        minLen = min(minLen, min(len1, len2));
        maxLen = max(maxLen, max(len1, len2));
        if (Mul(v[i-1], P, v[i-1], v[i]) >= 0 &&
            Mul(v[i], P, v[i], v[i-1]) >= 0) {
            double Len = Mul2(v[i-1], v[i], v[i-1], P);
            Len = Len * Len / len(v[i], v[i-1]);
            if (Len < 0)
                Len = -Len;
            minLen = min(minLen, Len);
        }
    }
    int64_t s = maxLen - minLen;
    cout.precision(10);
    cout << fixed << s * const_pi() << endl;

    return 0;
}
