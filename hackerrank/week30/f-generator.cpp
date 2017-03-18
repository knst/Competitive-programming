#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << n << endl;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n * 3; ++i) {
        int x = rand() % n;
        int y = rand() % n;
        if (x == y) continue;
        v[x][y] = 1;
        v[y][x] = 1;
    }

    for (auto i : v) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
}
