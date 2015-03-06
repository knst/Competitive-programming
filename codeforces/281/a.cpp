/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

namespace std {
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
}

int main() {
    std::ios_base::sync_with_stdio(false);

    string hname;
    string gname;
    cin >> hname >> gname;
    int n;
    cin >> n;
    map<int,int> my;
    map<int,int> mr;

    for (int i = 0; i < n; ++i) {
        int minute;
        cin >> minute;
        char c;
        cin >> c;
        int m;
        cin >> m;
        char color;
        cin >> color;
        if (c == 'a')
            m += 1000;
        if (mr[m])
            continue;
        if (color == 'r' || my[m]) {
            mr[m] = minute;
            if (m > 1000) {
                cout << gname << ' ';
            } else
                cout << hname << ' ';
            cout << m % 1000 << ' ';
            cout << minute << endl;;
        }
        if (color == 'y')
            my[m] = minute;
    }


    return 0;
}

