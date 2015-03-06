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

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int t;
    cin >> n >> t;
    map<pair<int,int>,long long> values;
    values[{0,0}] = 1;
    for (int i = 0; i < n; ++i) {
        map<pair<int,int>,long long> values2;
        for (auto i : values) {
            auto j = i.first;
            int last = j.first % 10;
            int last2 = j.first % 100 / 10;
            for (int next = 1; next <= 4; ++next) {
                if (next == last)
                    continue;
                if (last2 == 0 && last > next)
                    continue;
                if (next < last && last2 < last) {
                    values2[{j.first % 1000 * 10 + next, j.second + 1}] += i.second;;
                } else {
                    values2[{j.first % 1000 * 10 + next, j.second}] += i.second;
                }
            }
        }
        values = values2;
//        for (auto i : values) {
//            cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
//        }
//        cout << endl;
    }
    long long result = 0;
    for (auto i : values) {
        if (i.first.first % 10 > i.first.first % 100 / 10)
            continue;
        if (i.first.second == t)
            result += i.second;
    }
    cout << result << endl;




    return 0;
}
