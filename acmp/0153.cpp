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

    int64_t n;
    cin >> n;

    size_t m;
    cin >> m;
    vector<int64_t> v(m);
    for (auto& i : v)
        cin >> i;
    v.push_back(0);

    vector<size_t> mask(m + 1);

    size_t minimum = numeric_limits<size_t>::max();
    int64_t sum = 0;
    size_t count = 0;

    while (true) {
        ++mask[0];
        ++count;
        sum += v[0];
        size_t index = 0;
        while (mask[index] > 2) {
            mask[index] = 0;
            sum -= v[index] * 3;
            ++index;
            sum += v[index];
            mask[index]++;
            count -= 2;
        }
        if (index == m)
            break;
        if (sum == n)
            minimum = min(count, minimum);
    }
    if (minimum != numeric_limits<size_t>::max()) {
        cout << minimum << endl;
        return 0;
    }
    for (auto i : v)
        n -= i + i;
    if (n >= 0)
        cout << -1;
    else
        cout << 0;
    cout << endl;

    return 0;
}
