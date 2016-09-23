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

//constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

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
    cin.tie(0);

    size_t n;
    cin >> n;
    size_t t;
    cin >> t;
    string s;
    cin >> s;

    int bestCombo = 0;
    int last = n;
    int start = 0;
    while (s[start] != '.')
        ++start;
    ++start; // first after point
    for (size_t i = start; i < n; ++i) {
        if (s[i] > '4')  {
            int combo = 1;
            int j = i - 1;
            while (s[j] == '4') {
                ++combo;
                --j;
            }
            bestCombo = combo;
            last = i;
            break;
        }
    }
    if (bestCombo > t)
        bestCombo = t;
    int e = last - bestCombo;
    s = s.substr(0, e + 1);
    int off = 0;
    if (bestCombo > 0)
        off = 1;
    for (int j = e; j >= 0; --j) {
        if (s[j] == '.')
            continue;
        s[j] += off;
        if (s[j] > '9')
            s[j] = '0';
        } else {
            off = 0;
        }
    }
    if (off == 1)
        cout << "1";
    size_t L = s.size();
    while (L > 1 && s[L-1] == '0')
        --L;
    if (s[L-1] == '.')
        --L;

    s = s.substr(0, L);
    cout << s << endl;

    return 0;
}
