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

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    using PT = pair<pair<int,int>, int>;
    vector<PT> parts;
    for (int i = 0; i < n; ++i) {
        int a;
        int b;
        cin >> a >> b;
        parts.push_back({{a, b},i});
    }
    sort(parts.begin(), parts.end());

    int m;
    cin >> m;
    priority_queue<PT, vector<PT>, greater<PT>> mans;
    map<int,int> mansK;
    for (int i = 0; i < m; ++i) {
        int c;
        int d;
        int k;
        cin >> c >> d >> k;
        mansK[i] = k;
        mans.push({{d,c}, i});
    }
    vector<pair<int,int>> result;
    for (auto part : parts) {
        do {
            if (mans.empty()) {
                cout << "NO" << endl;
                return 0;
            }
            PT man = mans.top();
            if (mansK[man.second] == 0) {
                mans.pop();
                continue;
            }
            mansK[man.second]--;
            if (man.first.first < part.first.second ||
                man.first.second > part.first.first
            ) {
                mansK[man.second] = 0;
                continue;
            }
            result.push_back({part.second, man.second});
            break;
        } while (true);

    }
    sort(result.begin(), result.end());
    cout << "YES" << endl;
    for (auto i : result) {
        cout << i.second + 1 << ' ';
    }


    return 0;
}

