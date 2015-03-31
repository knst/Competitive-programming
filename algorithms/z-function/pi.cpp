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

void print_array(const auto &a) {
    for (const auto& i : a)
        cout << i << ' ';
    cout << endl;
}

vector<size_t> Pi(const string& s) {
    size_t n = s.size();
    vector<size_t> pi(n, 0);
    size_t k = 0;
    for (size_t i = 1; i < n; ++i) {
        while (s[i] != s[k] && k > 0)
            k = pi[k-1];
        if (s[i] == s[k])
            ++k;
        pi[i] = k;
    }
    return pi;
}

vector<size_t> Z(const string& s) {
    size_t n = s.size();
    vector<size_t> pi = Pi(s);
    vector<size_t> z(n, 0);
    for (size_t i = 1; i < n; ++i) {
        if (pi[i] < pi[i-1])
            z[i-pi[i-1]] = pi[i-1];
        if (z[pi[i]] && z[i] == 0)
            z[i] = z[pi[i]];
    }
    if (n && s[n-1] == s[0])
        z[n-1] = 1;
    if (n)
        z[0] = n;
    return z;
}

int main() {
    std::ios_base::sync_with_stdio(false);


    print_array(Pi("abaabab"));
    print_array(Pi("abcdabscabcdabia"));
    print_array(Pi("abcdabcabcdabcdab"));

    print_array(Z("abaabab"));
    print_array(Z("abcdabscabcdabia"));
    print_array(Z("abcdabcabcdabcdab"));


    return 0;
}
