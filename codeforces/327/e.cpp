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

    size_t n;
    size_t m;

    bool m12 = false;
    bool m23 = false;
    bool m13 = false;
    bool First;

vector<vector<char>> v(n, vector<char>(m));

void reset(const vector<vector<char>>& V) {
    v = V;
    First = true;
}

queue<pair<size_t,size_t>> qc;

void fill(vector<vector<char>>& v, queue<pair<size_t, size_t>>& q, char value1, char value2, char value3, char value) {
    qc.clear();
    queue<pair<size_t, size_t>> q2;
    while (!q.empty()) {
        pair<size_t, size_t> t = q.front();
        q.pop();
        if (t.first >= n || t.second >= m)
            continue;
        if (v[t.first][t.second] == 8)
            continue;
        if (!First && (v[t.first][t.second] & value))
            continue;
        v[t.first][t.second] = v[t.first][t.second] | value;

        for (size_t i = 0; i < 4; ++i) {
            qc.push({t.first + dx4[i], t.second + dy4[i]});
            q2.push({t.first + dx4[i], t.second + dy4[i]});
        }

    }

    q = q2;
}
size_t solve(char value1, char value2, char value3) {
    size_t solution = 0;
    queue<pair<size_t, size_t>> q1, q2, q3;
    for (size_t i = 0; i < n; ++i)
        for (size_t j = 0; j < n; ++j) {
            if (v[i][j] == 8)
                continue;
            if (v[i][j] & value1)
                q1.push({i, j});
            if (v[i][j] & value2)
                q2.push({i, j});
            if (v[i][j] & value3)
                q3.push({i, j});
        }

    do {


        fill(v, q1, value1, value2, value3, value1);
        if (check())
            break;
        ++solution;
        fill(v, q2, value1, value2, value3, value2);
        if (check())
            break;
        ++solution;
        fill(v, q3, value1, value2, value3, value3);
        if (check())
            break;
        ++solution;
        if (First) {
            solution -= 3;
            First = false;
        }

    } while (q1.size() || q2.size() || q3.size());
    if (check())
        return solution;
    return -1;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    vector<vector<char>> V(n, vector<char>(m));
    for (size_t i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (size_t j = 0; j < m; ++j) {
            if (s[j] == '1')
                V[i][j] = 1;
            if (s[j] == '2')
                V[i][j] = 2;
            if (s[j] == '3')
                V[i][j] = 4;
            if (s[j] == '#')
                V[i][j] = 8;
        }
    }

    size_t solution = -1;
    reset(V); solution = min(solution, solve(1, 2, 2));
    reset(V); solution = min(solution, solve(1, 4, 4));
    reset(V); solution = min(solution, solve(2, 4, 4));
    reset(V); solution = min(solution, solve(1, 1, 1));
    reset(V); solution = min(solution, solve(2, 2, 2));
    reset(V); solution = min(solution, solve(4, 4, 4));
    reset(V); solution = min(solution, solve(1, 2, 4));
    reset(V); solution = min(solution, solve(1, 4, 2));
    reset(V); solution = min(solution, solve(2, 1, 4));
    reset(V); solution = min(solution, solve(2, 4, 1));
    reset(V); solution = min(solution, solve(4, 1, 2));
    reset(V); solution = min(solution, solve(4, 2, 1));
    if (solution == -1)
        cout << -1 << endl;
    else if (solution == 0)
        cout << 0 << endl;
    else if (solution == 1)
        cout << 0 << endl;
    else
        cout << solution - 1 << endl;

    return 0;
}
