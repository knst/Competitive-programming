#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {7, 15, 9, 5, 41, 9, 9, 9};
    int o = 0;
    int i = v.size() - 1;
    int diff = v[i] - v[i-1];
    for (int j = i - 2; j >= 0; --j) {
        diff -= v[i-1] - v[j];
        ++o;
    }
    if (diff)
        cout << -1 << endl;
    else
        cout << o + 1 << endl;
}

