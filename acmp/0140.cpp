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

    vector<vector<int>> v(n, vector<int>(n));
    for (auto & i : v)
        for (auto& j : i) {
            cin >> j;
            if (j == 100000)
                j = numeric_limits<int>::max();
        }

            for (size_t k = 0; k < n; ++k) {
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j) {
                if (v[i][k] < numeric_limits<int>::max() && v[k][j] < numeric_limits<int>::max())
                    if (v[i][j] > v[i][k] + v[k][j]) {
                        v[i][j] = v[i][k] + v[k][j];
                    }
            }
        }
            for (size_t k = 0; k < n; ++k) {
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j) {
                if (v[i][k] < numeric_limits<int>::max() && v[k][j] < numeric_limits<int>::max())
                    if (v[i][j] > v[i][k] + v[k][j]) {
                        cout << "YES" << endl;
                        return 0;
                    }
            }
        }
    cout << "NO" << endl;


    return 0;
}
