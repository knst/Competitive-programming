#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> count(101);
    for (int i = 0; i < count.size(); ++i) {
        count[i] = 0;
    }
    vector<int> value(n*2);
    for (int i = 0; i < n * 2; ++i) {
        cin >> value[i];
        ++count[value[i]];
    }
    multiset<int> a;
    multiset<int> b;
    for (int i = 0; i < count.size(); ++i) {
        if (count[i] >= 2) {
            count[i] = 2 - count[i];
            a.insert(i);
            b.insert(i);
        }
    }
    for (int i = 0; i < count.size(); ++i) {
        if (count[i] == 1) {
            if (a.size() > b.size())
                b.insert(i);
            else
                a.insert(i);
            count[i] = 0;
        }
    }
    cout << a.size() * b.size() << endl;
    for (int i = 0; i < count.size(); ++i) {
        while (count[i] != 0) {
            if (a.size() < n) {
                a.insert(i);
            } else {
                b.insert(i);
            }
            ++count[i];
        }
    }

    for (int i = 0; i < value.size(); ++i) {
        int v = value[i];
        if (a.find(v) != a.end()) {
            cout << 1 << ' ';
            a.erase(a.find(v));
        } else if (b.find(v) != b.end()) {
            cout << 2 << ' ';
            b.erase(b.find(v));
        } else {
            cerr << "wtf" << endl;
        }
    }
    return 0;


}
