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

    size_t n;
    size_t m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<char> M(26);
    for (size_t i = 0; i < 26; ++i)
        M[i] = i;
    for (size_t i = 0; i < m; ++i) {
        char a;
        char b;
        cin >> a >> b;
        a -= 'a';
        b -= 'a';
        size_t ai;
        size_t bi;
        for (size_t j = 0; j < 26; ++j) {
            if (M[j] == a)
                ai = j;
            if (M[j] == b)
                bi = j;
        }
        swap(M[ai], M[bi]);
    }
    for (auto i : s)
        cout << static_cast<char>(M[i - 'a'] + 'a');
    cout << endl;
    return 0;
}
