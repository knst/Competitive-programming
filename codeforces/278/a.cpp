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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int hpy, atky, defy;
    int hpm, atkm, defm;
    int h;
    int a;
    int d;
    cin >> hpy >> atky >> defy;
    cin >> hpm >> atkm >> defm;
    cin >> h >> a >> d;
    int minimal = numeric_limits<int>::max();
    for (int j= 0; j <= 300; ++j) {
        int atky2 = atky + j;
        int deltaY = atky2 - defm;
        if (deltaY <= 0)
            continue;

        for (int k = 0; k <= 300; ++k) {
            int defy2 = defy + k;
            int deltaM = atkm - defy2;
            int ty = (hpm +deltaY - 1)/ deltaY;
            int hpy2 = hpy;
            if (deltaM > 0) {
                hpy2 = max(hpy, deltaM * ty + 1);
            }
            int sum = j * a + k * d + (hpy2 - hpy) * h;
            if (sum < minimal)
                minimal = sum;
        }
    }
    cout << minimal << endl;


    return 0;
}
