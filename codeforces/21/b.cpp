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
//test speed
/*
namespace std {
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}; */
namespace std {
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
};

void TestExit(int a, int b) {
    if (a == 0 && b == 0)
        cout << "-1" << endl;
    else if (a == 0 && b != 0)
        cout << "0" << endl;
    else
        cout << 1 << endl;
    exit(0);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int a1, b1, c1;
    int a2, b2, c2;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    if (a1 != 0)
        TestExit(a1 * b2 - a2 * b1, a2 * c1 - a1 * c2);
    if (b1 != 0)
        TestExit(a2 * b1, -c2 * b1 + b2 * c1);
    if (c1 != 0) {
        cout << 0 << endl;
        exit(0);
    }
    if (a2 == 0 && b2 == 0 && c2 != 0)
        cout << 0 << endl;
    else
        cout << -1 << endl;



    return 0;
}
