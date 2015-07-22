
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
        cin >> v[i];

    const int M = 1000000;
    vector<vector<int> > cost(n, vector<int> (n, M));
    vector<vector<int> > coups(n, vector<int> (n, 0));

    if (v[0] > 100)
        cost[0][1] = v[0];
    else
        cost[0][0] = v[0];

    for (size_t i = 1; i < n; ++i) {
        if (cost[i - 1][1] != M) {
            cost[i][0] = cost[i - 1][1];
            coups[i][0] = coups[i][1] + 1;
        }
        if (v[i] <= 100) {
            if (cost[i - 1][0] + v[i] <= cost[i][0]) {
                cost[i][0] = cost[i - 1][0] + v[i];
                coups[i][0] = coups[i - 1][0];
            }
        } else {
            if (cost[i - 1][0] + v[i] <= cost[i][1]) {
                cost[i][1] = cost[i - 1][0] + v[i];
                coups[i][1] = coups[i - 1][0];
            }
        }

        for (size_t j = 1; j < n-1; ++j) {
            if (cost[i - 1][j + 1] < cost[i][j]) {
                cost[i][j] = cost[i - 1][j + 1];
                coups[i][j] = coups[i - 1][j + 1] + 1;
            }
            if (v[i] <= 100) {
                if (cost[i - 1][j] + v[i] <= cost[i][j]) {
                    cost[i][j] = cost[i-1][j] + v[i];
                    coups[i][j] = coups[i - 1][j];
                }
            } else {
                if (cost[i - 1][j] + v[i] <= cost[i][j + 1]) {
                    cost[i][j + 1] = cost[i - 1][j] + v[i];
                    coups[i][j + 1] = coups[i - 1][j];
                }
            }
//            cout << cost[i][j] << ' ' << cost[i][j + 1] << endl;

        }
        //if (cost[i][n - 2] > 100)
        //    cost[i][n - 1] = cost[i][n - 2] + v[i];
    }
    for (size_t i = 0; 0 && i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            cout << cost[i][j] << ' ';
        }
        cout << endl;
    }

    int minimum = M;
    int k = 0;
    int k2 = 0;
    for (size_t i = 0; i < n; ++i)
        if (cost[n-1][i] <= minimum) {
            minimum = cost[n-1][i];
            k = i;
            k2 = coups[n-1][i];
        }
    cout << minimum << endl;
    cout << k << ' ' << k2 << endl;



    return 0;
}
