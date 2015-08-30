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
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
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

vector<size_t> S;
void dfs_sol2(const vector<vector<size_t>>& edges, vector<bool>& mask, size_t index)
{
    if (mask[index])
        return;
    mask[index] = true;
    if (edges[index].size() > 2)
        S.push_back(index);
    for (size_t i = 0; i < edges[index].size(); ++i)
        dfs_sol2(edges, mask, edges[index][i]);
    if (edges[index].size() > 2)
        S.push_back(index);
}
#if 0
size_t dfs_last(const vector<vector<size_t>>& edges, vector<bool>& mask, size_t index)
{
    if (mask[index])
        return -1;
    mask[index] = true;
    size_t last = -1;
    if (edges[index].size() > 3)
        last = index;
    for (size_t i = 0; i < edges[index].size(); ++i) {
        size_t last_i = dfs_last(edges, mask, edges[index][i]);
        if (last_i != -1)
            last = last_i;
    }
    return last;
}

bool dfs_sol(const vector<vector<size_t>>& edges, vector<bool>& mask, size_t index, size_t &count) {
    if (mask[index])
        return true;
    mask[index] = true;
    if (edges[index].size() > 3)
        --count;

    for (size_t i = 0; i < edges[index].size(); ++i) {
        bool ret = dfs_sol(edges, mask, edges[index][i], count);
        if (!ret)
            return ret;
    }
    if (edges[index].size() > 3 && count)
        return false;
    return true;
}
#endif
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    vector<vector<size_t>> edges(n);
    for (size_t i = 1; i < n; ++i) {
        size_t a;
        size_t b;
        cin >> a >> b;
        --a; --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (size_t i = 0; i < n; ++i) {
    S.clear();
    vector<bool> mask2(n);
    dfs_sol2(edges, mask2, i);
    size_t start = 0;
    size_t end = start + 1;
    size_t count2 = 0;
    for (size_t i = 1; i < S.size(); ++i) {
        if (S[i] == S[i-1])
            ++count2;
    }
    for (auto i : S)
        cout << i << ' ';
    cout << endl;
    while (0 && start != S.size()) {
        while (S[end] != S[start])
            ++end;
        ++count2;
        start = end + 1;
        end = start + 1;
    }
    if (count2 > 2)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    }
    return 0;
#if 0
    vector<size_t> multi;
    for (size_t i = 0; i < edges.size(); ++i) {
        if (edges[i].size() > 3)
            multi.push_back(i);
    }

    size_t last;
    {
        vector<bool> mask(n);
        last = dfs_last(edges, mask, 0);
    }

    if (last == -1)
        cout << "Yes" << endl;
    else {
        vector<bool> mask(n);
        size_t count = multi.size();
        if (dfs_sol(edges, mask, last, count))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
#endif
}
