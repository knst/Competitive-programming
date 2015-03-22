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

    size_t n;
    cin >> n;
    vector<string> v;

    for (size_t i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    vector<char> sv = {'a'};
    while (true) {
        bool ok = true;
        string s;
        for (auto i : sv)
            s = i + s;
        for (size_t i = 0; i < n; ++i) {
            if (v[i].find(s) != string::npos)
                ok = false;
        }
        if (ok) {
            cout << s << endl;
            return 0;
        }
        size_t index = 0;
        while (index < s.size()) {
            sv[index]++;
            if (sv[index] > 'z') {
                sv[index] = 'a';
                ++index;
            } else
                break;
        }
        if (index == sv.size())
            sv.push_back('a');
    }

    return 0;
}
