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

struct Point {
    int x;
    int y;
    bool operator<(const Point& p) const {
        if (x < p.x)
            return true;
        if (x > p.x)
            return false;
        if (y < p.y)
            return true;
        return false;
    }
    bool operator==(const Point& p) const {
        if (x == p.x && y == p.y)
            return true;
        return false;
    }
    bool operator != (const Point&p) const {
        return !(*this == p);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);

    vector<pair<Point,Point>> v(4);
    vector<Point> ps;
    for (int i = 0; i < 4; ++i) {
        cin >> v[i].first.x >> v[i].first.y;
        cin >> v[i].second.x >> v[i].second.y;
        if (v[i].second < v[i].first)
            swap(v[i].first, v[i].second);
        ps.push_back(v[i].first);
        ps.push_back(v[i].second);
    }
    sort(ps.begin(), ps.end());
    sort (v.begin(), v.end());
    for (int i = 0; i < 4; ++i) {
        if (v[i].first == v[i].second) {
            cout << "NO" << endl;
            return 0;
        }
    }
    bool ok = true;
    for (int i = 0; i < 4; ++i) {
        if (ps[i*2] != ps[i*2 + 1])
            ok = false;
    }
    if (v[0].first != ps[0])
        ok = false;
    if (v[0].second != ps[2])
        ok = false;
    if (v[1].first != ps[0])
        ok = false;
    if (v[1].second!= ps[4])
        ok = false;
    if (v[2].first != ps[2])
        ok = false;
    if (v[2].second != ps[6])
        ok = false;
    if (v[3].first != ps[4])
        ok = false;
    if (v[3].second != ps[6])
        ok = false;
    if (ps[0].x != ps[2].x)
        ok = false;
    if (ps[0].y != ps[4].y)
        ok = false;
    if (ps[4].x != ps[6].x)
        ok = false;
    if (ps[2].y != ps[6].y)
        ok = false;
    if (ok)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
