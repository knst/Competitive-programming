#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    sort(v.begin(), v.end());
    if (n == 1) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 2) {
        set<int> result;
        result.insert(2 * v[0] - v[1]);
        result.insert(2 * v[1] - v[0]);
        int i = (v[1] + v[0]) / 2;
        if (v[1] - i == i - v[0])
            result.insert(i);
        cout << result.size() << endl;
        for (const auto& i : result)  {
            cout << i << ' ';
        }
        cout << endl;
        return 0;
    }
    if (n > 2) {
        set<int> diffs;
        for (int i = 1; i < n; ++i) {
            diffs.insert(v[i] - v[i-1]);
        }
        if (diffs.size() > 2) {
            cout << 0 << endl;
            return 0;
        }
        if (diffs.size() == 1) {
            set<int> result;
            int diff = *(diffs.begin());
            result.insert(v[0] - diff);
            result.insert(v[n-1] + diff);
            cout << result.size() << endl;
            for (const auto& i : result)
                cout << i << ' ';
            cout << endl;
        }
        if (diffs.size() == 2) {
            int diff1 = *(diffs.begin());
            int diff2 = *++(diffs.begin() );
            if (diff1 * 2 != diff2 && diff2 * 2 != diff1) {
                cout << 0 << endl;
                return 0;
            }
            int diff1_count = 0;
            int diff2_count = 0;
            int diff1_last = 0;
            int diff2_last = 0;
            for (int i = 1; i < n; ++i) {
                if (v[i] - v[i - 1] == diff1) {
                    diff1_count++;
                    diff1_last = i;
                }
                if (v[i] - v[i-1] == diff2) {
                    diff2_count++;
                    diff2_last = i;
                }
            }
            if (diff1_count > 1 && diff2_count > 1) {
                cout << 0 << endl;
                return 0;
            }
            int diff = diff1;
            int diff_last = diff1_last;
            if (diff2_count == 1) {
                diff = diff2;
                diff_last = diff2_last;
            }
            int i = (v[diff_last] + v[diff_last - 1]) / 2;
            if (diff >= diff2 && diff >= diff1 && v[diff_last] - i == i - v[diff_last - 1]) {
                cout << 1 << endl << i << endl;
            } else {
                cout << 0 << endl;
            }
        }

    }
    return 0;
}
