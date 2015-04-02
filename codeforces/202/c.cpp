#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long sum = 0;
    long long maximum = 0;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        maximum = max(maximum, a);
        sum += a;
    }
    cout << max(maximum, (sum - 1) / (n - 1) + 1) << endl;
}

