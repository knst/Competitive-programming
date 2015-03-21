#include<iostream>
#include<cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cout << 5000 << ' ' << 20 << endl;
    vector<int> a;
    for (size_t i = 0; i < 5000; ++i) {
        a.push_back(i + 1);
    }
    sort(a.begin(), a.end());
    for (auto i : a)
        cout << i << ' ';
    cout << endl;
    cout << 20 << endl;
    for (size_t i = 0; i < 20; ++i)
        cout << rand() % 10000 + 1 << endl;
}
