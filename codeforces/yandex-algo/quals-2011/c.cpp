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

    size_t a;
    size_t b;
    cin >> a >> b;

    vector<int> v(n);
    for (auto& i : v)
        cin >> i;

    if (a == b) {
        for (size_t i = 0; i < a; ++i)
            cout << "1 ";
        for (size_t i = 0; i < b; ++i)
            cout << "2 ";
        cout << endl;
        return 0;
    }
    vector<int> v2 = v;
    sort(v2.begin(), v2.end());
    multiset<int> A;
    multiset<int> B;
    if (a >= b) {
        for (size_t i = 0; i < a; ++i) {
            A.insert(v2[i]);
        }
        for (size_t i = 0; i < b; ++i)
            B.insert(v2[i + a]);
    } else {
        for (size_t i = 0; i < b; ++i) {
            B.insert(v2[i]);
        }
        for (size_t i = 0; i < a; ++i)
            A.insert(v2[i + b]);
    }

    for (auto i : v) {
        auto itA = A.find(i);
        if (itA != A.end()) {
            cout << 1 << ' ';
            A.erase(itA);
        } else {
            cout << 2 << ' ';
            B.erase(B.find(i));
        }
    }
    cout << endl;



    return 0;
}
