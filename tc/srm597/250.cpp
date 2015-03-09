#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;


class LittleElephantAndString {
public:
    int getNumber(string a, string b) {
        int n = a.size();
        if (b.size() != n)
            return -1;
        vector<char> va;
        vector<char> vb;
        for (int i = 0; i < n; ++i) {
            va.push_back(a[i]);
            vb.push_back(b[i]);
        }
        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());
        if (va != vb)
            return -1;
        int count = 0;
        int index = n - 1;
        int jndex = n - 1;
        while (index >= 0 && jndex >= 0) {
            if (a[index] == b[jndex]) {
                index--; jndex--;
                ++count;
            } else {
                index--;
            }
        }
        return n - count;
    }
};

int main() {
    string a = "AAAB";
    string b = "BAAA";
    int j = a.size() - 1;
    int i;
    for (i = a.size() - 1; i>=0; --i) {
        while (j >= 0) {
            if (a[j] == b[i])
                break;
            --j;
        }
        if (j < 0)
            break;
        else {
            --j;
        }
    }
    cout << i + 1;
    return 0;

    LittleElephantAndString l;
    cout << l.getNumber("ABC", "CBA") << endl;
    cout << l.getNumber("A", "B") << endl;
    cout << l.getNumber("AAABBB", "BBBAAA") << endl;
    cout << l.getNumber("EDCBA", "ABCDE") << endl;
    cout << l.getNumber("A", "A") << endl;
    cout << l.getNumber("AAAAAB", "BAAAAA") << endl;
    cout << l.getNumber("BAAAAA", "AAAAAB") << endl;


}
