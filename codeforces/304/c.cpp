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
    size_t n1;
    cin >> n1;
    vector<int> v1(n1);
    for (auto& i : v1)
        cin >> i;
    size_t n2;
    cin >> n2;
    vector<int> v2(n2);
    for (auto & i : v2)
        cin >> i;

    size_t count = 0;
    set<pair<vector<int>,vector<int>>> s;
    while (s.find({v1, v2}) == s.end() && v1.size() && v2.size()) {
        ++count;
        s.insert({v1, v2});
        int t1 = v1.front();
        int t2 = v2.front();
        for (size_t i = 1; i < v1.size(); ++i)
            v1[i - 1] = v1[i];
        for (size_t i = 1; i < v2.size(); ++i)
            v2[i - 1] = v2[i];
        v1.pop_back();
        v2.pop_back();
        if (t1 > t2) {
            v1.push_back(t2);
            v1.push_back(t1);
        } else {
            v2.push_back(t1);
            v2.push_back(t2);
        }
    }
    if (v1.empty()) {
        cout << count << ' ' << 2 << endl;
    } else if (v2.empty()) {
        cout << count << ' ' << 1 << endl;
    } else
        cout << -1 << endl;


    return 0;
}
