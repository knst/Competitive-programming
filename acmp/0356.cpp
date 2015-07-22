
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
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");
#endif

    size_t e;
    size_t f;
    input >> e >> f;
    f -= e;
    size_t n;
    input >> n;

    vector<size_t> maxcost(f + 1);
    vector<size_t> mincost(f + 1);

    for (size_t i = 0; i < n; ++i) {
        size_t w;
        size_t p;
        input >> p >> w;
        for (size_t j = 0; j + w <= f; ++j) {
            if (j == 0 || maxcost[j]) {
                maxcost[j + w] = max(maxcost[j + w], maxcost[j] + p);
                if (mincost[j + w])
                    mincost[j + w] = min(mincost[j + w], mincost[j] + p);
                else
                    mincost[j + w] = mincost[j] + p;
            }
        }
    }
    if (f == 0 || maxcost[f])
        output << mincost[f] << ' ' << maxcost[f] << endl;
    else
        output << "This is impossible." << endl;


    return 0;
}
