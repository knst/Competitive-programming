#include <vector>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
        v[i].second = i + 1;
    }
    vector<pair<int,int>> e;
    sort(v.begin(), v.end());
    {
        int count = 0;
        if (v[0].first != 0 || v[1].first == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    v.push_back(make_pair(-1, -1));
    int count = 1;
    int prev = 0;
    for (int i = 1; i < n;) {
        if (v[i].first != v[prev].first + 1) {
            cout << -1 <<endl;
            return 0;
        }
        int start = i;
        int end = i;
        while (v[start].first == v[end].first)
            ++end;
        int count2 = end - start;
        if (count * k < count2) {
            cout << -1 << endl;
            return 0;
        }
        int vc = 0;
        for (int j = 0; j < count2; ++j) {
            e.push_back(make_pair(v[prev].second, v[i + j].second));
            ++vc;
            if (vc == k) {
                vc = 0;
                prev++;
            }

        }
        i = end;
        prev = start;
    }
    cout << e.size() << endl;
    for (auto i : e) {
        cout << i.first << ' ' << i.second << endl;
    }




}
