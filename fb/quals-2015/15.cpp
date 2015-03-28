#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n < 10) {
        cout << n << ' ' << n << endl;
        return;
    }

    int minimum = n;
    int maximum = n;

    vector<int> digits;
    while (n) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());

    for (size_t i = 0; i < digits.size(); ++i) {
        for (size_t j = i; j < digits.size(); ++j) {
            if (i == 0 && digits[j] == 0)
                continue;

            swap(digits[i], digits[j]);
            int value = 0;
            for (auto i : digits) {
                value = value * 10 + i;
            }
            minimum = min(minimum, value);
            maximum = max(maximum, value);
            swap(digits[i], digits[j]);
        }
    }
    cout << minimum << ' ' << maximum << endl;
}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
