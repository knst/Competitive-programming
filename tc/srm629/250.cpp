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


struct RectangleCovering {
    int test(int W, int H, vector<int> ws, vector<int> hs) {
        vector<int> v;
        int n = ws.size();
        for (int i = 0; i < n; ++i) {
            int l = 0;
            if (ws[i] > W && hs[i] > l) {
                l = hs[i];
            }
            if (hs[i] > W && ws[i] > l) {
                l = ws[i];
            }
            if (l > 0)
                v.push_back(l);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int sum = 0;
        int count = 0;
        for (size_t i = 0; sum <= H && i < v.size(); ++i) {
            ++count;
            sum += v[i];
        }
        if (sum > H)
            return count;
        return -1;
    }
    int minimumNumber(int w, int h, vector<int> ws, vector<int> hs) {
        int a1 = test(w, h, ws, hs);
        int a2 = test(h, w, ws, hs);
        if (a1 == -1)
            return a2;
        if (a2 == -1)
            return a1;
        return min(a1, a2);
    }
};

int main() {
    RectangleCovering p;
    cout << p.minimumNumber(5, 5, {8,8,8},{2,3,4}) << endl;
    cout << p.minimumNumber(10, 10, {6,6,6,6},{6,6,6,6}) << endl;
    cout << p.minimumNumber(5, 5, {5}, {5}) << endl;
    cout << p.minimumNumber(3, 5, {6}, {4}) << endl;
    cout << p.minimumNumber(10000, 5000, {12345,12343,12323,12424,1515,6666,6789,1424,11111,25},
            {1442,2448,42,1818,3535,3333,3456,7890,1,52}) << endl;

}
