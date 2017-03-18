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

    int n;
    int q;
    cin >> n >> q;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    for(int a0 = 0; a0 < q; a0++){
        int left;
        int right;
        int x;
        int y;
        cin >> left >> right >> x >> y;
        y = y % x;
        int count = 0;
        for (int i = left; i <= right; ++i) {
            if (a[i] < x) {
                if (a[i] == y) {
                    ++count;
                }
            } else if (a[i] % x == y) {
                ++count;
            }
        }
        cout << count << '\n';
    }
    return 0;
}
