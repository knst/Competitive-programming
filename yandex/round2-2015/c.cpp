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

    size_t t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<pair<int, char>> v(26);
        for (size_t i = 0; i < 26; ++i) {
            v[i].second = i + 'a';
        }
        int n = s.size();
        for (size_t i = 0; i < n; ++i) {
            v[s[i] - 'a'].first++;
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        while (!v.empty() && v.back().first == 0)
            v.pop_back();
        int count = 0;
        char last = -1;
        char lasti = 0;
        while (!v.empty() && v.back().first == 1) {
            ++count;
            if (last == -1) {
                last = v.back().second;
                lasti = 1;
            }
            v.pop_back();
        }
        if (v.size() && v.back().first == 2) {
            --count;
            last = v.back().second;
            lasti = 2;
            v.pop_back();
        }
        if (count % 2 == 1) {
            cout << 2 << endl;
        } else {
            cout << 1 << ' ';
            char minimum = 'a' + 1;
            int t = 0;
            if (v.size() > 0) {
                for (auto i : v)
                    if (i.second < minimum) {
                        minimum = i.second;
                        t = i.first - 2;
                    }
                if (t == 0)
                    t = 2;
                for (int i = 0; i < t; ++i)
                    cout << minimum;
                cout << '\n';
            }
            else if (last != -1) {
                for (int i = 0; i < lasti; ++i)
                    cout << last;
                cout << endl;
            }
            else {
                cout << v.back().first;
            }
        }




    }

    return 0;
}
