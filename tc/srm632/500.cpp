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


struct PotentialGeometricSequence{
    int numberOfSubsequences(vector<int> d) {
        int n  = d.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                bool ok = true;
                if (j - 1 > i) {
                    int D = d[i+1] - d[i];
                    for (int k = i+1; k <= j; ++k) {
                        if (d[k] - d[k-1] != D)
                            ok = false;
                    }
                }
                if (ok)
                    ++count;
            }
        }
        return count;
    }
};

int main() {
    PotentialGeometricSequence p;
    cout << p.numberOfSubsequences({0, 1,2}) << endl;
    cout << p.numberOfSubsequences({1,2,4}) << endl;
    cout << p.numberOfSubsequences({3,2,1,0}) << endl;
    cout << p.numberOfSubsequences({1,2,4,8,16}) << endl;
    cout << p.numberOfSubsequences({1,3,5,5,5,5,64,4,23,2,3,4,5,4,3}) << endl;

}
