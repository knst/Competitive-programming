#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;
    if (m > 2 * (n + 1) ||
        n > (m + 1)) {
        cout << -1 << endl;
        return 0;
    }
    string output;
    while (n>0 && m>0) {
        output += '0';
        output += '1';
        --n;
        --m;
    }
    if (n > 0) {
        output = output + '0';
        --n;
    }
    if (m > 0)
        output = '1' + output;
    if (m > 1)
        output = '1' + output;
    if (m > 2)
        output = output + '1';
    m -= 3;
    for (const auto& it : output) {
        cout << it;
        if (it == '0' && m > 0) {
            cout << '1';
            --m;
        }
    }
    cout << endl;


    return 0;
}
