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

    set<string> text;
    size_t n;
    do {
        string s;
        cin >> s;
        if (s[0] >= '0' && s[0] <= '9')
            n = stoi(s);
        else
            text.insert(s);
    } while (!n);

    set<string> words;
    for (size_t i = 0; i < n; ++i) {
        string s;
        cin >> s;
        words.insert(s);
    }
    bool ok = true;
    for (auto s : text)
        if (words.find(s) == words.end())
            ok = false;
    if (ok)
        cout << "Correct" << endl;
    else
        cout << "Misspell" << endl;

    return 0;
}
