#include <vector>
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int64_t n, k, b;
        cin >> n >> k >> b;
        // n by b.
        // store: k
        bool sum2_ok = false;
        int64_t sum1 = 0;
        int64_t sum2 = 0;
        for (int64_t i = 1; i <= b; ++i) {
            sum1 += i;
            sum2 += k - i + 1;
            if (sum2 >= n)
                sum2_ok = true;
        }
        if (sum1 <= n && sum2_ok) {
           vector<int64_t> result;
            if (k == b) {
                for (int64_t i = 1; i <= b; ++i)
                    result.push_back(i);
            } else {
                int64_t last = b;
                while (sum1 <= n) {
                    sum1 -= last;
                    sum1 += k - (b - last);
                    --last;
                }
                ++last;
                sum1 -= k - (b - last);
                for (int64_t i = 1; i < last; ++i) {
                    result.push_back(i);
                }
                if (n - sum1 != 0) {
                    result.push_back(n - sum1);
                }
                for (int64_t i = last + 1; i <= b; ++i) {
                    result.push_back(k - (b - i));
                }
            }
            cout << result.front();
            for (size_t i = 1; i < result.size(); ++i) {
                cout << ' ' << result[i];
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
