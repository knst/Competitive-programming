/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int GetTime(const string& s)
{
    return ((s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] - '0') * 10 + s[4] - '0';
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    vector<pair<int, int>> v;
    for (size_t i = 0; i < n; ++i) {
        string in, out;
        cin >> in >> out;
        v.push_back({GetTime(in), -1});
        v.push_back({GetTime(out), 1});
    }
    sort(v.begin(), v.end());
    size_t maximal = 0;
    size_t count = 0;
    for (auto i : v) {
        count -= i.second;
        maximal = max(maximal, count);
    }
    cout << maximal << endl;




    return 0;
}
