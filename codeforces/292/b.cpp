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

void NotUniq() {
    cout << "Not unique" << endl;
    exit(0);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    size_t m;
    cin >> n >> m;

    n += 2;
    m += 2;

    vector<vector<char>> field(n, vector<char>(m, '*'));
    queue<pair<size_t, size_t>> q;
    for (size_t i = 1; i < n - 1; ++i) {
        string s;
        cin >> s;
        for (size_t j = 1; j < m - 1; ++j) {
            field[i][j] = s[j-1];
            q.push({i, j});
        }
    }
    while (!q.empty()) {
        pair<int, int> top = q.front();
        q.pop();

        if (field[top.first][top.second] != '.')
            continue;

        vector<pair<int, int>> possibilities;
        for (size_t i = 0; i < 4; ++i) {
            pair<int,int> point = {top.first + dx4[i], top.second + dy4[i]};
            if (field[point.first][point.second] == '.')
                possibilities.push_back(point);
        }

        if (possibilities.empty())
            NotUniq();

        if (possibilities.size() > 1)
            continue;

        pair<int, int> add = possibilities.front();

        for (size_t i = 0; i < 4; ++i)
            q.push({add.first + dx4[i], add.second + dy4[i]});

        if (add > top)
            swap(add, top);

        if (add.first == top.first) {
            field[add.first][add.second] = '<';
            field[top.first][top.second] = '>';
        } else {
            field[add.first][add.second] = '^';
            field[top.first][top.second] = 'v';
        }

    }

    for (auto i : field)
        for (auto j : i)
            if (j == '.')
                NotUniq();

    for (size_t i = 1; i < n - 1; ++i) {
        for (size_t j = 1; j < m - 1; ++j) {
            cout << field[i][j];
        }
        cout << '\n';
    }
    cout.flush();

    return 0;
}
