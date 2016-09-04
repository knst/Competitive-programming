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

    int n;
    size_t m;
    cin >> n >> m;
    int rotate = 0;
    bool mirrored = false;
    for (size_t i = 0; i < m; ++i) {
        int type;
        int diff;
        cin >> type >> diff;
        if (type == 1) {
            rotate += diff;
        } else {
            if (mirrored) {
                rotate = rotate + diff;
            } else {
                rotate = n + rotate - diff;
            }
            mirrored = !mirrored;
        }
        rotate %= n;
    }
//    cerr << "state: " << rotate << ' ' << mirrored << endl;
    if (mirrored) {
        cout << "2 ";
        if (rotate == 0)
            cout << 0;
        else {
            int ans = n - rotate;
            cout << ans;
        }
    } else {
        cout << "1 ";
        if (rotate == 0)
            cout << 0;
        else
            cout << n - rotate;
    }
    cout << endl;

    return 0;
}
