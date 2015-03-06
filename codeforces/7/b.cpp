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
};

int Alloc(vector<int> &v, int n) {
    static int ID = 1;
    int m = v.size();
    for (int i = 0; i < m; ++i) {
        int j = i;
        while (j < m && v[j] == 0)
            ++j;
        if (j - i >= n) {
            for (int j = 0; j < n; ++j)
                v[i + j] = ID;
            return ID++;
        }
    }
    return 0;
}

void Erase(vector<int>& v, int x) {
    bool ok = false;
    for (auto& i : v) {
        if (i == x) {
            ok = true;
            i = 0;
        }
    }
    if (!ok || x == 0)
        cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
}

void Defrag(vector<int>& v) {
    int start = 0;
    int i = 0;
    int m = v.size();
    while (start < m && i < m) {
        while (i < m && v[i] == 0)
            ++i;
        if (i < m) {
            v[start] = v[i];
            ++start;
            ++i;
        }
    }
    for (int i = start; i < m; ++i)
        v[i] = 0;
}
int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    int m;
    cin >> t >> m;
    vector<int> v(m, 0);
    for (int i = 0; i < t; ++i) {
        string s;
        cin >> s;
        if (s == "alloc") {
            int n;
            cin >> n;
            int x = Alloc(v, n);
            if (x == 0)
                cout << "NULL" << endl;
            else
                cout << x << endl;
        }
        if (s == "erase") {
            int x;
            cin >> x;
            Erase(v, x);
        }
        if (s == "defragment") {
            Defrag(v);
        }
    }

    return 0;
}

