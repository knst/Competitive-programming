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

struct JanuszTheBusinessman
{
    int makeGuestsReturn(vector <int> arrivals, vector <int> departures) {
        int count = 0;
        vector<pair<int,int>> v;
        int n = arrivals.size();
        for (int i = 0; i < n; ++i)
            v.push_back({departures[i], arrivals[i]});
        sort(v.begin(), v.end());
        vector<bool> used(n, false);
        for (int i = 0; i< n; ++i) {
            if (used[i])
                continue;
            ++count;
            int last = v[i].first;
            int mini;
            int Max = -1;
            for (int i = 0; i < n; ++i) {
                if (v[i].second <= last && v[i].first >= last) {
                    if (v[i].first > Max) {
                        mini = i;
                        Max = v[i].first;
                    }
                }
            }
            for (int i = 0; i < n; ++i) {
                if (
                    (v[i].second <= v[mini].first && v[i].first >= v[mini].second) ||
                    (v[i].first >= v[mini].second && v[i].second <= v[mini].first)
                )
                    used[i] = true;
            }
        }
        return count;
    }

};

int main() {

    JanuszTheBusinessman jz;
    cout << jz.makeGuestsReturn(
            {203, 228, 185},
            {232, 257, 213}
            ) << endl;
    cout <<     jz.makeGuestsReturn({2, 10, 6}, {6, 11, 9}) << endl;
    cout <<     jz.makeGuestsReturn(
    {2, 10, 23, 34, 45, 123, 1} ,
    {25, 12, 40, 50, 48, 187, 365}
    ) << endl;
    cout << jz.makeGuestsReturn({166, 318, 203, 280, 264, 64, 228, 144, 185, 352}, {183, 356, 232, 303, 300, 88, 257, 158, 213, 356}) << endl;
    cout << jz.makeGuestsReturn(
            {203, 228, 185},
            {232, 257, 213}
            ) << endl;

}
