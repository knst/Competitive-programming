#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    long long l;
    long long r;
    long long ql;
    long long qr;
    cin >> n >> l >> r >> ql >> qr;
    vector<int> w(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        sum += w[i];
    }
    long long suml = 0;
    long long sumr = sum;
    long long ans = sum * (l + r) + n * (l + r);
    for (int i = 0; i <= n; ++i) {
        int L = i;
        int R = n - i;
        long long cur = 0;
        if (i < n / 2) {
            cur = (R - L - 1) * qr;
        }
        if (i > n / 2) {
            cur = (L - R - 1) * ql;
        }
//        cout << cur << ' ' << suml << ' ' << suml * l << ' ' << sumr << ' ' << sumr * r << ' ' << cur + l * suml + r * sumr << endl;
        ans = min(ans, cur + l * suml + r * sumr);

        if (i < n) {
            suml += w[i];
            sumr -= w[i];
        }
    }
    cout << ans << endl;
    return 0;
}

