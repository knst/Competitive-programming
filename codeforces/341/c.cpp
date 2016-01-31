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

double C(pair<int,int> a, int p) {
    int l = a.first;
    int r = a.second;
    if (l > r)
        swap(r, l);
    double f1 = r / p - (l - 1) / p;
    return f1 / (r - l + 1);
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;
    int p;
    cin >> p;

    vector<pair<int, int>> v(n);
    for (auto& i : v)
        cin >> i.first >> i.second;

    auto a = v.front();
    v.push_back(a);

    double res = 0;
    for (size_t i = 1; i < v.size(); ++i) {
        double f1 = C(v[i - 1], p);
        double f2 = C(v[i], p);
        res += f1 + f2 - f1 * f2;
    }
    cout.precision(8);
    cout << fixed << res * 2000.0 << endl;

    return 0;
}
