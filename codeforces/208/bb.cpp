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
    for (int i = 1; i < n; ++i) {
        if (v[i] > v[i-1]) {
            if (v[i] > xmax) {
                cout << "y" << endl;
                return 0;
            }
    cout << "no" << endl;



    return 0;
}
