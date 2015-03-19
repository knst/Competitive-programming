#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <cmath>
#include <stack>
using namespace std;

struct CountryGroupHard
{
    string solve(vector<int> a) {
        string OK = "Sufficient";
        string NOOK = "Insufficient";
        size_t n = a.size();
        bool changed = false;
        do {
            changed = false;
            for (size_t i = 0; i < n; ++i) {
                if (a[i] > 0) {
                    size_t left = i;
                    size_t right = i;
                    while (left > 0 && (a[left-1] == 0 || a[left-1] == a[i]))
                        --left;
                    while (right + 1 < n && (a[right+1] == 0 || a[right+1] == a[i]))
                        ++right;
                    if (right - left == static_cast<size_t>(a[i] - 1)) {
                        changed = true;
                        for (size_t j = left; j <= right; ++j)
                            a[j] = -1;
                        cerr << "type-1" << endl;
            for (auto i : a)
                cout << i << ' ';
            cout << endl;
                    }
                }
                if (a[i] == 1) {
                    a[i] = -1;
                    changed = true;
            for (auto i : a)
                cout << i << ' ';
            cout << endl;
                        cerr << "type-2" << endl;
                }
                if (a[i] == 0) {
                    if (i == 0 || a[i-1] == -1)
                        if (i == n - 1 || a[i + 1] == -1) {
                            a[i] = -1;
                            changed = true;
            for (auto i : a)
                cout << i << ' ';
            cout << endl;
                        cerr << "type-3" << endl;
                        }
                }
            }
        } while (changed);
        for (size_t i = 0; i < n; ++i)
            if (a[i] != -1)
                return NOOK;
        return OK;
    }
};
int main() {
    CountryGroupHard c;
    cout << c.solve({0,2,3,0,0}) << endl;
    cout << c.solve({0, 2, 0}) << endl;
    cout << c.solve({0, 3, 0, 0, 3, 0}) << endl;
    cout << c.solve({0,0,3,3,0,0}) << endl;
    cout << c.solve({2,2,0,2,2}) << endl;


}
