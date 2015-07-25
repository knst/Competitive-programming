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

int main() {
    std::ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        int n;
        int m;
        int t;
        int c;
        cin >> n >> m >> t >> c;
        vector<string> v(n);
        for (auto& i : v) {
            cin >> i;
        }
        int index = 0;
        int count = 0;
        while (index < m) {
            vector<char> select(n);
            for (int i = 0; i < n; ++i) {
                select[i] = v[i][index];
            }
            bool ok = true;
            while (ok && index < m) {
                ok = false;
                for (int i = 0; i < n; ++i) {
                    if (select[i] == '1' && v[i][index] == '1')
                        ok = true;
                    if (v[i][index] == '0')
                        select[i] = '0';
                }
                if (ok) 
                    index++;
                else
                    ++count;
            }
        }
        cout << t * m + count * c << endl;
    }


    return 0;
}
