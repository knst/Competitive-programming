#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int t(int need, int x, int b, int w) {
    int count = 0;
    while(need) {
        while (b < x) {
            b += w - x;
            ++count;
        }
        b -= x;
        --need;
    }
    return count;
}

int main() {
    long long a, b, w, x, c;
    cin >> a >> b >> w >> x >> c;
    if (c <= a) {
        cout << 0 << endl;
        return 0;
    }
    if (b / x >= c - a) {
        cout << c - a << endl;
        return 0;
    }
    long long delta = b / x;
    b = b % x;
    long long need = c - a - delta;
    long long count = 0;
    count = (need * x - b + w - x -1) / (w - x);
    if (0 && count != t(need, x, b, w)) {
        cout << "FAIL" << need << ' ' << x << ' ' << b << ' ' << w << endl;
    }
    cout << delta + count + c - a - delta << endl;


    return 0;
}
