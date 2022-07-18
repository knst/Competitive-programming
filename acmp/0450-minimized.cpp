// knst

#import <bits/stdc++.h>

using namespace std;

int n, i, j, M = 1e9, s, v[9][9], S;
char p[9];

main() {
    for (cin >> n; i < n; ++i)
        for (j = 0; j < n; ++j)
            p[i] = i + 65,
            cin >> s,
            S += v[i][j] = s;

    string P;
    do {
        for (s = i = 0; i < n; ++i)
            s -= v[i][p[i] - 65];

        if (s < M)
            M = s,
            P = p;

    } while (next_permutation(p, p + n));
    cout << P << endl << M + S;
}
