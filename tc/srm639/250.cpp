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


struct AliceGame
{
    long long findMinimumValue(long long x, long long y) {
        if (x == 0 && y == 0)
            return 0;
        long long z = x + y;
        long long sum = 0;
        long long k = 0;
        while (sum < z) {
            sum += 1 + k * 2;
            ++k;
        }
        if (sum > z) {
            return -1;
        }

        if (x == 0)
            return k;
        if (y == 0)
            return k;

        long long kb = 0;
        {
            long long sumb = 0;
            while (sumb < y) {
                sumb += 1 + kb * 2;
                kb++;
            }
        }
        --k;
        long long ka = 0;
        {
            long long suma = 0;
            while (suma < x) {
                suma += 1 + (k - ka) * 2;
                ++ka;
            }
        }
        cerr << '\t' << ka << ' ' << kb << ' ' << k << endl;
        if (ka % 2 && x % 2 ==0)
            ++ka;
        if (kb % 2 && y % 2 == 0)
            --kb;
        return max(ka, k-kb);
    }



};

int main() {
    AliceGame a;
    cout <<a.findMinimumValue(8, 17) << endl;
    cout <<a.findMinimumValue(4, 4) << endl;
    cout <<a.findMinimumValue(17, 8) << endl;
    cout <<a.findMinimumValue(0, 0) << endl;
    cout << a.findMinimumValue(9, 9) << endl;
    cout << a.findMinimumValue(500000, 500000) << endl;


}
