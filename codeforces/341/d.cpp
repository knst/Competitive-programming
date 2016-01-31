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

long double Pow1(long double a, long double b, long double c)
{
    return pow(b, c) * log(a);
}

long double Pow2(long double a, long double b, long double c)
{
    return b * c * log(a);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    long double a;
    long double b;
    long double c;

    cin >> a >> b >> c;

    vector<long double> results;
    results.push_back(Pow1(a, b, c));
    results.push_back(Pow1(a, c, b));

    results.push_back(Pow2(a, b, c));
    results.push_back(Pow2(a, c, b));

    results.push_back(Pow1(b, a, c));
    results.push_back(Pow1(b, c, a));

    results.push_back(Pow2(b, a, c));
    results.push_back(Pow2(b, c, a));

    results.push_back(Pow1(c, a, b));
    results.push_back(Pow1(c, b, a));

    results.push_back(Pow2(c, a, b));
    results.push_back(Pow2(c, b, a));

    vector<string> prints = {
        "x^y^z",
        "x^z^y",
        "(x^y)^z",
        "(x^z)^y",
        "y^x^z",
        "y^z^x",
        "(y^x)^z",
        "(y^z)^x",
        "z^x^y",
        "z^y^x",
        "(z^x)^y",
        "(z^y)^x",
    };
    long double maximal = results[0];
    string ans = prints[0];
    for (size_t i = 0; i < results.size(); ++i) {
        if (results[i] > maximal) {
            if ((results[i] - maximal) > maximal / 1e20) {
                maximal = results[i];
                ans = prints[i];
            }
        }
    }
    cout << ans << endl;


    return 0;
}
