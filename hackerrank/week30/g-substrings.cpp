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
        string& a = v[x].size() > v[y].size() ? v[x] : v[y];
        string& b = v[x].size() > v[y].size() ? v[y] : v[x];

        size_t best = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            for (size_t j = 0; j < b.size(); ++j) {
                for (size_t k = 0; i + k < a.size() && j + k < b.size(); ++k) {
                    if (a[i + k] != b[j + k]) break;
                    if (k + 1 > best) best = k + 1;
                }
            }
        }
        cout << best << endl;
    }
}
