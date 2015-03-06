#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    long long mCount = 0;
    long long fCount = 0;
    long long maximum = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'M') {
            ++mCount;
            --fCount;
            if (fCount < 0)
                fCount = 0;
        }
        if (s[i] == 'F') {
            if (mCount) {
                maximum = max(maximum, mCount + fCount);
                ++fCount;
            }
        }
    }
    cout << maximum << endl;

    return 0;


}
