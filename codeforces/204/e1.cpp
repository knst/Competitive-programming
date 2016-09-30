#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        v[i] = max(v[i], -v[i]);
    }

    for (int i = 0; i < n; ++i) {
        int count1 = 0;
        int count2 = 0;
        for (int j = 0; j < i; ++j) {
            if (v[j] > v[i])
                ++count1;
            if (v[j] > - v[i])
                ++count2;
        }
        for (int j = i + 1; j < n; ++j) {
            if (v[j] < v[i])
                ++count1;
            if (v[j] < -v[i])
                ++count2;
        }
        if (count1 >= count2)
            v[i] = -v[i];
    }

    int answer = 0;
    for (int i = 0; i < n; ++i) 
        for (int j = 1; j < n; ++j) {
            if (v[j - 1] > v[j]) {
                swap(v[j - 1], v[j]);
                ++answer;
            }
        }
    cout << answer << endl;
    return 0;
}
