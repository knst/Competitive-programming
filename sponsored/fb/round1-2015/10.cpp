#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

void solve(const vector<int> primacity) {
    int a;
    int b;
    int k;
    cin >> a >> b >> k;
    int result = 0;
    for (int i = a; i<= b; ++i) {
        if (primacity[i] == k)
            ++result;
    }
    cout << result << endl;


}
int main() {
    int MAX = 1000 * 1000 * 10;
    vector<int> primacity(MAX + 1);
    vector<int> prime;
    for (size_t i = 2; i <= 1000 * 1000 * 10; ++i) {
        int value = i;
        int count = 0;
        for (size_t p = 0; p < prime.size() && prime[p] * prime[p] <= value; ++p) {
            if (value % prime[p] == 0) {
                do {
                    value /= prime[p];
                } while (value % prime[p] == 0);
                ++count;
            }
        }
        if (value != 1)
            ++count;
        if (count == 1)
            prime.push_back(i);
        primacity[i] = count;
    }

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve(primacity);
    }
}
