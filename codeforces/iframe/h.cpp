#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef pair<pair<int,int>, int> Pos;

int main() {
    int n;
    cin >> n;
    map<string,Pos> m;
    for (int i = 0; i < n; ++i) {
        string a;
        string b;
        string c;
        cin >> a >> b >> c;
        m[a].first.first++;
        m[b].first.second++;
        m[c].second++;
    }
    vector<pair<Pos,string>> v;
    for (auto i : m) {
        v.push_back(make_pair(i.second, i.first));
    }
    for (auto& i : v) {
        i.first.first.first = n - i.first.first.first;
        i.first.first.second = n - i.first.first.second;
        i.first.second = n - i.first.second;
    }
    sort(v.begin(), v.end(), std::less<pair<Pos,string>>());
    int pos = 1;
    for (int index = 0; index < v.size(); ++index) {
        if (index && v[index].first != v[index-1].first)
            pos = index + 1;
        cout << pos << ' ' << v[index].second << ' ' << n -v[index].first.first.first << ' ' << n-v[index].first.first.second << ' ' << n-v[index].first.second << endl;
    }
}
