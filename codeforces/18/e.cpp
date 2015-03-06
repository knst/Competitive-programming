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

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int m;
    cin >> n >> m;
    vector<string> v;
    int Inf = n * m * 2 + 1;
    vector<vector<vector<int>>> countMin(n+1, vector<vector<int>>(26, vector<int>(26, Inf)));
    vector<vector<vector<pair<char,char>>>> countI(n+1, vector<vector<pair<char, char>>>(26, vector<pair<char,char>>(26)));
    for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
            countMin[0][i][j] = 0;

    for (int i = 0; i < n; ++i) {
        vector<char> s(m);
        for(int j = 0; j < m; ++j) {
            char c;
            cin >> c;
            c -= 'a';
            s[j] = c;
        }
        for (char a = 0; a < 26; ++a) {
            for (char b = 0; b < 26; ++b) {
                if (a == b)
                    continue;
                int count = 0;
                for (int j = 0; j < m; ++j) {
                    if (s[j] != ((j % 2 == 0) ? a : b))
                        ++count;
                }
                int mini = Inf;
                pair<char, char> miniI;
                for (char A = 0; A < 26; ++A) {
                    if (A == a)
                        continue;
                    for (char B = 0; B < 26; ++B) {
                        if (B == b)
                            continue;
                        if (A == B)
                            continue;
                        if (countMin[i][A][B] < mini) {
                            mini = countMin[i][A][B];
                            miniI = {A, B};
                        }
                    }
                }
                if (mini + count < countMin[i+1][a][b]) {
                    countMin[i+1][a][b] = mini + count;
                    countI[i+1][a][b] = miniI;
                }
            }
        }
    }

    int mini = Inf;
    pair<char, char> minAB;
    char minA;
    char minB;

    stack<pair<int,int>> s;
    for (char a = 0; a < 26; ++a) {
        for (char b = 0;b < 26; ++b) {
            if (a == b)
                continue;
            if (countMin[n][a][b] < mini) {
                minAB = countI[n][a][b];
                mini = countMin[n][a][b];
                minA = a;
                minB = b;
            }
        }
    }

    cout << mini << endl;

    s.push(minAB);
    for (int i = n-1; i > 0; --i) {
        s.push(countI[i][s.top().first][s.top().second]);
    }
    s.pop();
    while (!s.empty()) {
        for (int i = 0; i < m; ++i) {
            if (i % 2 == 0)
                cout << static_cast<char>(s.top().first + 'a');
            else
                cout << static_cast<char>(s.top().second + 'a');
        }
        cout << endl;
        s.pop();
    }
    for (int i = 0; i < m; ++i)
        cout << static_cast<char>((i % 2 ? minB : minA) + 'a');
    cout << endl;

    return 0;
}
