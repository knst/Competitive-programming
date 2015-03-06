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

pair<int, int> test(const string& line, const string& a, const string& b) {
    int a1 = -1;
    int b1 = -1;

    int n = line.size();
    for (int i = 0; a1 == -1 && i -1 + a.size() < n; ++i) {
        bool ok = true;
        for (int j = 0; j < a.size(); ++j) {
            if (line[i + j] != a[j])
                ok = false;
        }
        if (ok)
            a1 = i;
    }
    if (a1 == -1)
        return {a1, b1};

    for (int i = a1 + a.size(); b1 == -1 && i -1 + b.size() < n; ++i) {
        bool ok = true;
        for (int j = 0; j < b.size(); ++j) {
            if (line[i + j] != b[j])
                ok = false;
        }
        if (ok)
            b1 = i;
    }
    return {a1, b1};
}

int main() {
    std::ios_base::sync_with_stdio(false);

    string line;
    string a;
    string b;
    cin >> line >> a >> b;
    pair<int,int> First = test(line, a, b);
    for (int i = 0, j = line.size() - 1; i < j; ++i, --j) {
        swap(line[i], line[j]);
    }
    pair<int, int> Second = test(line, a,b);

    bool f_a = First.second != -1;
    bool f_b = Second.second != -1;
    if (f_a && f_b) {
        cout << "both";
    } else if (f_a && !f_b) {
        cout << "forward";
    } else if (!f_a && f_b) {
        cout << "backward";
    } else
        cout << "fantasy";
    cout << endl;

    return 0;
}
