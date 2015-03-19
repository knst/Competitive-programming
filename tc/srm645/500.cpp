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

    ArmyTeleportation at;
    cout << at.ifPossible({0, 1}, {0, 1}, {2, 1}, {4, 3}, {2, 3, 2}, {0, 1, 3}) << endl;
    cout << at.ifPossible({0, 1, 2},
            {2, 4, 6},
            {3, 5, 6},
            {1, 1, 0},
            {3, 1, -2},
            {4, 2, 10}) << endl;
    cout << at.ifPossible({0, 1},
            {1, 2},
            {1, 2},
            {2, 3},
            {0, 0, 0},
            {5, 3, 8}) << endl;
    cout << at.ifPossible({6, -5, 1},
            {3, -10, -7},
            {0, 11, 5},
            {-5, 8, 5},
            {0, -5, 4},
            {-8, -9, -4}) << endl;

}
