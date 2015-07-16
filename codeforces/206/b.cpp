#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int c1;
    int c2;
    int c3;
    int c4;
    cin >> c1 >> c2 >> c3 >> c4;
    int minimal = c4;
    
    int n;
    int m;
    cin >> n >> m;
    vector<int> vn(n);
    vector<int> vm(m);
    for (int i = 0; i < n; ++i) {
        cin >> vn[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> vm[i];
    }

    int sum1 = 0;
    for (int i = 0; i < n; ++i)
        sum1 += min(c2, c1 * vn[i]);
    int sum2 = 0;
    for (int i = 0; i < m; ++i)
        sum2 += min(c2, c1 * vm[i]);
    sum1 = min(sum1, c3);
    sum2 = min(sum2, c3);
    minimal = min(minimal, sum1 + sum2);
    cout << minimal << endl;




    return 0;
}
