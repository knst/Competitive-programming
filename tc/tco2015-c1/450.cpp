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

struct UnrelatedPaths
{
    int maxUnrelatedPaths(vector <int> parent) {
        size_t n = parent.size();
        vector<bool> mask(n + 1);
        for (auto i  : parent)
            mask[i] = true;
        size_t count = 0;
        for (auto i : mask)
            if (!i)
                ++count;
        return count;
    }
};


int main() {

    UnrelatedPaths u;
    cout << 2 << endl << u.maxUnrelatedPaths({0, 1, 1, 2, 3} ) << endl;
    cout << 4 << endl << u.maxUnrelatedPaths({0, 0, 1, 1, 2, 2}
            ) << endl;
    cout << 1 << endl << u.maxUnrelatedPaths( {0, 1, 2, 3} ) << endl;
    cout << 17 << endl  << u.maxUnrelatedPaths( {0,1,1,2,2,2,4,6,5,0,10,5,12,12,10,4,16,12,5,3,20,12,11,21,9,5,1,20,15,24,6,8,15}) << endl;
    cout << 19 << endl << u.maxUnrelatedPaths( {0,1,1,1,1,0,2,5,1,6,7,10,5,10,8,5,16,14,8,14,4,14,15,21,0,24,11,1,9,18,13,20,6,28,19,28,14,11,38,26,25,10,23,43}) << endl;

}
