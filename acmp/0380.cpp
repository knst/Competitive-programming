/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

struct rect {
    int x1;
    int y1;
    int x2;
    int y2;

    bool operator<(const rect& r) {
        if (y1 < r.y1)
            return true;
        if (y1 > r.y1)
            return false;
        if (y2 < r.y2)
            return true;
        return false;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<rect> v;

    vector<int> p;
    vector<int> q;
    for (size_t i = 0; i < n; ++i) {
        rect r;
        cin >> r.x1 >> r.y1 >> r.x2 >> r.y2;
        if (r.x1 > r.x2)
            swap(r.x1, r.x2);
        if (r.y1 > r.y2)
            swap(r.y1, r.y2);
        v.push_back(r);
        p.push_back(r.x1);
        p.push_back(r.x2);
        q.push_back(r.y1);
        q.push_back(r.y2);
    }
    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    int result = 0;
    for (size_t i = 1; i < p.size(); ++i) {
        int s = p[i-1];
        int e = p[i];
        for (size_t y = 1; y < q.size(); ++y) {
            int sy = q[y - 1];
            int ey = q[y];
            bool ok = false;
            for (size_t j = 0; j < n; ++j) {
                if (v[j].x1 <= s && v[j].x2 >= e && v[j].y1 <= sy && v[j].y2 >= ey)
                    ok = true;
            }
            if (ok)
                result += (e - s) * (ey - sy);
        }
    }
    cout << result << endl;
    return 0;
}
