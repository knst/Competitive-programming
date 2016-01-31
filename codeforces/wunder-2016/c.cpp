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

using Point = pair<int64_t, int64_t>;

int64_t Mul(const Point& a, const Point& b) {
    return a.first * b.second - a.second * b.first;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    vector<pair<int64_t, int64_t>> v;
    map<Point, size_t> m;
    for (size_t i = 0; i < n; ++i) {
        int64_t x, y;
        cin >> x >> y;
        v.push_back({x, y});
        m[{x, y}] = i + 1;
    }
    Point leftest = v[0];
    for (auto i : v)
        if (i < leftest)
            leftest = i;

    {
        vector<Point> v2;
        for (auto i : v) {
            if (i == leftest)
                continue;
            v2.push_back({i.first - leftest.first, i.second - leftest.second});
        }
        v = v2;
    }

    sort(v.begin(), v.end(), [](const Point& a, const Point& b) {
            return Mul(a, b) > 0;
    });

/*    for (auto i : v)
        cout << i.first << i.second << endl;
        */
    Point f = v[0];
    size_t start = 0;
    for (start = 0; start < v.size(); ++start) {
        if (Mul(v[0], v[start]) == 0)
            f = min(f, v[start]);
        else
            break;
    }
    Point e = v[start];
    for (size_t end = start; end < v.size(); ++end)
        if (Mul(v[start], v[end]) == 0)
            e = min(e, v[end]);
        else
            break;
    f.first += leftest.first;
    e.first += leftest.first;
    f.second += leftest.second;
    e.second += leftest.second;
    cerr << f.first << ' ' << f.second << endl;
    cerr << e.first << ' ' << e.second << endl;
    cout << m[leftest] << ' ' << m[f] << ' ' << m[e] << endl;
    return 0;
}
