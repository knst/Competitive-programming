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

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int Abs(int x) {
    if (x < 0)
        return -x;
    return x;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int x0;
    cin >> n >> x0;
    vector<pair<int,int>> v(n);
    for (auto &i: v) {
        cin >> i.first >> i.second;
    }
    int minimal = -1;
    for (int i = 0; i < 1001; ++i) {
        bool ok = true;
        for (auto j : v) {
            if ((j.first > i && j.second > i) ||
                    (j.first < i && j.second < i))
                ok = false;
        }
        if (ok) {
            if (minimal == -1) {
                minimal = Abs(x0 - i);
            }
            else
                minimal = min(minimal, Abs(x0 - i));
        }


    }
    cout << minimal << endl;

    return 0;
}
