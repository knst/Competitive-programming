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

    string s;
    string q;
    cin >> s >> q;
    vector<int> target(200);
    vector<int> base(200);
    for (auto i : s)
        target[i]++;
    for (auto i : q)
        base[i]++;

    int r1 = 0;
    int r2 = 0;
    for (char i = 'a'; i <= 'z'; ++i) {
        int c = min(target[i], base[i]);
        target[i] -= c;
        base[i] -= c;
        r1 += c;
    }
    for (char i = 'A'; i <= 'Z'; ++i) {
        int c = min(target[i], base[i]);
        target[i] -= c;
        base[i] -= c;
        r1 += c;
    }
    for (char i = 'a'; i <= 'z'; ++i) {
        target[i] += target[i - 'a' + 'A'];
        base[i] += base[i - 'a' + 'A'];
        int c = min(target[i], base[i]);
        r2 += c;
    }
    cout << r1 << ' ' << r2 << endl;

    return 0;
}
