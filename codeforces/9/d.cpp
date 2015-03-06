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

map<tuple<int,int,int>, long long> m;

long long getResult(int Min, int Max, int depth) {
    if (Min >= Max) {
        if (depth <= 0)
            return 1;
        return 0;
    }

    tuple<int,int,int> t(Min, Max, depth);

    auto it = m.find(t);
    if (it != m.end())
        return it->second;

    long long count = 0;
    for (int K = Min; K <= Max; ++K) {
        count += getResult(Min, K - 1, - 1) * getResult(K+1, Max, depth - 1);
        count += getResult(Min, K - 1, depth - 1) * getResult(K+1, Max, - 1);
        count -= getResult(Min, K - 1, depth - 1) * getResult(K+1, Max, depth - 1);
    }
    m[t] = count;
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int h;
    cin >> n >> h;
    cout << getResult(1, n, h-1) << endl;


    return 0;
}
