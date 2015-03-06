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
    cin >> n>> m;
    vector<vector<bool>> v(n + 2, vector<bool>(m + 2));
    int k;
    cin >> k;
    for (size_t I = 0; I < k; ++I) {
        int x;
        int y;
        cin >> x >> y;
        v[x][y] = true;
        for (int i = -1; i < 1; ++i) {
            for (int j = -1; j < 1; ++j) {
                if (
                        v[x + i][y + j] &&
                        v[x + i + 1][y + j] &&
                        v[x + i][y + j + 1] &&
                        v[x + i + 1][y + j + 1]) {
                    cout << I  + 1<< endl;
                    return 0;
                }
            }

        }
    }
    cout << 0 << endl;
    return 0;
}
