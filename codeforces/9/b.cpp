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

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int vb;
    int vs;
    cin >> vb >> vs;
    vector<double> v(n);
    for (auto& i : v)
        cin >> i;
    int x;
    long long y;
    cin >> x >> y;

    double timeMin = 1e20;
    double diffMin = 1e20;
    int mini = -1;
    for (size_t I = 1; I < v.size(); ++I) {
        double i = v[I];
        double diff = sqrt(y * y + (x - i) * (x - i));
        double time = i / vb + diff / vs;
        if (time < timeMin-1e-10) {
            timeMin = time;
            diffMin = diff;
            mini = I;
        } else if (time < timeMin + 1e-10) {
            if (diff < diffMin - 1e-10) {
                diffMin = diff;
                mini = I;
            }
        }

    }
    cout << mini  + 1 << endl;

    return 0;
}
