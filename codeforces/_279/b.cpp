/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

namespace std {
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
};

void Write(const vector<pair<int,int>>& v, int i, int x, int y, int z) {
    for (int j = 0; j < i - 2; ++j)
        cout << v[j].second << ' ';
    cout << v[i+x].second << ' ' << v[i+y].second << ' ' << v[i+z].second;
    for (int j = i + 1; j < v.size(); ++j)
        cout << ' ' << v[j].second;
    cout << endl;

}
void Write2(const vector<pair<int,int>>& v, int s, int e, int x1, int x2, int y1, int y2) {
    for (int j = 0; j < s - 1; ++j)
        cout << v[j].second << ' ';
    cout << v[s+x1].second << ' ' << v[s+x2].second << ' ';
    for (int j = s + 1; j < e - 1; ++j)
        cout << v[j].second << ' ';
    cout << v[e+y1].second << ' ' << v[e+y2].second << ' ';
    for (int j = e + 1; j < v.size(); ++j)
        cout << v[j].second << ' ';
    cout << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        v.push_back({x, i+1});
    }
    sort(v.begin(), v.end());
    for (int i = 2; i < n; ++i) {
        if (v[i].first == v[i-1].first && v[i].first == v[i-2].first) {
            cout << "YES" << endl;
            Write(v, i, -2, -1, 0);
            Write(v, i, -2, 0, -1);
            Write(v, i, -1, 0, -2);
            return 0;
        }
    }
    int s = 1;
    while (s < n && v[s].first != v[s-1].first)
        ++s;
    int e = s + 1;
    while (e < n && v[e].first != v[e-1].first)
        ++e;
    if (e >= n) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    Write2(v, s, e, 0, -1, 0, -1);
    Write2(v, s, e, -1, 0, 0, -1);
    Write2(v, s, e, -1, 0, -1, 0);


    return 0;
}

