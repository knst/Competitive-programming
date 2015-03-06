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
    vector<string> text;
    size_t  maximal = 0;
    while (getline(cin, s)) {
        text.push_back(s);
        maximal = max(s.size(), maximal);
    }
    bool toRight = false;
    for (int i = 0; i < maximal + 2; ++i)
        cout << "*";
    cout << endl;
    for (size_t  i = 0; i < text.size(); ++i) {
        cout << "*";

        int spaces = maximal - text[i].size();
        for (int i =0 ; i < spaces / 2; ++i)
            cout << ' ';

        if ((spaces % 2) && toRight) {
            cout << ' ';
        }
        cout << text[i];
        for (int i = 0; i < spaces / 2; ++i)
            cout << ' ';
        if ((spaces % 2) && !toRight) {
            cout << ' ';
        }
        if (spaces % 2)
            toRight = !toRight;

        cout << "*" ;
        cout << endl;
    }
    for (int i = 0; i < maximal + 2; ++i)
        cout << "*";
    cout << endl;




    return 0;
}
