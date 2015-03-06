#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int f(const vector<int>& b, int n) {
    if (n == 1)
        return 0;
    int result = 0;
    for (auto i : b) {
        while (n % i == 0) {
            --result;
            n /= i;
        }
    }
    for (int j = 2; j * j <= n; ++j) {
        while (n % j == 0) {
            ++result;
            n /= j;
        }
    }
    if (n != 1)
        ++result;
    return result;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (auto& i : a)
        cin >> i;
    for (auto& i : b)
        cin >> i;

    vector<int> g(n);
    g[0] = a[0];
    for (int i = 1; i < n; ++i) {
        g[i] = gcd(g[i-1], a[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        int F = f(b, g[i]);
        if (F < 0) {
            for (int j = 0; j <= i; ++j) {
                a[j] /= g[i];
                g[j] /= g[i];
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; ++i) {
        result += f(b, a[i]);
    }
    cout << result << endl;
    return 0;
}
