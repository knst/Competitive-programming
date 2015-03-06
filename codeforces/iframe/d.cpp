#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> v;
    for (int i=  0; i < n; ++i) {
        v.push_back(i);
        cin >> a[i];
    }
    do {
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < i; ++j) {
                if (v[j] > v[i])
                    ++count;
            }
            if (count != a[v[i]])
                ok = false;
        }
        if (ok) {
            for (int i = 0; i < n; ++i)
                cout << static_cast<char>('a' + v[i]);
            cout << endl;
        }


    } while (next_permutation(v.begin(), v.end()));
}
