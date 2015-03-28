#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <sstream>

using namespace std;

void solve(const vector<vector<int>>& easy, const vector<vector<int>>& hard) {
    string s;
    cin >> s;
    for (auto& i : s)
        if (i == '-')
            i = ' ';
    stringstream stream(s);
    int x;
    int y;
    stream >> x >> y;
    cout << easy[x][y] << ' ' << hard[y][y] << endl;
}
int sum(long long x, long long y) {
    const long long MOD = 1000 * 1000 * 1000 + 7;
    return (x + y) % MOD;
}
int main() {
    int N = 2001;
    int M = 2001;
    vector<vector<int>> easy(N, vector<int>(M));
    vector<vector<int>> hard(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        easy[i][0] = 1;
    }
    for (int i = 0; i < M; ++i)
        hard[0][i] = 1;
    for (int j = 1; j < N; ++j) {
        for (int i = 1; i < M; ++i) {
            if (i > j)
                easy[i][j] = sum(easy[i-1][j], easy[i][j-1]);
        }
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            if (i <= j)
                hard[i][j] = sum(hard[i-1][j], hard[i][j-1]);
        }
    }
#if 0
    for (auto i : easy) {
        for (auto j : i)
            cout << j << ' ';
        cout << endl;
    }
    cout << endl;

    for (auto i : hard) {
        for (auto j : i)
            cout << j << ' ';
        cout << endl;
    }
    cout << endl;
    return 0;
#endif
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve(easy, hard);
    }
}
