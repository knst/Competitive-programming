#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int k;
    cin >> k;
    int s;
    cin >> s;
    if (s == 0 && k != 1) {
        cout << "No solution";
    } else {
        cout << s;
        for (int i = 1; i < k; ++i) {
            cout << "0";
        }
    }
    cout << endl;

    return 0;
}
