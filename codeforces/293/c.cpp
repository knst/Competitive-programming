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

    size_t n;
    size_t m;
    int k;
    cin >> n >> m >> k;
    vector<int> inPositions(n);
    vector<int> application(n);
    for (size_t i = 0; i < n; ++i) {
        int app;
        cin >> app;
        app--;
        application[app] = i;
        inPositions[i] = app;
    }
    long long sum = 0;
    for (size_t i = 0; i < m; ++i) {
        int app;
        cin >> app;
        --app;
        sum +=  application[app] / k + 1;
        if (application[app] != 0) {
            int pos1 = application[app];
            int pos2 = pos1 - 1;
            int app2 = inPositions[pos2];
            swap(application[app], application[app2]);
            swap(inPositions[pos1], inPositions[pos2]);
        }
    }
    cout << sum << endl;
    return 0;
}
