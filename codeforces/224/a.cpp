#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main() {
    string s1;
    string s2;
    cin >> s1 >> s2;
    int index = 0;
    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] == '|')
            index = i;
    }
    int n1 = s1.size();
    int a1 = index;
    int a2 = n1 - index - 1;
    int n2 = s2.size();
    if (a1 - a2 > n2 || a2 - a1 > n2) {
        cout << "Impossible" << endl;
        return 0;
    }
    if ((a1 + a2 + n2) % 2 == 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    int index1 = (a1 + a2 + n2) / 2 - a1;
    cout << s2.substr(0, index1) << s1 << s2.substr(index1, n2 - index1) << endl;


    return 0;
}
