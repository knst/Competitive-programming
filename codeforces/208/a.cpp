#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    set< pair<int,int> > s;
    for (int i = 1; i < n; ++i) {
        for (set<pair<int,int> > ::const_iterator it = s.begin(); it != s.end(); ++it) {
            int x1 = v[i-1];
            int x2 = v[i];
            if (x1 > x2)
                swap(x1, x2);
            int y1 = it->first;
            int y2 = it->second;
            if (y1 > y2)
                swap(y1, y2);

            if (x1 < y1 && x2 > y1 && x2 < y2) {
                cout << "yes" << endl;
                return 0;
            }
            if (y1 < x1 && y2 > x1 && y2 < x2) {
                cout << "yes" << endl;
                return 0;
            }


        }
        s.insert(make_pair(v[i-1], v[i]));
    }
    cout << "no" << endl;



    return 0;
}
