#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int a_i = 0; a_i < n; a_i++){
           cin >> a[a_i];
        }
        int first = 0;
        int last = n;
        while (first < last) {
            int newLast = 0;
            int newFirst = n;
            for (int j = first + 1; j < last; ++j) {
//                if (a[j] + 1 == a[j-1]) {
                if (a[j] < a[j-1]) {
                    swap(a[j], a[j-1]);
                    newLast = j;
                }
            }
            for (int j = last - 1; j > first; --j) {
//                if (a[j] + 1 == a[j-1]) {
                if (a[j] < a[j-1]) {
                    swap(a[j], a[j-1]);
                    newFirst = j;
                }
            }
            first = newFirst;
            last = newLast;
        }
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            if (a[i-1] > a[i]) ok = false;
        }
        if (ok) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

