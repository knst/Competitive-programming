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

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    size_t k;
    cin >> n >> k;

    int best_len = -1;
    size_t best_index = 0;


    vector<pair<pair<int,int>, size_t>> v;
    for (size_t i = 0; i < n; ++i) {
        int x;
        int y;
        cin >> x >> y;
        v.push_back({{x, y}, i + 1});
    }

    sort(v.begin(), v.end());

    size_t index = 0;
    set<pair<pair<int,int>,size_t>> added;
    for (auto j : v) {
        auto i = j.first;
        ++index;
        added.insert({{i.second, i.first}, j.second});
        cout << "added:" << endl;
        for (auto i : added) {
            cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
        }
        if (index >= k) {
            cout << "prob: " << added.begin()->first.second << ' ' <<  v[index - k].first.second<< endl;

            int len = added.begin()->first.second - v[index - k].first.second;
            cout << "len: " << len << endl;
            if (len > best_len) {
                best_len = len;
                best_index = index;
            }

            pair<pair<int,int>, size_t> to_remove = {{v[index - k].first.second, v[index - k].first.first}, v[index - k].second};
            added.erase(added.find(to_remove));
        }
    }

    index = 0;
    added.clear();
    for (auto j : v) {
        auto i = j.first;
        ++index;
        added.insert({{i.second, i.first}, j.second});
        if (index >= k) {
            int len =  added.begin()->first.second - v[index - k].first.second;
            if (index == best_index) {
                cout << len + 1 << endl;
                for (auto k : added)
                    cout << k.second << ' ';
                cout << endl;
                return 0;
            }
            pair<pair<int,int>, size_t> to_remove = {{v[index - k].first.second, v[index - k].first.first}, v[index - k].second};
            added.erase(added.find(to_remove));
        }
    }
    cout << 0 << endl;
    for (size_t i = 0; i < k; ++i) {
        cout << i + 1 << ' ';
    }
    cout << endl;
}
