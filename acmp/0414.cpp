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

#ifdef _KNST
    istream& input = cin;
    ostream& output = cout;
#else
    ifstream input("INPUT.TXT");
    ofstream output("OUTPUT.TXT");
#endif

    size_t n;
    input >> n;

    size_t a;
    size_t b;
    input >> a >> b;
    vector<size_t> v(n);
    for (size_t i = 1; i < n; ++i)
        input >> v[i];
    vector<bool> m(n);
    v[0] = 1;
    m[0] = true;
    while (a != 1) {
        m[a-1] = true;
        a = v[a - 1];
    }
    while (m[b - 1] == false)
        b = v[b - 1];
    output << b << endl;

    return 0;
}
