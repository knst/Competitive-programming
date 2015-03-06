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

const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, -1, 0, 1};

const int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    std::ios_base::sync_with_stdio(false);

    vector<int> primes;
    for (int i = 2; i < 1000001; ++i) {
        bool ok = true;
        for (int j = 0; ok && j < primes.size() && primes[j] * primes[j] <= i; ++j) {
            if (i % primes[j] == 0)
                ok = false;
        }
        if (ok)
            primes.push_back(i);

    }
    set<int> primes2;
    for (auto p : primes)
        primes2.insert(p);
    int n;
    cin >> n;
    {
        bool ok = false;
        int start = 4;
        while (!ok) {
            if (primes2.find(start) == primes2.end() &&
                    primes2.find(n-start) == primes2.end()) {
                cout << start << ' ' << n-start << '\n';
                ok = true;;
            }
            ++start;

        }
    }

    return 0;
}
