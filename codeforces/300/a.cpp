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

namespace std {
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
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
    cin >> s;
    string original = "CODEFORCES";
    if (s.size() < original.size()) {
        cout << "NO" << endl;
        return 0;
    }
    size_t len1 = 0;
    size_t len2 = 0;
    while (len1 < original.size() && original[len1] == s[len1])
        ++len1;
    while (len2 < original.size() && original[original.size() - len2 - 1] == s[s.size() - len2 - 1])
        ++len2;
    if (len1 + len2 >= original.size())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


    return 0;
}
