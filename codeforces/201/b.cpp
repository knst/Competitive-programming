#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i =0; i < n; ++i)
        cin >> v[i];
    int k = 0;
    int u = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == i)
            ++k;
        else {
            if (i == v[v[i]])
                ++u;
        }

    }
    if (k == n) {
        cout << n << endl;
        return 0;
    }
    if (u > 1) {
        cout << k + 2 << endl;
        return 0;
    }
    cout << k + 1 << endl;
    return 0;


}
