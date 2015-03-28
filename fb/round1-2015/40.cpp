#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <stack>

using namespace std;

void solve() {
    size_t n;
    cin >> n;
    vector<size_t> v(n);
    for (auto&  i: v)
        cin >> i;
    vector<size_t> level(n);
    level[0] = 1;
    for (size_t i = 1; i < n; ++i) {
        stack<size_t> indexes;
        indexes.push(i);
        while (!level[v[indexes.top()]-1])
            indexes.push(v[indexes.top()]-1);
        while (!indexes.empty()) {
            level[indexes.top()] = level[v[indexes.top()]-1] + 1;
            indexes.pop();
        }
    }
    for (auto i : level)
        cerr << i << ' ';
    cerr << endl;
    vector<int> levelCount(n);
    for (auto i : level)
        levelCount[i-1]++;
    for (auto i : levelCount)
        cerr << i << ' ';
    cerr << endl;
    long long sum1 = 0;
    long long sum2 = 0;
    for (size_t i = 0; i < n; ++i) {
        if (i % 2) {
            sum1 += levelCount[i];
            sum2 += levelCount[i] * 2;
        } else {
            sum1 += levelCount[i] * 2;
            sum2 += levelCount[i];
        }
        cerr << "sum12: " << sum1 << ' ' << sum2 << endl;
    }
    cout << min(sum1, sum2) << endl;
}
int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
