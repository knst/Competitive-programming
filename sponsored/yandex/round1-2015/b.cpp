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

using Point = pair<int, int>;

int Abs(int x) {
    return x > 0 ? x : -x;
}

double Pol(Point a, Point b) {
    double x = b.first - a.first;
    double y = b.second - a.second;
    if (x > 0 && y >= 0)
        return atan(y / x);
    if (x > 0 && y < 0)
        return atan(y / x) + 2 * const_pi();
    if (x < 0)
        return atan(y / x) + const_pi();
    if (x == 0 && y > 0)
        return const_pi() / 2;
    if (x == 0 && y < 0)
        return const_pi() * 3 / 2;
    throw "wtf?";
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    vector<pair<Point, int>> v(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> v[i].first.first >> v[i].first.second >> v[i].second;
    }
    int minimum = numeric_limits<int>::max();

    for (size_t start = 0; start < n; ++start) {
        vector<pair<double, int>> pol;
        for (size_t i = 0; i < n; ++i) {
            if (i != start) {
                pol.push_back({Pol(v[start].first, v[i].first), v[i].second});
            }
        }
        sort(pol.begin(), pol.end());
        int sum1 = 0;
        int sum2 = 0;
        size_t a = 0;
        while (a < pol.size() && pol[a].first <= const_pi()) {
            sum1 += pol[a].second;
            ++a;
        }
        for (size_t i = a; i < pol.size(); ++i)
            sum2 += pol[i].second;
        int vs = v[start].second;
        minimum = min(minimum, Abs(sum1 - sum2 + vs));
        minimum = min(minimum, Abs(sum1 - sum2 - vs));
        size_t b = 0;
        while (a < pol.size()) {
            sum1 += pol[a].second;
            sum2 -= pol[a].second;
            while (b < a && pol[b].first + const_pi() < pol[a].first) {
                sum1 -= pol[b].second;
                sum2 += pol[b].second;
                ++b;
            }
            ++a;
            minimum = min(minimum, Abs(sum1 - sum2 + vs));
            minimum = min(minimum, Abs(sum1 - sum2 - vs));

        }

    }
    cout << minimum << endl;

    return 0;
}
