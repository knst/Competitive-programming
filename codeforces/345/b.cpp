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
    cin >> n;

    vector<int> v(n);
    for (auto& i : v)
        cin >> i;
    sort(v.begin(), v.end());
    size_t count = 0;
    size_t start = 0;
    size_t mm = 0;
    while (start < n) {
        size_t next = start;
        while (next < n && v[next] == v[start])
            ++next;
        count += min(mm, next - start);
        if (next - start > mm)
            mm += (next - start - mm);
        start = next;
    }
    cout << count << endl;;
    /*
    for (size_t i = 0; i < n; ++i) {
        int v;
        cin >> v;
        s.insert(v);
    }
    size_t count = 0;
    while (s.size()) {
        bool first = true;
        for (int i = 1; i <= 1000; ++i) {
            if (s.find(i) != s.end()) {
                if (first)
                    first = false;
                else {
                    j = 0;
                    ++count;
                }
            }
        }
    }
    cout << count << endl;
*/
    return 0;
}
