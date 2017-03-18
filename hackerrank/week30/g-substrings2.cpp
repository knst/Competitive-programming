/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/
#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t n;
    size_t q;
    cin >> n;
    cin >> q;
    vector<string> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    while (q--) {
        size_t x;
        size_t y;
        cin >> x >> y;
        string& b = v[x].size() > v[y].size() ? v[x] : v[y];
        string& a = v[x].size() > v[y].size() ? v[y] : v[x];

        int best = 0;
        vector<int> T(a.size() + 1);
        for (size_t G = 0; G < a.size(); ++G) {
            if (a.size() - G < best) break;
            // K: a.substr(G);
            // S: b
            int Ksize = a.size() - G;
            int Ssize = b.size();
            T[0] = -1;

            for(int i = 1; i <= Ksize; i++) {
                int pos = T[i - 1];
                while(pos != -1 && a[G + pos] != a[G + i - 1]) pos = T[pos];
                T[i] = pos + 1;
            }

            int sp = 0;
            int kp = 0;
            while(sp < Ssize) {
                while(kp != -1 && (kp == Ksize || a[G+kp] != b[sp])) kp = T[kp];
                kp++;
                sp++;
                best = max(best, kp);
            }
        }
        cout << best << endl;
    }
}
