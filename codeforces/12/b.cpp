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

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int main() {
    std::ios_base::sync_with_stdio(false);

    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    vector<char> v;
    for (auto i : s1)
        v.push_back(i);

    sort(v.begin(), v.end());
    int index = 0;
    while (v[index] == '0' && index + 1< v.size())
        ++index;
    swap(v[index], v[0]);
    for (int i = 0; i < v.size(); ++i)
        s1[i] = v[i];
    if (s1 == s2)
        cout << "OK" << endl;
    else
        cout << "WRONG_ANSWER" << endl;

    return 0;
}
