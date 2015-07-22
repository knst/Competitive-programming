
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
    vector<int> v(n);
    for (size_t i = 0; i < n; ++i)
        input >> v[i];
    vector<int> start(n);
    for (size_t i = 0; i < n; ++i) {
        vector<int> start2(n);
        for (size_t j = 0; j <= i + 1; ++j) {
            if (j > i + 1)
                continue;
            if (i % 2 == 0) {
                if (n - i - 1 >= j)
                    start2[j] = start[j - 1] + v[j - 1];
                else if (j == 0)
                    start2[j] = start[j] + v[n - j - i - 1];
                else
                    start2[j] = max(start[j] + v[n - j - i - 1], start[j - 1] + v[j - 1]);
            } else {
                if (n - i - 1 >= j)
                    start2[j] = start[j - 1] - v[j - 1];
                else if (j == 0)
                    start2[j] = start[j] - v[n - j - i - 1];
                else
                    start2[j] = min(start[j] - v[n - j - i - 1], start[j - 1] - v[j - 1]);
            }
        }
        start = start2;
        for (size_t j = 0; j < n; ++j)
            cout << start[j] << ' ';
        cout << endl;
    }
    int f2 = n % 2 ? 1 : 2;
    int f1 = n % 2 ? 2 : 1;
    for (size_t i = 0; i < n; ++i) {
        if (n % 2 && start[i] > 0 || n % 2 == 0 && start[i] < 0) {
            output << f1 << endl;
            return 0;
        }
    }
    for (size_t i = 0; i < n; ++i)
        if (start[i] == 0) {
            output << 0 << endl;
            return 0;
        }
    output << f2 << endl;


    return 0;
}
