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
    cin.tie(0);

    string s;
    cin >> s;
    size_t m;
    cin >> m;
    vector<pair<pair<size_t,size_t>, size_t>> shifts(m);
    for (auto& i : shifts) {
        cin >> i.first.first >> i.first.second >> i.second;
        --i.first.first;
        --i.first.second;
    }
    vector<char> s2(s.size());
    for (size_t i = 0; i < s.size(); ++i) {
        size_t p = i;
        for (auto j : shifts) {
            if (p >= j.first.first && p <= j.first.second) {
                p = (p - j.first.first + j.second) % (j.first.second - j.first.first + 1) + j.first.first;
            }
        }
        s2[p] = s[i];
    }
    for (auto i : s2)
        cout << i;
    cout << endl;


    return 0;
}
