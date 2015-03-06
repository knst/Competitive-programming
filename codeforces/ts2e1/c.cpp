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

const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, -1, 0, 1};

const int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

namespace {
    string to_string2(int n) {
        char s[10];
        sprintf(s, "%d", n);
        return s;
    }
}

string GetA(int n) {
    return "A" + to_string2(n);
}

string GetB(int n) {
    return "B" + to_string2(n);
}

string Not(const string& a) {
    return "(" + a + "|" + a + ")";
}

string Or(const string& a, const string& b) {
    return "(" + Not(a) + "|" + Not(b) + ")";
}

string And(const string& a, const string& b) {
    return Not("(" + a + "|" + b + ")");
}

/*
string solve(int n) {
    --n;
    if (n == 0)
        return Not(And(GetA(0), GetB(0)));
    else
        return "((" + Not(GetA(n)) + "|" + Not(GetB(n)) + ")|" + solve(n) + ")";

}
*/

string solve(int n) {
    --n;
    if (n == 0)
        return "((A0|B0)|(A0|B0))";
    return "((" + GetA(n) + "|" + GetB(n) + ")|((" + Not(GetA(n)) + "|" + Not(GetB(n)) + ")|" + solve(n) + "))";
}

bool shef(bool x, bool y) {
    return !x | !y;
}
int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << solve(n) << endl;

    return 0;
}
