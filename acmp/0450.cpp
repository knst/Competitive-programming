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
    vector<vector<int>> v(n, vector<int>(n));
    for (auto& i : v) {
        for (auto& j : i) {
            cin >> j;
        }
    }

    vector<int> p(n);
    vector<int> sum(n);
    for (size_t i = 0; i < n; ++i) {
        p[i] = i;
        for (size_t j = 0; j < n; ++j) {
            sum[j] += v[i][j];
        }
    }

    int minimal = numeric_limits<int>::max();
    vector<int> minimalP;
    do {
        int s = 0;
        for (size_t i = 0; i < n; ++i) {
            s += sum[i];
            s -= v[i][p[i]];
        }
        if (s < minimal) {
            minimal = s;
            minimalP = p;
        }

    } while (next_permutation(p.begin(), p.end()));
    for (auto i : minimalP)
        cout << static_cast<char>(i + 'A');
    cout << endl << minimal << endl;


    return 0;
}
