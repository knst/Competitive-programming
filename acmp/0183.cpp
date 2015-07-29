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
    uint64_t mod;
    cin >> mod;

    vector<int64_t> v(n + 3);
    v[2] = 1 % mod;
    for (size_t index = 3; index <= n; ++index) {
        if (index % 2 == 0)
            v[index] += v[index / 2];
        v[index] = (v[index] + v[index - 1]) % mod;
    }
    cout << v[n] << endl;

    return 0;
}
