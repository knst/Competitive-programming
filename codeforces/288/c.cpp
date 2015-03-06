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

    int m;
    int t;
    int r;
    cin >> m >> t >> r;
    vector<int> w(m);
    set<int> wset;
    for (auto& i : w) {
        cin >> i;
        i += 400;
        wset.insert(i);
    }
    size_t N = 1000;
    vector<int> timesStart(N);
    vector<int> timesEnd(N);
    int count = 0;
    int countNow = 0;
    for (size_t i = 301; i < N; ++i) {
        if (timesStart[i - t-1])
            --countNow;
        if (wset.find(i) != wset.end()) {
            if (t < r) {
                cout << -1 << endl;
                return 0;
            }
            for (size_t j = i - r + countNow; j < i; ++j) {
                if (timesStart[j]) {
                    cout << -1 << endl;
                    return 0;
                }
                timesStart[j] = 1;
                ++count;
                ++countNow;
            }
        }
    }
    cout << count << endl;



    return 0;
}
