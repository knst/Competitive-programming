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
    vector<int> v(n);
    vector<int> used(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        used[i] = 0;
    }
    sort(v.begin(), v.end());
    int index = n - 1;
    int insert_index = n / 2 - 1;
    int count = 0;
    while (index > 0 && insert_index >= 0) {
        while (index > 0 && used[index])
            --index;
        while (insert_index >= 0 && (insert_index >= index || used[insert_index] || 2 * v[insert_index] > v[index]))
            --insert_index;
        if (index > 0 && insert_index >= 0 && index > insert_index &&  !used[index] && !used[insert_index] && v[index] >= 2 * v[insert_index]) {
            used[index] = 1;
            used[insert_index] = 1;
            count++;
            --index;
        }
    }
    cout << n - count << endl;

    return 0;
}
