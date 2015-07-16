#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                cout << k;
            else
                cout << 0;
            cout << ' ';
        }
        cout << endl;
    }
    return 0;

}



