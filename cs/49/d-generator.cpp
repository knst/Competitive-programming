#include <iostream>
using namespace std;

int main() {
    int t;
    int a;
    cin >> t >> a;
    cout << t << ' ' << a << endl;
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < a; ++j) {
            if (j == 0) cout << 99;
            else cout << 100;
            cout << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
