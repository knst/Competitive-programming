#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct EllysSortingTrimmer{
    string getMin(string s, int l) {
        vector<char> v;
        for (int i = 1; i < s.size(); ++i) {
            v.push_back(s[i]);
        }
        sort(v.begin(), v.end());
        vector<char> v2;
        v2.push_back(s[0]);
        for (int i = 0; i < l-1; ++i) {
            v2.push_back(v[i]);
        }
        sort(v2.begin(), v2.end());
        string result;
        for (int i = 0; i < l; ++i)
            result += v2[i];
        return result;
    }
};

int main() {
    EllysSortingTrimmer m;
    cout << m.getMin("ABRACADABRA", 5) << endl;
    cout << m.getMin("TOPCODER", 3) << endl;
    cout << m.getMin("ESPRIT", 3)<< endl;
    cout << m.getMin("F", 1) << endl;


}
