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

    vector<pair<int, int>> v;
    for (size_t i = 0; i < n; ++i) {
        int l;
        int r;
        cin >> l >> r;
        v.push_back({l, 1});
        v.push_back({r, 2});
    }
    sort(v.begin(), v.end());
    size_t count = 0;
    size_t first = 0;
    int result = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i].second == 1) {
            if (count == 0)
                first = v[i].first;
            ++count;
        }
        if (v[i].second == 2) {
            --count;
        }
        if (count == 0)
            result += v[i].first - first;

    }
    cout << result << endl;

    return 0;
}
