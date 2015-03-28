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

int gcd(int x, int y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

inline int compare(int ci, int c, int hi, int h, long long x, long long y) {
    int a = ci * c + hi * h;
    int b = ci + hi;
    if (a * y - x * b > 0)
        return 1;
    if (a * y - x * b < 0)
        return -1;
    return 0;
}
int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int m;
    int c;
    int h;
    int k;
    cin >> n >> m;
    cin >> c >> h;
    cin >> k;
    vector<int> vc(n);
    vector<int> vh(m);
    for (int i = 0; i < n; ++i) {
        cin >> vc[i];
    }
    for (int j = 0; j < m; ++j) {
        cin >> vh[j];
    }
    sort(vc.begin(), vc.end());
    sort(vh.begin(), vh.end());
    auto it1 = std::unique (vc.begin(), vc.end());
    vc.resize(std::distance(vc.begin(),it1));
    auto it2 = std::unique (vh.begin(), vh.end());
    vh.resize(std::distance(vh.begin(),it2));


    while (k--) {
        int x;
        int y;
        cin >> x >> y;
        int g = gcd(x, y);
        x /= g;
        y /= g;

        int low = 0;
        bool ok = false;
        for (low = 0; !ok && low < n; ++low) {
            if (vc[low] % x == 0)
                continue;
            int top_l = 0;
            int top_r = m;
            while (!ok && top_l < top_r) {
                int top = (top_l + top_r) / 2;
                int r = compare(vc[low], c, vh[top], h, x, y);
                if (r > 0) {
                    top_r = top;
                }
                if (r < 0)
                    top_l = top+1;
                if (r == 0)
                    ok = true;
            }
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";

    }
    cout.flush();

    return 0;
}
