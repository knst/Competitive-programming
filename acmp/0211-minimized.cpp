// knst

#import <bits/stdc++.h>

using namespace std;

size_t n, m, X, Y, A, B, d, i, j, a, b, f, v[900][900], M[900][900], q[99999][3], S, E,
D[] = {-1, 0, 0, 1, -1, 0};

char c;

main() {
    cin >> m >> n;

    for (i; i < n * m; ++i)
        cin >> c,
        v[i / m + 1][i % m + 1] = c;


    while (cin >> Y >> X >> B >> A, X) {
        f = S = 0;
        E = 1;

        memcpy(M, v, 2e6);

        **q = X;
        q[0][1] = Y;

        M[X][Y] = 0;
        while (!f * (E - S)) {
            i = q[S][0];
            j = q[S][1];
            d = q[S][2];
            ++S;
            if (i == A && j == B)
                f = d;
            for (c = 0; M[i][j] != 88 &&  c < 4; ++c) {
                a = i + D[c];
                b = j - D[c + 2];
                if (a < n + 2 && b < m + 2)
                    q[E][0] = a,
                    q[E][1] = b,
                    q[E][2] = d + 1,
                    ++E;
            }
            M[i][j] = 88;
        }
        cout << f << "\n";
    }
}
