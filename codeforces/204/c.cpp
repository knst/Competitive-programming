#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    n *= 2;

    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        double ai;
        cin >> ai;
        v[i] = ai * 1000;
        if (v[i] >= 0)
            v[i] = v[i] % 1000;
        if (v[i] < 0)
            v[i] = (0 - v[i]) % 1000;
    }

    sort(v.begin(), v.end());
    long long delta = 0;
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        cout  << v[i] << ' ' << v[j] << endl;
        delta += v[i];
        if (v[j] != 0)
            delta -= (1000 - v[j]);
    }
    delta = max(delta, -delta);
    cout << delta / 1000 << '.' << delta % 1000 << endl;
    return 0;
}
