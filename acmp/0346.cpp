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

    int A;
    int B;
    int c;
    cin >> A >> B >> c;

    vector<int> a;
    vector<int> b;
    do {
        a.push_back(A % 10);
        A /= 10;
    } while (A);
    do {
        b.push_back(B % 10);
        B /= 10;
    } while (B);
    sort(b.begin(), b.end());
    sort(a.begin(), a.end());
    int minimal = numeric_limits<int>::max();
    do {
        int ap = 0;
        for (auto i : a)
            ap = ap * 10 + i;
        int bp = c - ap;
        if (bp <= 0)
            continue;
        vector<int> b2;
        do {
            b2.push_back(bp % 10);
            bp /= 10;
        } while (bp);
        while (b2.size() < b.size())
            b2.push_back(0);
        sort(b2.begin(), b2.end());
        if (b2 == b)
            minimal = min(minimal, ap);

    } while (next_permutation(a.begin(), a.end()));
    if (minimal != numeric_limits<int>::max()) {
        cout << "YES" << endl;
        cout << minimal << ' ' << c - minimal << endl;
    } else {
        cout << "NO" << endl;
    }


    return 0;
}
