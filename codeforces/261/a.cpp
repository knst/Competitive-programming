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
};

int Abs(int a) {
    return a >= 0 ? a : -a;
}

void Exit(int value) {
    cout << value << endl;
    exit(0);
}
int main() {
    std::ios_base::sync_with_stdio(false);

    int x1;
    int y1;
    int x2;
    int y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int d1 = Abs(x1-x2);
    int d2 = Abs(y1-y2);

    if (d2 != 0 && d1 != 0 && d1 != d2) {
        Exit(-1);
    }

    int d = d1;
    if (d2 != 0)
        d = d2;


    int X = min(x1, x2);
    int Y = min(y1, y2);

    set<pair<int,int>  > s;
    s.insert(make_pair(X, Y));
    s.insert(make_pair(X + d, Y + d));
    s.insert(make_pair(X, Y + d));
    s.insert(make_pair(X + d, Y));
    for (auto p : s ) {
        if (p.first == x1 && p.second == y1)
            continue;
        if (p.first == x2 && p.second == y2)
            continue;
        cout << p.first << ' ' << p.second << ' ';
    }




    return 0;
}

