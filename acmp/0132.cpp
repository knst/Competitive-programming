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
    size_t s, f;
    cin >> s >> f;
    --s; --f;
    vector<vector<int>> v(n, vector<int>(n));
    for (auto& i : v)
        for (auto& j : i)
            cin >> j;

    vector<bool> processed(n, false);
    priority_queue<pair<int,int>> pretend;
    pretend.push({0, s});
    vector<int> l(n, numeric_limits<int>::max());
    l[s] = 0;
    while (!pretend.empty()) {
        auto top = pretend.top();
        pretend.pop();
        size_t Mi = top.second;
        if (processed[Mi])
            continue;
        if (Mi == f)
            break;
        processed[Mi] = true;
        int M = -top.first;

        for (size_t i = 0; i < n; ++i) {
            if (v[Mi][i] != -1 && M + v[Mi][i] < l[i]) {
                    l[i] = M + v[Mi][i];
                    pretend.push({-l[i], i});
            }
        }

    }
    if (l[f] == numeric_limits<int>::max())
        cout << -1 << endl;
    else
        cout << l[f] << endl;



    return 0;
}
