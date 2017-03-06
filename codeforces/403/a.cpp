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

#include <cmath>

using namespace std;

namespace std { template <class T1, class T2> struct hash<pair<T1, T2>> {
    size_t operator()(const pair<T1, T2>& p) const { return hash<T1>()(p.first) ^ hash<T2>()(p.second); }
};}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1)) * 4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

template<class T> T gcd(T A, T B) { return B == 0 ? A : gcd(B, A % B); }

uint64_t powMod(uint64_t G, uint64_t pow, uint64_t M) {
    if (pow == 0) return 1;
    return pow % 2 == 0 ? powMod(G * G % M, pow / 2, M) : powMod(G, pow - 1, M) * G % M;
}

uint64_t inverse(uint64_t X, uint64_t M) { return X == 1 ? 1 : powMod(X, M - 2, M); }

struct Step {
    int last;
    int current;
    int index;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    vector<vector<size_t>> edges(n);
    for (size_t i = 0; i < n - 1; ++i) {
        size_t x, y;
        cin >> x >> y;
        --x;
        --y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vector<bool> mask(n);
    vector<int> colors(n);
    colors[0] = 1;
    queue<Step> steps;
    steps.push({0, 1, 0});
    while (!steps.empty()) {
        Step top = steps.front();
        steps.pop();
        int nextColor = 0;
        for (size_t i = 0; i < edges[top.index].size(); ++i) {
            int v = edges[top.index][i];
            if (colors[v] != 0) {
                continue;
            }
            nextColor++;
            while (nextColor == top.last || nextColor == top.current) {
                ++nextColor;
            }
            colors[v] = nextColor;
            steps.push({top.current, nextColor, v});
        }
    }
    int k = 0;
    for (auto i : colors)
        k = max(i, k);
    cout << k << endl;
    for (auto i : colors)
        cout << i << ' ';
    cout << endl;


}
