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

int dfs(int j, const vector<vector<int>>& edges, vector<bool>& mask, int depth, pair<int,int> denied) {
    int maxLen = depth;
    if (mask[j])
        return maxLen;
    mask[j] = true;
    for (auto i : edges[j]) {
        if (i == denied.first && j == denied.second)
            continue;
        if (i == denied.second && j == denied.first)
            continue;
        maxLen = max(maxLen, dfs(i, edges, mask, depth + 1, denied));
    }
    return maxLen;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    vector<pair<int,int>> edgeSet;
    for (int i= 0; i < n-1; ++i) {
        int x;
        int y;
        cin >> x >> y;
        --x;
        --y;
        if (x > y)
            swap(x, y);
        edges[x].push_back(y);
        edges[y].push_back(x);
        edgeSet.push_back({x, y});
    }

    int result = 0;
    for (int i = 0; i < n-1; ++i) {
        vector<bool> group(n, false);
        dfs(0, edges, group, 0, edgeSet[i]);

        vector<int> path1;
        vector<int> path2;
        for (int start = 0; start < n; ++start) {
            vector<bool> mask = group;
            path1.push_back(dfs(start, edges, mask, 0, edgeSet[i])-1);
            mask = group;
            mask.flip();
            path2.push_back(dfs(start, edges, mask, 0, edgeSet[i])-1);
        }
/*        cout << "denied: " << edgeSet[i].first << ' ' << edgeSet[i].second << endl;
        cout << "path1: ";
        for (auto a : path1)
            cout << ' ' << a;
        cout << endl << "path2: ";
        for (auto a : path2)
            cout << ' ' << a;
        cout << endl;
        */
        for (auto a : path1) {
            for (auto b : path2) {
                if (a > 0 && b > 0)
                    result = max(result, a * b);
            }
        }
    }
    cout << result << endl;

    return 0;
}
