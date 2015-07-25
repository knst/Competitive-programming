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

    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for (size_t i = 0; i < n; ++i)
        cin >> a[i] >> b[i] >> c[i];

    vector<int> times(n + 2, numeric_limits<int>::max());
    times[0] = a[0];
    times[1] = b[0];
    times[2] = c[0];
    for (size_t i = 1; i < n; ++i) {
        times[i] = min(times[i], times[i - 1] + a[i]);
        times[i + 1] = min(times[i + 1], times[i - 1] + b[i]);
        times[i + 2] = times[i - 1] + c[i];
    }
    cout << times[n-1] << endl;


    return 0;
}
