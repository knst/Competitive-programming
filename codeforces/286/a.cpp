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

    size_t N = 30001;
    size_t n;
    size_t d;
    cin >> n >> d;
    vector<int> p(N, 0);
    for (size_t i = 0; i < n; ++i) {
        size_t index;
        cin >> index;
        p[index]++;
    }
    vector<vector<pair<int,int>>> dyn(N);
    dyn[d].push_back({d, p[d]});
    int maximum = p[d];
    for (size_t i = d; i < N; ++i) {
        if (dyn[i].empty())
            continue;
        sort(dyn[i].begin(), dyn[i].end());
        for (size_t j = 0; j < dyn[i].size(); ++j) {
            while (j + 1 < dyn[i].size() && dyn[i][j].first == dyn[i][j+1].first)
                ++j;
            int P = dyn[i][j].second;
            for (int D = dyn[i][j].first - 1; D <= dyn[i][j].first + 1; ++D) {
                if (D > 0 && i + D < N) {
                    dyn[i + D].push_back({D, P + p[i + D]});
                    maximum = max(maximum, P + p[i + D]);
                }
            }
        }
        dyn[i] = vector<pair<int,int>>();
    }
    cout << maximum << endl;

    return 0;
}
