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

    vector<int> v(n);
    for (auto& i : v)
        cin >> i;

    vector<size_t> result(n);
    for (size_t i = 0; i < n; ++i) {
        size_t maximal = 0;
        for (size_t j = 0; j < i; ++j)
            if (v[j] < v[i])
                maximal = max(result[j], maximal);
        result[i] = maximal + 1;
    }
    size_t r = 0;
    for (auto i : result)
        r = max(r, i);

    cout << r << endl;


    return 0;
}
