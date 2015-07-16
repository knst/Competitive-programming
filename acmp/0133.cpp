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

    vector<int> v(n);
    for (auto& i : v)
        cin >> i;

    vector<vector<size_t>> edges(n);

    size_t m;
    cin >> m;
    for (size_t i = 0; i < m; ++i) {
        size_t x;
        size_t y;
        cin >> x >> y;
        --x;
        --y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    vector<int> lens(n, -1);
    priority_queue<pair<int, size_t>, vector<pair<int, size_t>>, greater<pair<int,size_t>>> q;
    q.push({0, 0});
    while (!q.empty()) {
        auto i = q.top();
        q.pop();
        if (lens[i.second] != -1)
            continue;
        lens[i.second] = i.first;
        for (auto j : edges[i.second]) {
            if (lens[j] != -1)
                continue;
            q.push({i.first + v[i.second], j});
        }
    }
    cout << lens[n-1] << endl;

    return 0;
}
