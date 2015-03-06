#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int Sort(vector<int> &a) {
    int count = 0;
    int n = a.size();
    for (int i = 1; i< n; ++i) {
        int j = i;
        while (j > 0 && a[j] < a[j-1]) {
            swap(a[j], a[j-1]);
            ++count;
            --j;
        }
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    vector<vector<int> > a(n);
    for (int i = 0; i < n; ++i) {
        a[i].resize(n);
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (v[j] >= v[i])
                count++;
            a[i][j] = count;
//            cout << a[i][j] << ' ';
        }
//        cout << endl;
    }
//    cout << endl;
    int minimal = 0;
    int count = 0;
    int I = 0;
    int J = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int delta = -(a[i][i] + a[j][j] - a[i][j] - a[j][i]);
            if (delta < minimal) {
                minimal = delta;
                count = 0;
                I = i;
                J = j;
            }
            if (delta == minimal)
                ++count;
        }
    }
    swap(v[I], v[J]);
    cout << Sort(v) << ' ' << count << endl;


}
