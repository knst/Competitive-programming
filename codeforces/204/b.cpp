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

        if (first[v[i]] == 0) {
            first[v[i]] = i + 1;
            delta[v[i]] = 0;
        } else {
            int newDelta = i - last[v[i]] + 1;
            if (delta[v[i]] == 0)
                delta[v[i]] = newDelta;
            if (newDelta != delta[v[i]])
                delta[v[i]] = -1;
        }
        last[v[i]] = i + 1;
    }
    vector<pair<int,int> > result;
    for (map<int, int>::const_iterator i = first.begin(); i != first.end(); ++i) {
        int value = i->first;
        int d = delta[value];
        if (d == 0) {
            result.push_back(make_pair(value, 0));
        } else if (d != -1) {
            result.push_back(make_pair(value, d));
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i].first << ' ' << result[i].second << endl;
    }
}
