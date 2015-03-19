#include <iostream>

using namespace std;

int main() {
    long long M = 1000LL * 1000 * 1000 * 1000;
    long long x = 0;
    long long y = 0;
    long long k = 0;
    while (x < M - 2 * k - 10 && y < M - 2 * k - 10) {
        x += 1 + k * 2;
        y += 3 + k * 2;
        k += 2;
    }
    cout << x << ' ' << y << endl;
}

