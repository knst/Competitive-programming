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

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int Get(vector<int> prices, vector<int> count) {
    int sum = 0;
    for (int i = 0; i < count.size(); ++i) {
        sum += prices[i] * count[i];
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int m;
    cin >> n >> m;
    vector<int> prices(n);
    for (auto& i : prices)
        cin >> i;
    map<string, int> M;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        M[s] = M[s] + 1;
    }

    vector<int> count;
    for (auto i : M) {
        count.push_back(i.second);
    }
    sort(prices.begin(), prices.end());
    sort(count.begin() ,count.end());
    reverse(count.begin(), count.end());
    int minimal = Get(prices, count);
    reverse(prices.begin(), prices.end());
    int maximal = Get(prices, count);
    cout << minimal << ' ' << maximal << endl;





    return 0;
}
