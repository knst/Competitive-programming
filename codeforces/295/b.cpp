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
}

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

using Point = pair<int,int>;

bool Can(
    const vector<vector<size_t>>& neightbors,
    const set<size_t>& alls,
    const vector<Point>& dPoses,
    size_t index
) {
    size_t i = index;

    if (alls.find(i) == alls.end())
        return false;

    Point p = dPoses[i];
    for (auto j : neightbors[i]) {
        if (alls.find(j) == alls.end())
            continue;
        Point p1 = dPoses[j];
        if (p1.second < p.second)
            continue;
        int count = 0;
        for (auto k : neightbors[j]) {
            if (alls.find(k) == alls.end())
                continue;
            Point p2 = dPoses[k];
            if (p2.second < p1.second)
                ++count;
        }
        if (count < 2)
            return false;
    }
    return true;
}
constexpr uint64_t MOD = 1000000009;
int main() {
    std::ios_base::sync_with_stdio(false);

    size_t m;
    cin >> m;

    set<size_t> frees;
    set<size_t> alls;
    vector<vector<size_t>> neightbors(m + 1);
    map<Point,size_t> poses;
    vector<Point> dPoses(m + 1);
    for (size_t i = 1; i <= m; ++i) {
        alls.insert(i);
        int x;
        int y;
        cin >> x >> y;
        poses[{x, y}] = i;
        dPoses[i] = {x, y};
    }

    for (size_t i = 1; i <= m; ++i) {
        int x = dPoses[i].first;
        int y = dPoses[i].second;
        int p1 = poses[{x-1, y-1}];
        int p2 = poses[{x, y-1}];
        int p3 = poses[{x+1, y-1}];

        if (p1) {
            neightbors[i].push_back(p1);
            neightbors[p1].push_back(i);
        }
        if (p2) {
            neightbors[i].push_back(p2);
            neightbors[p2].push_back(i);
        }
        if (p3) {
            neightbors[i].push_back(p3);
            neightbors[p3].push_back(i);
        }

    }


    for (auto i : alls) {
        bool can = Can(neightbors, alls, dPoses, i);
        if (can)
            frees.insert(i);
    }
    bool getMax = true;

    uint64_t result = 0;
    while (!frees.empty()) {
        size_t next = *(frees.begin());
        if (getMax)
            next = *(frees.rbegin());
        getMax = !getMax;

        frees.erase(next);
        alls.erase(next);
        for (auto i : neightbors[next]) {
            if (Can(neightbors, alls, dPoses, i))
                frees.insert(i);
            else
                frees.erase(i);
            for (auto j : neightbors[i]) {
                if (Can(neightbors, alls, dPoses, j))
                    frees.insert(j);
                else
                    frees.erase(j);
            }
        }
        result = (result * m + next - 1) % MOD;
    }
    cout << result << endl;


    return 0;
}
