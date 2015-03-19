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
    string solve(vector<int> v) {
        string OK = "Sufficient";
        string NOOK = "Insufficient";
        int a = v.size();
        int dn[10000];
        for (auto& i : dn)
            i = 0;
        dn[a] = 1;
        for (int i = a-1; i >= 0; --i)
            for (int j = 1; i + j - 1 < a; ++j) {
                int c= 0;
                for (int k = i; k < i + j; ++k)
                    if (v[k] && v[k] != j)
                        c=  1;
                if (!c)
                    dn[i] += dn[i + j];
            }
        if (dn[0] == 1)
            return OK;
        return NOOK;
    }
};
int main() {
    CountryGroupHard c;
    cout << c.solve({0,2,3,0,0}) << endl;
    cout << c.solve({0, 2, 0}) << endl;
    cout << c.solve({0, 3, 0, 0, 3, 0}) << endl;
    cout << c.solve({0, 3, 3, 3, 3, 0, 2, 0}) << endl;
    cout << c.solve({0,0,3,3,0,0}) << endl;
    cout << c.solve({2,2,0,2,2}) << endl;


}
