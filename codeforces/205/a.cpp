#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    int st = 0;
    int sb = 0;
    bool diff = false;
    for (int i = 0; i < n; ++i) {
        int a;
        int b;
        cin >> a >> b;
        if (a % 2 == 1)
            ++st;
        if (b % 2 == 1)
            ++sb;
        if (b % 2 != a % 2)
            diff = true;
    }
    if (st % 2 == 0 && sb % 2 == 0) {
        cout << 0 << endl;
        return 0;
    }
    if (st % 2 == 0 || sb % 2 == 0 || !diff) {
        cout << -1 << endl;
        return 0;
    }
    cout << 1 << endl;
    return 0;


}
