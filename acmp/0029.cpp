/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
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

int Abs(int x)
{
    return x > 0 ? x : -x;
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
    vector<int> v(n);
    for (size_t i = 0; i < n; ++i)
        input >> v[i];
    vector<long long> p(n);
    p[0] = 0;
    if (n > 1)
        p[1] = Abs(v[1] - v[0]);
    for (size_t i = 2; i < n; ++i)
        p[i] = std::min(p[i - 1] + Abs(v[i] - v[i-1]), p[i - 2] + 3 * Abs(v[i] - v[i-2]));
    output << p[n-1] << endl;


    return 0;
}
