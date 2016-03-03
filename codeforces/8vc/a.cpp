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

void norm(vector<size_t>& v) {
    vector<size_t> x(v.size());
    size_t start;
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == 1)
            start = i;
    }
    for (size_t i = 0; i + 1 < v.size(); ++i) {
        if (v[(i + start) % v.size()] == 0)
            start++;
        x[i] = v[(i + start) % v.size()];
    }
    v = x;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    vector<size_t> a(n);
    vector<size_t> b(n);

    for (auto& i : a)
        cin >> i;
    for (auto& i : b)
        cin >> i;
    norm(a);
    norm(b);
    if (a == b)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;



    return 0;
}
