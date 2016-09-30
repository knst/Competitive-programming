#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (v[j-1] > v[j]) {
                swap(v[j-1], v[j]);
                ++count;
            }
        }
    }
    int result = 0;
    while (count > 1) {
        result += 4;
        count -= 2;
    }
    if (count == 1)
        result += 1;
    cout << result << endl;
}
