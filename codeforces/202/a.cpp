#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int c25 = 0;
    int c50 = 0;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        if (value == 25)
            c25++;
        if (value == 50) {
            c25--;
            c50++;
        }
        if (value == 100) {
            if (c50 > 0)
                --c50;
            else
                c25 -= 2;
            c25--;
        }
        if (c25 < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
