#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (size_t i = 0; i < n; ++i)
        v[i] = i;
    random_shuffle(v.begin(), v.end());
    cout << 1 << endl << n << endl;
    for (auto i : v)
        cout << i << ' ';
    cout << endl;
}
