#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<vector<int> > e(n);
    for (int i = 0; i < n - 1; ++i) {
        int a;
        int b;
        cin >> a >> b;
        --a;
        --b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    vector<bool> use(n);
    for (int i = 0; i < n; ++i)
        use[i] = 0;
    vector<vector<int> > byLevel;
    vector<int> first;
    first.push_back_back(i);
    int level = 0;
    use[0] = true;
    while (!byLevel[level].empty()) {
        vector<int> newq;
        for (int i = 0; i < byLevel[level].size(); ++i) {
            int value = byLevel[level][i];
            if (use[value])
                continue;
            use[value] = true;
            for (int j = 0; j < e[value].size(); ++j)
                newq.push_back(e[value][j]);
        }
        byLevel.push_back(newq);
        level++;
    }
    while (level >=0 ) {




    }






    return 0;
}
