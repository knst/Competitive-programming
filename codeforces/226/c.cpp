#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

void eratosfen(vector<bool> &m, const vector<int>& count_mask, vector<long long>& count) {
    int n = m.size();
    int firstPrime = 2;
    m[0] = false;
    m[1] = false;
    for (int i = firstPrime; i < n; ++i)
        m[i] = true;

    for (int i = firstPrime; i < n; ++i) {
        if (m[i]) {
            count[i] += count_mask[i];
            for (int j = i + i; j < n; j += i) {
                m[j] = false;
                count[i] += count_mask[j];
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    int max_x = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
        max_x = max(max_x, x[i]);
    }
    vector<int> count_mask(max_x + 1);
    vector<long long> count(max_x + 1);
    for (int i = 0; i < n; ++i)
        count_mask[x[i]]++;
    vector<bool> prime_mask(max_x + 1);
    eratosfen(prime_mask, count_mask, count);

    count[1] = 0;
    for (int i = 1; i <= max_x; ++i) {
        count[i] = count[i] + count[i-1];
    }
    int m;
    cin >> m;
    int t = x[0];
    for (int i = 0; i < m; ++i) {
        int x;
        int y;
        cin >> x >> y;
        if (x > max_x) {
            cout << 0 << endl;
        } else {
            y = min(y, max_x);
            cout << count[y] - count[x-1] << endl;
        }
    }
}
