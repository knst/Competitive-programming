// knst

#import <bits/stdc++.h>

using namespace std;

size_t n, m, i, j, k, x, y, c = 1e4, t,
    X[]  {-1, 0, 0, 1, -1, 0},
    v[100][100], w[100][100];

main() {
    for (cin >> n >> m; --c; **w = **v)
        for (i = 0; i < n; ++i)
            for (j = 0; j < m; ++j)
                if (c == 9999)
                    cin >> v[i][j], w[i][j] = 1e8;
                else
                    for (k = 4; k--; )
                        x = i + X[k],
                        y = j - X[k + 2],
                        x < n && y < m &&
                            (t = w[i][j] = min(w[x][y] + v[i][j], w[i][j]));
    cout << t;
}
