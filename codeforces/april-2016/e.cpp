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

bool Read(vector<int>& v, size_t n) {
    n > 0 && cin >> v[0];
    n > 1 && cin >> v[1];
    n > 2 && cin >> v[2];
    n > 3 && cin >> v[3];
    n > 4 && cin >> v[4];
    n > 5 && cin >> v[5];
    n > 6 && cin >> v[6];
    n > 7 && cin >> v[7];
    n > 8 && cin >> v[8];
    n > 9 && cin >> v[9];
}

bool calc(vector<vector<int>>& v, size_t k, size_t i, size_t j) {
//    cout << k << ' ' << i << ' ' << j << endl;
    k < 10 && i < 10 && j < 10 && (v[i][j] > v[i][k] + v[k][j]) && (v[i][j] = v[i][k] + v[k][j]);
    (j < 10 && calc(v, k, i, j + 1)) ||
    (i < 10 && calc(v, k, i + 1, 0)) ||
    (k < 10 && calc(v, k + 1, 0, 0));
    return true;
}
int res(vector<vector<int>> & v, size_t i, size_t j) {
    int Max = 0;
    i < 10 && j < 10 && v[i][j] != 10000000 && (Max = v[i][j]);
    (i < 10 && (Max = max(Max, res(v, i + 1, j)), 1)) ||
    (j < 10 && (Max = max(Max, res(v, 0, j + 1)), 1));
    return Max;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    vector<vector<int>> v(10, vector<int>(10, 10000000));
    n > 0 && Read(v[0], n);
    n > 1 && Read(v[1], n);
    n > 2 && Read(v[2], n);
    n > 3 && Read(v[3], n);
    n > 4 && Read(v[4], n);
    n > 5 && Read(v[5], n);
    n > 6 && Read(v[6], n);
    n > 7 && Read(v[7], n);
    n > 8 && Read(v[8], n);
    n > 9 && Read(v[9], n);

    calc(v, 0, 0, 0);

    int result = res(v, 0, 0);
    cout << result << endl;


    return 0;
}
