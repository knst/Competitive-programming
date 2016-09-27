#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        bool ok = false;
        for (size_t i = s.size() - 1; !ok && i > 0; --i) {
            if (s[i] > s[i - 1]) {
                size_t j = i;
                for (size_t k = i; k < s.size(); ++k)
                    if (s[k] < s[j] && s[k] > s[i - 1])
                        j = k;
                swap(s[j], s[i-1]);
                ok = true;
                sort(s.begin() + i, s.end());
                cout << s << endl;
            }
        }
        if (!ok)
            cout << "no answer" << endl;
    }
    return 0;
}

