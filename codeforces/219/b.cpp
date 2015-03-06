#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    int n = 40;
    int m = 40;
    int field[40][40];
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            field[i][j] =
        }
    }

    int stack[40][40][40][40];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int ii = 0; ii < n; ++ii) {
                for (int jj = 0; jj < m; ++jj) {
                        stack[i][j][ii][jj] = 0;
                }
            }
        }
    }





    return 0;
}
