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

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& i : v)
        cin >> i;
    vector<int> order;
    for (int i = 0; i < n; ++i)
        order.push_back(i);
    int maximal = 0;
//    do {
        set<int> result;
        result.insert(0);
        for (int i = 0; i < n; ++i) {
            set<int> result2;
            for (auto x : result) {
                x += v[order[i]];
                vector<int> digit;
                while (x) {
                    digit.push_back(x % 10);
                    x /= 10;
                }
                sort(digit.begin(), digit.end());
                do {
                    int y = 0;
                    for (auto i : digit)
                        y = y * 10 + i;
                    result2.insert(y);
                } while (next_permutation(digit.begin(), digit.end()));
            }
            result = result2;
        }
        for (auto i : result)
            maximal = max(maximal, i);

//    } while (next_permutation(order.begin(), order.end()));
    cout << maximal << endl;


    return 0;
}
