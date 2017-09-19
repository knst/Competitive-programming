#include <iostream>
#include <set>
using namespace std;

int main() {
    int sum = 0;
    int next = 0;
    set<int> values;
    std::string s;
    cin >> s;
    while (cin >> next) {
        if (values.find(next) != values.end()) {
            cout << "WTF " <<endl;
        }
        values.insert(next);
        sum ^= next;
    }
    cout << sum << endl;
}
