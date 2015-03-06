#include <iostream>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    int correctMin = 101;
    int correctMax = -1;
    int incorrectMin = 101;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        correctMin = min(correctMin, value);
        correctMax = max(correctMax, value);
    }
    for (int i = 0; i < m; ++i) {
        int value;
        cin >> value;
        incorrectMin = min(incorrectMin, value);
    }
    int result = max(correctMax, correctMin * 2);
    if (result >= incorrectMin) {
        cout << -1 << endl;
    } else
        cout << result << endl;



}
