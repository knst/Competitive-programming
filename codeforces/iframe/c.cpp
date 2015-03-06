#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<int> v;
    v.insert(3);
    for (int i = 0; i < n; ++i) {
        set<int> q;
        for (auto j : v) {
            if (j == 10 || j == 8)
                cout << j << endl;
            q.insert(j + 1);
            q.insert(j + 3);
            q.insert(j * j);
        }
        v = q;

    }
}
