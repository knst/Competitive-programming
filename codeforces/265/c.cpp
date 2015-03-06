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

long long Get10(long long a, long long pow, long long MOD) {
    pow = pow % (MOD - 1);
    if (pow == 0)
        return 1;
    if (pow % 2 == 1)
        return Get10(a, pow - 1, MOD) * a % MOD;
    long long b = Get10(a, pow / 2, MOD);
    return b * b % MOD;
}
int main() {
    std::ios_base::sync_with_stdio(false);

    const long long MOD = 1000000007;

    vector<pair<long long, long long>> v(10);
    for (int i = 0; i < 10; ++i) {
        v[i] = {i, 1};
    }
    string s;
    cin >> s;
    int n;
    cin >> n;
    stack<pair<int, string>> St;
    for (int i = 0; i < n; ++i) {
        string ss;
        cin >> ss;
        St.push({ss[0] - '0', ss.substr(3)});

    }
    while (!St.empty()) {
        auto i = St.top();
        long long new_value = 0;
        long long new_len = 0;
        for (const auto& j : i.second) {
            new_value = (new_value * Get10(10, v[j-'0'].second, MOD) % MOD + v[j - '0'].first) % MOD;
            new_len = (new_len + v[j-'0'].second) % (MOD - 1);
        }
        v[i.first].first = new_value;
        v[i.first].second = new_len;
        St.pop();
//        for (auto i : v) {
//            cerr << "i: " << i.first << ' ' << i.second << endl;
//        }
    }
//    for (auto i : v) {
//        cerr << "i: " << i.first << ' ' << i.second << endl;
//    }
    long long result = 0;
    for (const auto& i : s) {
        result = (result * Get10(10, v[i-'0'].second, MOD) % MOD + v[i-'0'].first) % MOD;
    }
    cout << result << endl;

    return 0;
    {
        int mod;
        cin >> mod;
        string s;
        cin >> s;
        int n = s.size();
        int value = 0;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            value = value * 10 + s[i] -'0';
            result = (result * 10 + s[i] - '0') % mod;
        }
        cout << value % mod << ' ' << result << endl;

    }

    return 0;
}
