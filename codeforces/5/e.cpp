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

int main() {
    std::ios_base::sync_with_stdio(false);

    for (int test = 0; test < 10; ++test) {
        int n = rand() % 10 + 3;
        cout << n << endl;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = rand() % 20 + 1;
            cout << v[i] << ' ';
        }
        cout << endl;

        int count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = (i + 1) % n; ; j = (j + 1) % n) {
                bool ok = true;
                for (int k = (i + 1) % n; k != j; k = (k + 1) % n) {
                    if (v[k] > v[i] || v[k] > v[j])
                        ok = false;
                }

                if (ok)
                    ++count;

                if (j == i)
                    break;
            }
        }
        cout << count << endl;
    }

    return 0;
}
