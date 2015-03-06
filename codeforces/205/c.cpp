#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    int totalSum = 0;
    int maxSum = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            maxSum = max(maxSum + a[i], totalSum);
        }
        totalSum += a[i];
    }
    cout << maxSum << endl;

    return 0;


}
