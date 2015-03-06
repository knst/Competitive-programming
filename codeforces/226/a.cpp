#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    int c;
    cin >> c;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    int maximal = 0;
    for (int i = 1; i < n; ++i) {
        maximal = max(maximal, v[i-1] - c - v[i]);
    }
    cout << maximal << endl;


}
