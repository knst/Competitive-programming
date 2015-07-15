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

namespace std {
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
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
    cin.tie(0);

    size_t n;
    cin >> n;
    vector<int> v(n);
    int minimal = numeric_limits<int>::max();
    for (auto& i : v) {
        cin >> i;
        minimal = min(i, minimal);
    }

    vector<int> vo = v;
    bool flag = false;
    do {
        random_shuffle(v.begin(), v.end());
        flag = false;
        for (auto& i : v) {
            while (i > minimal) {
                i /= 2;
                minimal = min(i, minimal);
                flag = true;
            }
        }
    } while (flag);
    size_t result = numeric_limits<size_t>::max();
    for (int value = minimal; value <= 100000; value = value * 2) {
        vector<int> q = vo;
        size_t count = 0;
        bool valid = true;
        for (auto i : q) {
            size_t countI = 0;
            bool validI = false;
            while (i && !validI) {
                for (int j = i, iter = 0; j <= value; j *= 2, ++iter) {
                    if (j == value) {
                        validI = true;
                        count += countI + iter;
                    }
                }
                ++countI;
                i /= 2;
            }
            if (!validI)
                valid = false;
        }
        if (valid)
            result = min(result, count);
    }
    cout << result << endl;



    return 0;
}
