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

struct DevuAndPlantingTrees
{
     int maximumTreesDevuCanGrow(vector<string> garden) {
         size_t n = garden[0].size();
         vector<int> v1(n + 2);
         for (size_t i = 0; i < n; ++i) {
             if (garden[0][i] == '*'
              || garden[1][i] == '*')
                 v1[i + 1] = 1;
         }
         cout << garden[0] << endl;
         cout << garden[1] << endl;
         for (size_t i = 1; i <= n; ++i)
             cout << v1[i];
         cout << endl;
         int count = 0;
         for (size_t i = 1; i <= n; ++i) {
             if (v1[i-1] == 0 && v1[i + 1] == 0) {
                 v1[i] = 1;
             }
             if (v1[i])
                 ++count;
        }
         for (size_t i = 1; i <= n; ++i)
             cout << v1[i];
         cout << endl;
         return count;
     }
};


int main() {

    DevuAndPlantingTrees t;
    cout << t. maximumTreesDevuCanGrow({"..", ".."}) << endl;
    cout << t. maximumTreesDevuCanGrow({"..", ".*"}) << endl;
    cout << t. maximumTreesDevuCanGrow({"...", "..*"}) << endl;
    cout << t. maximumTreesDevuCanGrow({".....*..........", ".*.......*.*..*."}) << endl;
//    cout << t. maximumTreesDevuCanGrow() << endl;

}
