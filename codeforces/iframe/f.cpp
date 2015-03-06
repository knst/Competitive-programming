#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int prev = 0;
    cin >> prev;
    int maximal = prev;
    int count = 0;
    for (int i = 1; i < n; ++i) {
        int value;
        cin >> value;
        if (value > maximal) {
            ++count;
            maximal = value;
        }
    }
    cout << count;
}
