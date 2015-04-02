#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    string p;
    string q;
    string v;
    cin >> p >> q >> v;

    int n = p.size();
    int m = q.size();
    int l = v.size();
    vector< vector< vector<int> > > a;
    a.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        a[i].resize(m + 1);
        for (int j = 0; j <= m; ++j) {
            a[i][j].resize(l + 1);
            for (int k = 0; k <= l; ++k)
                a[i][j][k] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k < l; ++k) {
                if (p[i-1] == q[j-1]) {
                    if (p[i-1] == v[k]) {
                        a[i][j][k + 1] = a[i-1][j-1][k] + 1;
                        cout << "+1 +1" << endl;
                    } else {
                        if (p[i-1] != v[0]) {
                            a[i][j][0] = max(a[i-1][j-1][k] + 1, a[i][j][0]);
                            cout << "!=" << endl;
                        } else {
                            a[i][j][1] = max(a[i][j][1], a[i-1][j-1][k] + 1);
                            cout << "==" << endl;
                        }
                        cout << "+1" << endl;
                    }
                } else {
                    a[i][j][k] = max(a[i -1][j][k], a[i][j-1][k]);
                }
            }
        }
    }
    int maximal = 0;
    int maximalK = 0;
            for (int k = 0; k <= l; ++k) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
                cout << a[i][j][k] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    for (int i = 0; i < l; ++i) {
        if (a[n][m][i] > maximal) {
            maximal = a[n][m][i];
            maximalK = i;
        }
    }
    if (maximal == 0) {
        cout << 0 << endl;
        return 0;
    }
    cout << maximal << ' ' << maximalK << endl;

    string result;
    int K = maximalK;
    while (n && m) {
        if (p[n - 1] == q[m - 1]) {
            result = p[n - 1] + result;
            n--;
            m--;
            if (K > 0 && p[n - 1] == v[K-1])
                --K;
        } else {
            if (a[n-1][m][K] == a[n][m][K]) {
                --n;
            } else {
                --m;
            }
        }
    }
    cout << result << endl;
}
