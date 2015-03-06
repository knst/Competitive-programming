#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<pair<int,int>> d(n);
    for (int i = 0; i < n; ++i) {
        cin >> d[i].first;
        d[i].second = i + 1;
    }
    sort(d.begin(), d.end());

    if (d[0].first != 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int,int>> output;
    vector<int> previous = {0};
    int processed = 1;
    int depth = 1;
    while (processed < n) {
        vector<int> next;
        size_t index = 0;
        int count = 0;
        if (d[processed].first != depth) {
            cout << -1 << endl;
            return 0;
        }
        while (processed < n && d[processed].first == depth) {
            ++count;
            if (count > k-1 && depth != 1) {
                count = 1;
                ++index;
            }
            if (count > k) {
                count = 1;
                ++index;
            }

            if (index == previous.size()) {
                cout << -1 << endl;
                return 0;
            }

            next.push_back(processed);
            output.push_back(make_pair(d[previous[index]].second, d[processed].second));

            processed++;
        }
        previous = next;
        ++depth;
    }

    cout << output.size() << endl;
    for (auto& i : output)
        cout << i.first << ' ' << i.second << endl;
    
    return 0;
}
