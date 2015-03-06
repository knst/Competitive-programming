#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    --n;
    int count = 0;
    while (n) {
        n /= 2;
        ++count;
    }
    cout << count << endl;
}

