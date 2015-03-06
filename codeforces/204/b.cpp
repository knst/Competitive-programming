#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    map<int, int> first;
    map<int, int> last;
    map<int, int> delta;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        v.push_back(value);
    }

    for (int i = 0; i < n; ++i) {
        if (first[v[i]] == 0) {
            first[v[i]] = i + 1;
            delta[v[i]] = n + 1;
        } else if (last[v[i]] == 0) {
            last[v[i]] = i + 1;
        } else if (i - last[v[i]] + 1 < delta[v[i]]) {
            delta[v[i]] = i - last[v[i]] + 1;
        }
    }
    vector<pair<int,int> > result;
    for (map<int, int>::const_iterator i = first.begin(); i != first.end(); ++i) {
        int value = i->first;
        int d = delta[value];
        if (d == n + 1) {
            result.push_back(make_pair(value, 0));
        } else {
            bool ok = true;
            bool ended = false;
            int first = i->second;
            while (first + d <= n) {
                first += d;
                if (v[first-1] != value)
                    ended = true;
                if (ended && v[first-1] == value)
                    ok = false;
            }
            if (ok)
                result.push_back(make_pair(value, d));
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i].first << ' ' << result[i].second << endl;
    }
}
