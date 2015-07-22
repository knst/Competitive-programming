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

void canon(string& s, const size_t start, const size_t length) {
    if (length == 0 || length % 2)
        return;
    size_t len2 = length / 2;
    canon(s, start, len2);
    canon(s, start + len2, len2);
    int great = 0;
    for (size_t i = 0; !great && i < len2; ++i) {
        if (s[start + i] < s[start + len2 + i]) {
            great = -1;
        }
        if (s[start + i] > s[start + len2 + i])
            great = 1;
    }
    if (great == 1)
        for (size_t i = 0; i < len2; ++i)
            swap(s[start + i], s[start + len2 + i]);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    string a;
    string b;
    cin >> a >> b;
    canon(a, 0, a.size());
    canon(b, 0, b.size());
    if (a == b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
