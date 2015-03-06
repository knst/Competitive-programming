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
    int count = 0;
    int result = 0;
    while (getline(cin, s)) {
        cerr << "test: " << s << endl;
        if (s[0] == '+')
            ++count;
        else if (s[0] == '-')
            --count;
        else if (s.size() > 1) {
            int index = 0;
            while (s[index] != ':')
                ++index;
            cerr << "result: " << result << endl;
            result += (s.size() - index - 1) * count;
        }

    }
    cout << result << endl;

    return 0;
}
