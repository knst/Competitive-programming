
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

    size_t n;
    input >> n;
    size_t k;
    input >> k;
    string s;
    input >> s;
    vector<size_t> last(26, -k - 1);
    vector<size_t> values(n + k, n + k + 1);
    values[k] = 0;
    last[s[0] - 'A'] = 0;

    for (size_t i = 1; i < n; ++i) {
        for (size_t j = 0; j < last.size(); ++j) {
            if (i - last[j] > k)
                continue;
            size_t v = values[last[j] + k] + (j != static_cast<size_t>(s[i] - 'A'));
            if (v < values[i + k]) {
                values[i + k] = v;
            }
        }
        last[s[i] - 'A'] = i;
    }
    output << values[n + k - 1] << endl;

    return 0;
}
