#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 30000; ++i) {
        int k;
        cin >> k;
        int sum = 0;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            sum += x;
        }
        cout << sum << endl << endl;
    }
}

