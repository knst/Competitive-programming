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

    for (size_t i = 3; i * i <= n; ++i)
        if (n % i == 0) {
            cout << i - 1 << endl;
            return 0;
        }
    if (n % 2 == 0 && n / 2 -1 > 1)
        cout << n / 2 - 1 << endl;
    else if (n > 2)
        cout << n - 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
