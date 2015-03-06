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
    int count = 0;
    while (v >= minimal * 2) {
        v -= minimal;
        count ++;
    }
    int maximal = -1;
    for (int i = 0; i < 9; ++i)
        if (a[i] <= v)
            maximal = i + 1;
    cout << maximal;
    for (int i = 0; i < count; ++i)
        cout << minimalI + 1;
    cout << endl;


    return 0;
}
