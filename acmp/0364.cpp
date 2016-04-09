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


    uint64_t n, m;
    cin >> n >> m;

    bool empty = true;
    for (int i = 2; i < 33; ++i) {
        bool e = true;
        for (int j = 2; j < i; ++j)
            if (i % j == 0)
                e = false;
        if (e) {
            uint64_t r = 1;
            for (int j = 0; j < i - 1; ++j)
                r *= 2;
            uint64_t p = r * 2 - 1;
            r = r * (r * 2 - 1);
            for (uint64_t q = 3; q * q < p; ++q)
                if (p % q == 0)
                    r = 0;
            if (r >= n && r <= m) {
                cout << r << endl;
                empty = false;
            }
        }
    }
    if (empty)
        cout << "Absent" << endl;


    return 0;
}
