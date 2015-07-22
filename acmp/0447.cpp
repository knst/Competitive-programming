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

    int n;
    cin >> n;

    int last = 1;
    int c2 = 0;
    int c5 = 0;
    for (int i = 2; i <= n; ++i) {
        int value = i;
        while (value % 2 == 0) {
            ++c2;
            value /= 2;
        }
        while (value % 5 == 0) {
            ++c5;
            value /= 5;
        }
        last = last * value % 10;
    }
    for (int i = c2; i < c5; ++i)
        last = last * 5 % 10;
    for (int i = c5; i < c2; ++i)
        last = last * 2 % 10;

    cout << last << endl;

    return 0;
}
