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

int test(vector<pair<int,int>> vt0, vector<pair<int,int>> vt1, int x) {
    size_t index = 0;
    bool ok = true;
    while (ok) {
        ok = false;
        int maxw1 = -1;
        size_t maxi1 = 0;
        for (size_t i = 0; i < vt0.size(); ++i) {
            if (vt0[i].first > maxw1 && vt0[i].second <= x) {
                maxw1 = vt0[i].first;
                maxi1 = i;
            }
        }
        if (maxw1 > 0) {
            vt0[maxi1].first = 0;
            x += maxw1;
            int maxw2 = -1;
            size_t maxi2 = 0;
            for (size_t i = 0; i < vt1.size(); ++i) {
                if (vt1[i].first > maxw2 && vt1[i].second <= x) {
                    maxw2 = vt1[i].first;
                    maxi2 = i;
                }
            }
            if (maxw2 > 0) {
                ok = true;
                vt1[maxi2].first = 0;
                x += maxw2;
            }
            ++index;
        } else
            return index * 2;
    }
    return index * 2 - 1;
}


int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int x;
    cin >> n >> x;
    vector<pair<int,int>> vt0;
    vector<pair<int,int>> vt1;
    for (int i = 0; i < n; ++i) {
        int t;
        int h;
        int w;
        cin >> t >> h >> w;
        if (t == 0)
            vt0.push_back({w, h});
        if (t == 1)
            vt1.push_back({w, h});
    }
    sort(vt0.begin(), vt0.end());
    sort(vt1.begin(), vt1.end());
    int result = max(test(vt1, vt0, x), test(vt0, vt1, x));
    cout << max(0, result) << endl;


    return 0;
}
