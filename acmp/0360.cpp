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

const int dX4[] = {0, 0, 1, 1};
const int dY4[] = {0, 1, 0, 1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    unsigned int n;
    scanf("%u", &n);

    vector<vector<int>> v(n, vector<int>(n));
    for (auto& i : v)
        for (auto& j : i)
            scanf("%d", &j);
    int maximal = v[0][0] + v[0][1] + v[1][0];
    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 1; j < n; ++j) {
            int sum = 0;
            for (size_t t = 0; t < 4; ++t)
                sum += v[i - dX4[t]][j - dY4[t]];
            for (size_t t = 0; t < 4; ++t)
                maximal = max(maximal, sum - v[i - dX4[t]][j - dY4[t]]);
        }
    }
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 2; j < n; ++j) {
            maximal = max(maximal, v[i][j] + v[i][j-1] + v[i][j-2]);
            maximal = max(maximal, v[j][i] + v[j-1][i] + v[j-2][i]);
        }
    }
    cout << maximal << endl;

    return 0;
}
