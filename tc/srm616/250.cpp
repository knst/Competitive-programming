#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct WakingUp {
    int maxSleepiness(vector<int> period, vector<int> start, vector<int> volume, int D) {
        int nok = 1;
        int n = period.size();
        set<int> periods;
        for (int i = 0; i < n; ++i) {
            periods.insert(period[i]);
        }
        for (auto i : periods)
            nok *= i;
        int value = 0;
        int minimum = 0;
        vector<int> vals;
        for (int i =0 ; i < n; ++i)
            vals.push_back(period[i] - start[i]);

        for (int i = 1; i <= nok; ++i) {
            value += D;
            for (int j = 0; j < n; ++j) {
                vals[j]++;
                if (vals[j] == period[j]) {
                    vals[j] = 0;
                    value -= volume[j];
                }
            }
            minimum = min(minimum, value);
        }
        if (value < 0)
            return -1;
        return -minimum;
    }
};


int main() {
    WakingUp a;
    cout << a.maxSleepiness({2, 3}, {1,2}, {3,4}, 3) << endl;
    cout << a.maxSleepiness({1}, {1}, {17}, 17) << endl;
    cout << a.maxSleepiness({1}, {1}, {23}, 17) << endl;
    cout << a.maxSleepiness({9, 2, 5, 5, 7}, {6,1,4,1,6}, {71,66,7,34,6}, 50) << endl;
    cout << a.maxSleepiness(
            {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10},
            {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10},
            {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,8,9,10}, 100) << endl;



    return 0;
}

