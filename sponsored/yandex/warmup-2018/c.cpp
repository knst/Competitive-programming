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

#include <cmath>

using namespace std;

namespace std { template <class T1, class T2> struct hash<pair<T1, T2>> {
    size_t operator()(const pair<T1, T2>& p) const { return hash<T1>()(p.first) ^ hash<T2>()(p.second); }
};}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1)) * 4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

template<class T> T gcd(T A, T B) { return B == 0 ? A : gcd(B, A % B); }

uint64_t powMod(uint64_t G, uint64_t pow, uint64_t M) {
    if (pow == 0) return 1;
    return pow % 2 == 0 ? powMod(G * G % M, pow / 2, M) : powMod(G, pow - 1, M) * G % M;
}

uint64_t inverse(uint64_t X, uint64_t M) { return X == 1 ? 1 : powMod(X, M - 2, M); }

using Point = pair<int64_t, int64_t>;
bool test(Point a, Point b, Point p) {
    int64_t x1 = a.first;
    int64_t y1 = a.second;
    int64_t x2 = b.first;
    int64_t y2 = b.second;
    int64_t x = p.first;
    int64_t y = p.second;
    return x1 * y2 - x2 * y1 + (x2 - x1) * y + (y1 - y2) * x == 0;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    set<Point> points;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int x;
            int y;
            int r;
            cin >> x >> y >> r;
            points.insert({x * 2, y * 2});
        } else {
            int x1, y1, x2, y2, x3, y3, x4, y4;
            cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
            if (x1 + x3 != x2 + x4 || y1 + y3 != y2 + y4) return 7;
            points.insert({x1 + x3, y1 + y3});
        }
    }
    vector<Point> pointsv;
    for (auto p : points) {
        pointsv.push_back(p);
    }
    if (pointsv.size() <= 2) {
        cout << "Yes" << endl;
        return 0;
    }
    bool ok = true;
    for (int i = 2; i < pointsv.size(); ++i) {
        if (!test(pointsv[0], pointsv[1], pointsv[i])) ok = false;
    }
    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
