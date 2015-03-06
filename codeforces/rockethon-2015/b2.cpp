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

int f(vector<int>& values) {
    int sum = 0;
    for (size_t i = 0; i < values.size(); ++i) {
        for (size_t j = i; j < values.size(); ++j) {
            int minimum = values.size();
            for (size_t k = i; k <= j; ++k) {
                if (values[k] < minimum)
                    minimum = values[k];
            }
            sum += minimum;
        }
    }
    return sum;
}


void ret(vector<int>& v) {
    for (auto i : v)
        cout << i << ' ';
    cout << endl;
    exit(0);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    size_t m;
    cin >> n >> m;
    vector<int> v(n);
    for (size_t i = 0; i < n; ++i)
        v[i] = i + 1;
    if (m == 1) {
        ret(v);
    }

    swap(v[n-2], v[n-1]);
    if (m == 2)
        ret(v);
    for (size_t i = 2; i < m; ++i) {
        size_t l = n - 1;

        while (v[l-1] > v[l])
            --l;
        --l;

        size_t r = l + 1;
        while (r + 1 < n && v[r + 1] > v[l])
            ++r;
        while (l < r) {
            swap(v[l], v[r]);
            ++l;
            --r;
        }
    }
    ret(v);

    return 0;
}
