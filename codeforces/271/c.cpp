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
};

struct point {
    int x;
    int y;
    int a;
    int b;
    bool operator<(const point& p)const {
        if (x < p.x)
            return true;
        if (x > p.x)
            return false;
        if (y < p.y)
            return true;
        return false;
    }
};

long long dist(const point& a, const point& b) {
    long long x = b.x - a.x;
    long long y = b.y - a.y;
    return x * x + y * y;
}

bool isSquare(vector<point> v) {
    for (auto& i : v) {
        i.x += i.a;
        i.y += i.b;
    }
    sort(v.begin(), v.end());
    do {
        long long a = dist(v[0], v[1]);
        long long b = dist(v[1], v[2]);
        long long c = dist(v[2], v[3]);
        long long d = dist(v[3], v[0]);
        long long x = dist(v[0], v[2]);
        long long y = dist(v[1], v[3]);
        if (a != 0 && a == b && b == c && c == d && a * 2 == x && a * 2 == y)
            return true;
    } while (next_permutation(v.begin(), v.end()));
    return false;
}

void transform(point& p) {
    swap(p.x, p.y);
    p.x = -p.x;
}
void solve() {
    vector<point> v(4);
    for (auto& i : v) {
        cin >> i.x >> i.y >> i.a >> i.b;
        i.x -= i.a;
        i.y -= i.b;
    }
    int minimal = 50;
    for (int a = 0; a < 4; ++a) {
        for (int b = 0; b < 4; ++b) {
            for (int c = 0; c < 4; ++c) {
                for (int d = 0; d < 4; ++d) {
                    if (isSquare(v)) {
                        int count = a + b + c + d;
                        minimal = min(count, minimal);
                    }
                    transform(v[3]);
                }
                transform(v[2]);
            }
            transform(v[1]);
        }
        transform(v[0]);
    }
    if (minimal == 50) {
        cout << -1 << endl;
    } else
        cout << minimal << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        solve();

    return 0;
}

