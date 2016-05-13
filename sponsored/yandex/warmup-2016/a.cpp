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
    char af = 0;
    char bf = 0;
    for (auto i : s) {
        if (i == 'a' || i == 'i' || i == 'e' || i == 'o' || i == 'u' || i == 'y') {
            if (af == 0)
                af = i;
        } else {
            if (bf == 0) {
                bf = i;
            }
        }
    }
    string a;
    string b;
    if (af != 0) {
        a = af;
    }
    if (bf != 0)
        b = bf;
    if (a > b)
        cout << "Vowel" << endl;
    else
        cout << "Consonant" << endl;


    return 0;
}
