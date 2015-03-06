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

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, -1, 0, 1};

const int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int m;
    cin >> n >> m;
    int v = max(n, m);
    switch (v) {
        case 1:
            cout << "1/1" << endl;
            break;
        case 2:
            cout << "5/6" << endl;
            break;
        case 3:
            cout << "2/3" << endl;
            break;
        case 4:
            cout << "1/2" << endl;
            break;
        case 5:
            cout << "1/3" << endl;
            break;
        case 6:
            cout << "1/6" << endl;
            break;
    }

    return 0;
}
