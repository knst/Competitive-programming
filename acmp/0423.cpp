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

const long double const_pi = std::atan(static_cast<long double>(1))*4;

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void Sum(vector<int>& sum, vector<int>& a, vector<int>& b) {
    int over = 0;
    int n = max(a.size(), b.size());
    a.resize(n);
    b.resize(n);
    for (int i = 0; i < n; ++i) {
        int r = a[i] + b[i] + over;
        sum.push_back(r % 10);
        over = r / 10;
    }
    if (over)
        sum.push_back(over);
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

    string s;
    input >> s;
    int last = 0;
    vector<int> sum;
    vector<int> last_sum;
    last_sum.push_back(1);
    sum.push_back(1);
    for (size_t i = 0; i < s.size(); ++i) {
        int next = s[i] - '0';
        if (last && last * 10 + next <= 33) {
            vector<int> sum2;
            Sum(sum2, sum, last_sum);
            last_sum = sum;
            sum = sum2;
        } else {
            last_sum = sum;
        }
        last = next;
    }
    for (size_t i = sum.size() - 1; i < sum.size(); --i) {
        output << static_cast<char>(sum[i] + '0');
    }
    return 0;
}
