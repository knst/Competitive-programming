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

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        v[i][i] = 0;

    vector<set<int>> rows(n);
    vector<set<int>> columns(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            rows[i].insert(j);
            columns[i].insert(j);
        }
    }
    int last = 1;
    for (int i = 0 ; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            while (rows[i].find(last) == rows[i].end() || columns[j].find(last) == columns[j].end()) {
                ++last;
                if (last >= n)
                    last = 1;
            }
            rows[i].erase(last);
            columns[j].erase(last);
            rows[j].erase(last);
            columns[i].erase(last);
            v[i][j] = last;
            v[j][i] = last;
        }
        ++last;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
