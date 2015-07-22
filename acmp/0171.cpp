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

    uint64_t n;
    cin >> n;

    vector<size_t> counts;
    for (size_t i = 2; n != 1; ++i) {
        if (n % i == 0) {
            size_t count = 0;
            while (n % i == 0) {
                n /= i;
                ++count;
            }
            counts.push_back(count);
        }
    }
    uint64_t result = 1;
    for (auto i : counts)
        result = result * (i + 1);
    cout << result << endl;
}
