#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n;
    int x;
    cin >> n >> x;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        sum += v;
    }
    if (sum < 0)
        sum = -sum;
    cout << (sum + x - 1) / x << endl;
    return 0;
}
