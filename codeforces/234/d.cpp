#include<iostream>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    int m;
    int k;
    cin >> n >> m >> k;

    int index = 0;
    vector<int> vk(k);
    vector<int> v(n);
    for (int i=  0; i < k; ++i) {
        cin>>vk[k];
        for (int j = 0; j < vk[k]; ++j) {
            v[index++] = i;
        }
    }
    vector<vector<int>> M(k);
    for (int i = 0; i < k; ++i) {
        M[i].resize(k);
        for (int j = 0; j < k; ++j)
            M[i][j] = -1;
        if (vk[i] == 1)
            M[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int a;
        int b;
        int c;
        cin >> a >> b >> c;
        --a;
        --b;
        M[v[a]][v[b]] = c;
        M[v[b]][v[a]] = c;
    }

    for (int c = 0; c < k; ++c) {
        for (int a = 0; a < k; ++a) {
            for (int b =  0; b < k; ++b) {
                if (M[a][c] != -1 && M[c][b] != -1) {
                    if (M[a][b] == -1)
                        M[a][b] = M[a][c] + M[c][b];
                    else
                        M[a][b] = min(M[a][b], M[a][c] + M[c][b]);
                }
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < k; ++i) {
        if (M[i][i] != 0)
            ok = false;
    }
    if (ok) {
        cout << "Yes" << endl;
        for (int i = 0; i < k; ++i) {
            for (int j= 0; j < k; ++j)
                cout << M[i][j] << ' ';
            cout << endl;
        }
    } else
        cout << "No" << endl;



}
