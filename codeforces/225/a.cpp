#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<int> m1(n);
    vector<int> m2(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        m1[i]=m2[i]= 0;
    }
    long long sum1 = 0;
    long long s1 = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == 1)
            s1++;
        if (v[i] == 0)
            sum1 += s1;
    }
    long long sum2 = 0;
    long long s2 = 0;
    for (int i = n-1; i >= 0; --i) {
        if (v[i] == 0)
            s2++;
        if (v[i] == 1)
            sum2 += s2;
    }
    cout << sum1 << endl;




    return 0;
}
