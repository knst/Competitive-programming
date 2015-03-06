#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    string control = "<3";
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        control = control + s + "<3";
    }
    string sms;
    cin >> sms;
    int controlIndex = 0;
    for (int i = 0; i < sms.size(); ++i) {
        if (sms[i] == control[controlIndex]) {
            ++controlIndex;
        }
        if (controlIndex == control.size()) {
            cout << "yes" << endl;
            return 0;
        }
    }
    cout << "no" << endl;

    return 0;
}
