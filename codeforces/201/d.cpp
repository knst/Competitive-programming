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
            for (int k = 0; k <= l; ++k) {
                a[i][j][k] = 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 0; k < l; ++k) {
                if (p[i] == q[j]) {
                    if (p[i] == v[k])
                        a[i][j][k + 1] = a[i][j][k] + 1;
                    else
                        a[i][j][k] = a[i][j][k];
                } else {
                    a[i][j][k] = max(a[i -1][j][k], a[i][j-1][k]);
                }
            }
        }
    }
    int maximal = -1;
    int maximalK = 0;
    for (int i = 0; i < l; ++i) {
        if (a[n][m][i] > maximal) {
            maximal = a[n][m][i];
            maximalK = i;
        }
    }
    if (maximal == -1) {
        cout << 0 << endl;
        return 0;
    }

    string result;
    int K = maximalK;
    while (n && m) {
        if (p[n - 1] == q[m - 1]) {
            result = result + p[n - 1];
            cout << (p[n - 1] + 0);
            n--;
            m--;
            cout << n << ' ' << m << endl;
            if (p[n - 1] == v[K])
                --K;
        } else {
            if (a[n-1][m][K] == a[n][m][K]) {
                --n;
            } else {
                --m;
            }
            cout << n << ' ' << m << endl;


        }


    }
    cout << result << endl;


}
