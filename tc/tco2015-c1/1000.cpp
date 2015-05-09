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

struct DevuAndBeautifulSubstrings
{
    long long countBeautifulSubstrings(int n, int cnt)
    {
        vector<int> shifts;
        for (size_t i = 1; i <= 50; ++i)
            shifts.push_back(i * (i + 1) / 2);
        vector<vector<long long>> count(n + 1, vector<long long>(cnt + 1, 0));
        count[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= cnt; ++j) {
                for (int k = 0; k < shifts.size(); ++k) {
                    if (i - k -1 >= 0 && j - shifts[k] >= 0)
                        count[i][j] += count[i - k - 1][j - shifts[k]];
                }
            }
        }
/*        for (auto i : count) {
            for (auto j : i)
                cout << j << ' ';
            cout << endl;
        } */
        return count[n][cnt] * 2;

    }
};


int main() {

    DevuAndBeautifulSubstrings d;
    cout << 2 << endl << d.countBeautifulSubstrings( 2, 2) << endl;
    cout << 0 << endl << d.countBeautifulSubstrings( 2, 1) << endl;
    cout << 4 << endl << d.countBeautifulSubstrings(3, 4 ) << endl;
     cout << 642 << endl << d.countBeautifulSubstrings(15, 35 ) << endl;
    cout      << 32357325751902 << endl << d.countBeautifulSubstrings(50, 94) << endl;

}
