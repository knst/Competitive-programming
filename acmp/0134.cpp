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

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;

    size_t d;
    size_t v;
    cin >> d >> v;
    --d; --v;

    size_t r;
    cin >> r;
    using race = tuple<size_t, size_t, size_t, size_t>;
    vector<race> rv(r);
    for (auto& i : rv) {
        size_t x;
        size_t y;
        size_t s;
        size_t e;
        cin >> x >> s >> y >> e;
        --x;
        --y;
        i = make_tuple(x, y, s, e);
    }

    priority_queue<pair<size_t, size_t>, vector<pair<size_t, size_t>>, greater<pair<size_t, size_t>>> q;
    q.push({0, d});
    vector<size_t> V(n, numeric_limits<size_t>::max());
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (V[t.second] <= t.first)
            continue;
        V[t.second] = t.first;
        for (auto i : rv) {
            if (get<0>(i) != t.second)
                continue;
            if (get<2>(i) < t.first)
                continue;
            q.push({get<3>(i), get<1>(i)});
        }
    }
    if (V[v] == numeric_limits<size_t>::max())
        cout << -1 << endl;
    else
        cout << V[v] << endl;


    return 0;
}
