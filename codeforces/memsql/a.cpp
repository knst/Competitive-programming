#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct rect {
    int x1;
    int x2;
    int y1;
    int y2;
    bool in(const rect& r) {
        if (x1 < r.x1)
            return false;
        if (x2 > r.x2)
            return false;
        if (y1 < r.y1)
            return false;
        if (y2 > r.y2)
            return false;
        return true;
    }
};


int main()
{
    int n;
    cin >> n;
    rect r[5];
    vector<int> xi;
    vector<int> yi;

    for (int i = 0; i < n; ++i) {
        cin >> r[i].x1;
        cin >> r[i].y1;
        cin >> r[i].x2;
        cin >> r[i].y2;
        xi.push_back(r[i].x1);
        xi.push_back(r[i].x2);
        yi.push_back(r[i].y1);
        yi.push_back(r[i].y2);

    }
    sort(xi.begin(), xi.end());
    sort(yi.begin(), yi.end());
    int xin = xi.size();
    int yin = yi.size();
    if (yi[xin - 1] - yi[0] != xi[xin - 1] - xi[0]) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < xin - 1; i++) {
        for (int j = 0; j < yin - 1; j++) {
            rect R;
            R.x1 = xi[i];
            R.x2 = xi[i + 1];
            R.y1 = yi[j];
            R.y2 = yi[j + 1];
            bool ok = false;
            for (int N = 0; N < n; ++N) {

                if (R.in(r[N]))
                    ok = true;
            }
            if (!ok) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}

