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
    size_t k;
    size_t p;
    cin >> n >> k >> p;

    vector<size_t> v(p);
    for (auto& i : v)
        cin >> i;

    vector<bool> m(n + 1);
    m[n] = false;
    for (size_t i = n - 1; i < n; --i) {
        if (i + k > n)
            m[i] = true;
        else {
            bool ok = false;
            for (size_t j = i + 1; j <= i + k; ++j)
                if (!m[j])
                    ok = true;
            m[i] = ok;
        }
    }
    size_t count = 0;
    for (size_t i = 0; i < p; ++i) {
        count += v[i];
        if (!m[count])
            cout << "T";
        else {
            bool ok = true;
            for (size_t j = 0; j < k && count - v[i] + j < n; ++j) {
                if (!m[count - v[i] + j + 1])
                    ok = false;
            }
            if (ok)
                cout << "T";
            else
                cout << "F";
        }
        cout << "\n";
    }
    return 0;
}
