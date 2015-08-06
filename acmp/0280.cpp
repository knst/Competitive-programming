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
    vector<uint64_t> primes(1000);
    for (uint64_t i = 2; n != 1; ++i) {
        while (n % i == 0) {
            primes[i]++;
            n /= i;
        }
    }
    uint64_t count = 1;
    for (uint64_t i = 0; i < primes.size(); ++i) {
        if (primes[i] > 1)
            count *= primes[i];
    }
    cout << count << endl;
    return 0;
}
