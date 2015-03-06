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
//test speed
/*
namespace std {
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}; */
namespace std {
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
};

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

int main() {
    std::ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    s += '(';
    int maximal = -1;
    int count = 0;


    vector<int> v;
    for (const auto &i : s) {
        if (i == ')') {
            if (!v.empty()) {
                if (v.back() == -1) {
                    v.pop_back();
                    v.push_back(2);
                } else {
                    size_t n = v.size();
                    if (n > 1 && v[n-1] > 0 && v[n-2] == -1) {
                        v[n-2] = v[n-1] + 2;
                        v.pop_back();
                    } else {
                        v.push_back(-2);
                    }
                }
            }
        } else {
            v.push_back(-1);
        }
        size_t n = v.size();
        if (n > 1 && v[n-1] > 0 && v[n-2] > 0) {
            v[n-2] = v[n-1] + v[n-2];
            v.pop_back();
        }
 /*       cout << i << ": ";
        for (auto & j : v) {
            cout << j << ' ';
        }
        cout << endl;
*/
    }

    for (const auto& i : v) {
//        cerr << i << endl;
        if (i > maximal) {
            maximal = i;
            count = 0;
        }
        if (i == maximal)
            ++count;
    }
    /*
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '(')
            ++sum;
        if (s[i] == ')')
            --sum;
        ++len;
        if (sum == 0) {
            if (len > maximal) {
                count = 0;
                maximal = len;
            }
            if (len == maximal)
                ++count;
        }
        if (sum < 0) {
            len = 0;
            sum = 0;
        }

    }
*/
    if (maximal <= 0) {
        cout << "0 1" << endl;
    } else {
        cout << maximal << ' ' << count << endl;
    }

    return 0;
}
