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
    long long k;
    cin >> n >> m >> k;
    multiset<long long> s[5];
    size_t first = 0;
    size_t ans = 0;
    long long ansJ[5] = {0, 0, 0, 0, 0};
    vector<vector<long long>> D(n, vector<long long>(5));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            long long d;
            cin >> d;
            D[i][j] = d;
            s[j].insert(d);
        }
        while (first <= i) {
            long long sum = 0;
            long long maxJ[5] = {0, 0, 0, 0, 0};
            for (size_t j = 0; j < m; ++j) {
                if (!s[j].empty()) {
                    maxJ[j] = *(s[j].rbegin());
                    sum += maxJ[j];
                }
            }
            if (sum > k) {
                for (size_t j = 0; j < m; ++j) {
                    s[j].erase(D[first][j]);
                }
                ++first;
            } else
                break;

        }
        long long sum = 0;
        long long maxJ[5] = {0, 0, 0, 0, 0};
        for (size_t j = 0; j < m; ++j) {
            if (!s[j].empty()) {
                maxJ[j] = *(s[j].rbegin());
                sum += maxJ[j];
            }
        }
        if (i - first + 1 > ans) {
            ans = i - first + 1;
            for (size_t j = 0; j < m; ++j)
                ansJ[j] = maxJ[j];
        }

    }
    for (size_t i = 0; i < m; ++i)
        cout << ansJ[i] << ' ';
    cout << endl;
    return 0;
}
