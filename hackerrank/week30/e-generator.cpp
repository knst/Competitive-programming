/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/
#include <bits/stdc++.h>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int M = 1000;
//    int M = 4;
    int n = M;
    int q = M * 1000;
    cout << n << ' ' << q << endl;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cout << rand() % M << ' ';
    }
    cout << endl;
    for (int i = 0; i < q; ++i) {
        int x = 0;
        int y = 0;
        do {
            x = rand() % M;
            y = rand() % M;
        } while (x > y);
        cout << x << ' ' << y << ' ' << rand() % M + 1 << ' '<< rand() % M << '\n';

//        cout << rand() % 20 << ' ' << M - 1 - rand() % 20 << ' ' << m << ' ' << rand() % M  << '\n';
    }
    return 0;
}

