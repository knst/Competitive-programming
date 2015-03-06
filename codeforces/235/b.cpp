#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main() {
    int x;
    int k;
    cin >> x >> k;
    vector<int> v(x);
    v[x-1] = 1;
    for (int i = 0; i < k; ++i) {
        int t;
        cin >> t;
        int x2;
        cin >> x2;
        v[x2-1] = 1;
        int x1;
        if (t == 1) {
            cin >> x1;
            v[x1-1] = 1;
        }
    }
    int minimal = 0;
    int maximal = 0;
    for (int i = 0; i < x; ++i) {
        int j = i;
        while (v[j] == 0) {
            ++j;
            ++maximal;
        }
        minimal += (j - i + 1) / 2;
        i = j;
    }
    cout << minimal << ' ' << maximal << endl;
    

    return 0;
}
