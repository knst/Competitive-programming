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

    string s;
    cin >> s;
    size_t n = s.size();

    vector<int> result;
    int co = 0;
    int ce = 0;
    for (size_t i = 0; i < n; ++i) {
        if (s[i] == '(')
            co++;
        if (s[i] == ')')
            ce++;
        if (s[i] == '#') {
            result.push_back(1);
            ce++;
        }
        if (co < ce) {
            cout << "-1" << endl;
            return 0;
        }
    }
    int balance = 0;
    for (size_t i = s.size() - 1; i < s.size(); --i) {
        if (s[i] == ')')
            balance++;
        if (s[i] == '(')
            balance--;
        if (balance < 0) {
            cout << "-1" << endl;
            return 0;
        }
        if (s[i] == '#')
            break;
    }
    result[result.size()-1] += co - ce;
    for (auto i : result)
        cout << i << ' ';
    cout << endl;

    return 0;
}
