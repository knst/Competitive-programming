#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int K;
    cin >> K;
    while(K--) {
        char arr[8][8];
        int x1 = -1;
        int x2 = -1;
        int y1 = -1;
        int y2 = -1;

        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cin >> arr[i][j];
                if (arr[i][j] == 'K')
                    if (x1 == -1) {
                        x1 = i;
                        y1 = j;
                    } else {
                        x2 = i;
                        y2 = j;
                    }
            }
        }
        if (x1 % 4 != x2 % 4 ||
            y1 % 4 != y2 % 4) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i< 8; ++i) {
            for (int j = 0; j< 8; ++j) {
                if (i % 2 == x1 %2 && j % 2 == y2 % 2 && (arr[i][j] == '.' || arr[i][j] == 'K')) {
                    cout << "YES" << endl;
                    goto End;
                }
            }
        }
        cout << "NO" << endl;
End: continue;

    }

}
