#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int v;
    cin >> v;
    int a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 9; ++i) {
        cin >> a[i];
    }
    int minimal = a[0] + a[1];
    int minimalI = -1;
    for (int i = 0; i < 9; ++i) {
        if (a[i] <= minimal) {
            minimal = a[i];
            minimalI = i;
        }
    }
    int n = v / minimal;
    v -= n * minimal;
    if (n == 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        int maximal = 0;
        for (int j = 0; j < 9; ++j) {
            if (a[j] <= v + minimal)
                maximal = j + 1;
        }
        cout << maximal;
        v +=  minimal - a[maximal - 1];
    }
    cout << endl;
    return 0;
}
