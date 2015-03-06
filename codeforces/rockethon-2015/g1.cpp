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
    size_t k;
    cin >> n >> k;
    vector<int> vi(n);
    for (size_t i = 0; i < n; ++i)
        cin >> vi[i];
    map<vector<int>, int> m;
    m[vi] = 1;
    while (k--) {
        map<vector<int>, int> m2;
        for (size_t i = 0; i < n; ++i)
            for (size_t j = i; j < n; ++j) {
                for (auto I : m) {
                    vector<int> v = I.first;
                    for (size_t l = i, r = j; l < r; ++l, --r) {
                        swap(v[l], v[r]);
                    }
                    m2[v] += I.second;
                }
            }
        m = m2;
    }
    long long sum = 0;
    long long count = 0;
    for (auto i : m) {
        auto& v = i.first;
        sum += i.second;
        for (size_t l = 0; l < n; ++l)
            for (size_t r = l; r < n; ++r)
                if (v[l] > v[r])
                    count += i.second;
    }
    cout.precision(20);

    cout << fixed << static_cast<double>(count) / sum << endl;



    return 0;
}
