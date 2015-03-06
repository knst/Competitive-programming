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

    int n;
    cin >> n;

    string s;
    getline(cin, s);

    vector<int> times;
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        int hh = (s[1]-'0') * 10 + s[2] - '0';
        int mm = (s[4]-'0') * 10 + s[5] - '0';
        bool pm = s[7] == 'p';

        int time = 0;
        time = hh * 60 + mm;
        if (pm)
            time += 60 * 12;
        if (hh == 12) {
            time -= 60 * 12;
        }
        times.push_back(time);
        cerr << time << endl;
    }
    int count = 1;
    int days = 1;
    for (int i = 1; i < n; ++i) {
        if (times[i] < times[i-1]) {
            ++days;
            count = 1;
        } else {
            if (times[i] == times[i-1]) {
                ++count;
                if (count == 11) {
                    ++days;
                    count = 1;
                }
            } else
                count = 1;
        }
    }
    cout << days << endl;

    return 0;
}
