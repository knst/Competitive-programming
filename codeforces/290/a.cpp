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
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
}

void Impos() {
    cout << "Impossible" << endl;
    exit(0);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    vector<string> v;
    for (size_t i =0 ; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    vector<vector<int>> table(26, vector<int>(26));
    for (size_t i = 1; i < n; ++i) {
        size_t index = 0;
        while (index < v[i].size() && index < v[i-1].size() && v[i][index] == v[i-1][index])
            ++index;
        if (index >= v[i].size() && index < v[i-1].size()) {
            Impos();
        }
        if (index >= v[i].size() || index >= v[i-1].size())
            continue;
        int a = v[i-1][index]-'a';
        int b = v[i][index] - 'a';
        if (table[a][b] && table[a][b] != -1)
            Impos();
        if (table[b][a] && table[b][a] != 1)
            Impos();
        table[a][b] = -1;
        table[b][a] = 1;
    }

    vector<int> result;
    for (size_t i = 0; i < 26; ++i)
        result.push_back(i);

    for (size_t i = 0; i < 10000; ++i) {
        for (size_t a = 0; a < 26; ++a) {
            for (size_t b = a + 1; b < 26; ++b) {
                if (table[result[a]][result[b]] == 1)  {
                    swap(result[a], result[b]);
                }
            }
        }
    }
    bool ok = true;
    for (size_t a = 0; a < 26; ++a) {
        for (size_t b = a+1; b < 26; ++b) {
            if (table[result[a]][result[b]] == 1)
                ok = false;
        }
    }
    if (!ok)
        Impos();
    for (auto i : result) {
        cout << static_cast<char>(i + 'a');
    }
    cout << endl;

    return 0;
}

