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

int main() {
    std::ios_base::sync_with_stdio(false);

    int64_t m;
    int64_t h1;
    int64_t a1;
    int64_t x1;
    int64_t y1;
    int64_t h2;
    int64_t a2;
    int64_t x2;
    int64_t y2;
    cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
    int64_t hi1 = h1;
    int64_t hi2 = h2;
    for (int i = 0; i < m * 5; ++i) {
        if (hi1 == a1 && hi2 == a2) {
            cout << i << endl;
            return 0;
        }
        hi1 = (x1 * hi1 + y1) % m;
        hi2 = (x2 * hi2 + y2) % m;
    }

    vector<int64_t> hv1;
    vector<bool> hs1(m);
    while (hs1[hi1] == false) {
        hs1[hi1] = true;
        hv1.push_back(hi1);
        hi1 = (x1 * hi1 + y1) % m;
    }
    vector<int64_t> hv2;
    vector<bool> hs2(m);
    while (hs2[hi2] == false) {
        hs2[hi2] = true;
        hv2.push_back(hi2);
        hi2 = (x2 * hi2 + y2) % m;
    }

    int64_t l1 = hv1.size();
    int64_t l2 = hv2.size();
    int64_t gl = gcd(l1, l2);
    int64_t l = l1 * l2 / gcd(l1, l2);

    int64_t p1 = -1;
    int64_t p2 = -1;
    for (size_t i = 0; i < hv1.size(); ++i) {
        if (hv1[i] == a1)
            p1 = i;
    }
    for (size_t i = 0; i < hv2.size(); ++i) {
        if (hv2[i] == a2)
            p2 = i;
    }

    int64_t g = (p1 + l2 - p2) % l;
    if (p1 == -1 || p2 == -1 || g != 0) {
        cout << -1 << endl;
        cerr << l1 << ' ' << l2 << endl;
        cerr << "g: " << g << endl;
        return 0;
    }

    int64_t l1r = 0;
    int64_t l2r = 0;
    for (int64_t i = 0; i < l1r; ++i) {
        if (l1 * i % l2 == 0)
            l1r = i;
    }
    for (int64_t i = 0; i < l2r; ++i) {
        if (l2 * i % l1 == 0)
            l2r = i;
    }

    int64_t x = g * l2 * l2r + g * l1 * l1r;
    x = x % (l1 * l2 / g);

    cout << x + 10 * m << endl;





    return 0;
}
