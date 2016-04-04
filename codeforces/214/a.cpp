#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int n;
    int k;
    cin >> n >> k;
    vector< pair<int,int> > v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].first;
    for (int i = 0; i < n; ++i)
        cin >> v[i].second;
    set<pair<int, int> > s;
    set<pair<int,int> > s_new;
    for (int i = 0; i < n; ++i) {
        s_new.insert(v[i]);
        for (set<pair<int,int> >::iterator it = s.begin(); it != s.end(); ++it) {
            int a = it->first + v[i].first;
            int b = it->second + v[i].second;
            s_new.insert(make_pair(a, b));
        }
        s = s_new;
    }
    int maximal = -1;
    for (set<pair<int,int> >::iterator it = s.begin(); it != s.end(); ++it) {
        if (it->first == it->second * k)
            maximal = max(maximal, it->first);
    }
    cout << maximal << endl;
}
