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

    vector<pair<int64_t,int64_t>> v;
    for (size_t i = 0; i < n; ++i) {
        int64_t x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    v.push_back(v[0]);
    int64_t sum = 0;
    for (size_t i = 0; i < n; ++i) {
        sum += v[i].first * v[i + 1].second - v[i].second * v[i + 1].first;
    }
    if (sum < 0)
        sum = -sum;
    cout.precision(1);
    cout << fixed << (static_cast<double>(sum) / 2) << endl;


    return 0;
}
