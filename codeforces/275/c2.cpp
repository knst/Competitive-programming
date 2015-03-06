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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int weight(uint32_t x) {
    int result = 0;
    while (x) {
        x = x & (x - 1);
        ++result;
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    uint32_t m = v[0].size();

    vector<uint64_t> d(1 << m);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            uint32_t same = 0;
            for (int k = 0; k < m; ++k) {
                if (s[i][k] != s[j][k])
                    same |= (1 << k);
            }
            m[same] |= (1ULL << i);
            m[same] |= (1ULL << j);
        }
    }


    return 0;
}
