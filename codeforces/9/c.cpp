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

bool test(int value) {
    while (value) {
        int digit = value % 10;
        if (digit != 0 && digit != 1)
            return false;
        value /= 10;
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int count = 0;
    if (n == 1000 * 1000 * 1000)
        ++count;
    if (n > 111111111)
        n = 111111111;
    for (int i = 1; i <= n;) {
        if (test(i))
            ++count;
        i+= 9;
        if (i > n)
            break;
        if (test(i))
            ++count;
        ++i;
    }
    cout << count;

    return 0;
}
