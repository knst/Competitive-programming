#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int abs(int a) {
    return max(a, -a);
}

int main() {
    int n;
    cin >> n;
    n *= 2;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        double x;
        cin >> x;
        if (x >= 0) {
            v[i] = x * 1000.0 + 0.1;
            v[i] = v[i] % 1000;
        } else {
            v[i] = - x * 1000.0 + 0.1;
            v[i] = 1000 - v[i] % 1000;
        }
    }
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        sum += v[i];
        if (v[i] != 0)
            ++count;
    }
    int minimum = 1000 * 1000 * 1000;
    for (int i = max(0, count - n / 2); i <= min(n / 2, count); ++i) {
        minimum = min(minimum, abs(1000 * i - sum));
    }
    printf("%.3f", minimum / 1000.0);
//    cout << minimum / 1000 << '.' << minimum % 1000 / 100 << minimum % 100 / 10 << minimum % 10;
}



