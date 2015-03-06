#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main() {
    long long n;
    long long m;
    long long l;
    long long r;
    int p;
    cin >> n >> m;
    ++n, ++m;
    cin >> l >> r;
    cin >> p;

    long long result = 0;
    for (long long dx = 0; dx <= n; ++dx) {
        long long top2 = min(m, r * r - dx * dx);
        long long top = sqrt(top2);
        if (top * top > top2)
            --top;
        if ((top + 1) * (top + 1) <= top2)
            ++top;
        long long low2 = max(0LL, l * l - dx * dx);
        long long low = sqrt(low2);
        while (low * low < low2)
            ++low;
        if (top - low <= 0)
            continue;
        result += (top - low + 1) * (n - dx + 1) % p;
    }
    cout << result % p << endl;
    return 0;
}
