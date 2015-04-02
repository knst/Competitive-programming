#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

pair<long long, pair<long long,int> > calc(int value, const vector<int>& a, const vector< set<int> >& eTopo) {
    if (eTopo[value].empty())
        return make_pair<long long, pair<long long,int> >(0LL, make_pair(a[value], 1));

    int n = eTopo[value].size();
    vector< pair<long long, pair<long long,int> > > cache(n);
   
    int temp_count = 0;
    for (set<int>::const_iterator i = eTopo[value].begin();
         i != eTopo[value].end();
         ++i)
        cache[temp_count++] = calc(*i, a, eTopo);
    
    long long minimal = cache[0].second.first * cache[0].second.second;
    for (int i = 0; i < n; ++i) 
        minimal = min(minimal, cache[i].second.first * cache[i].second.second);
    
    int count = 0;
    long long result = 0;
    for (int i = 0; i < n; ++i) {
        count += cache[i].second.first * cache[i].second.second;
        result += cache[i].first + (cache[i].second.first * cache[i].second.second - minimal);
    }
    cout << value << ": " << result << ' ' << minimal << ' ' << count << endl;
    return make_pair(result, make_pair(count, 1));
}

int main()
{
    int n;
    cin >> n;

    vector<int> a;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    set<int> v;
    vector< set<int> > e;
    e.resize(n);
    for (int i = 1; i < n; ++i) {
        v.insert(i);
        int a;
        int b;
        cin >> a >> b;
        --a;
        --b;
        e[a].insert(b);
        e[b].insert(a);
    }
    vector<int> level;
    level.push_back(0);
    
    vector< set<int> > eTopo;
    eTopo.resize(n);

    while (!v.empty()) {
        vector<int> newLevel;
        for (int i = 0; i < level.size(); ++i) {
            int vertex = level[i];
            while (!e[vertex].empty()) {
                int a = vertex;
                int b = *(e[vertex].begin());
                e[a].erase(b);
                e[b].erase(a);

                newLevel.push_back(b);
                eTopo[vertex].insert(b);
//                cout << "add: " << vertex << ' ' << b << endl;
            }
            v.erase(vertex);
        }
        level = newLevel;
    }
    pair<long long, pair<long long,int> > result = calc(0, a, eTopo);
    cout << result.first << endl;

    return 0;
}
