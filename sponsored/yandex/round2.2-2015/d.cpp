/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <chrono>
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

int test(int64_t l) {
    int result = 0;
    int64_t l2 = l * l;
    static vector<int> m(1000001, -1);
    if (m[l] != -1)
        return m[l];
    int64_t y = l;
    int64_t y2 = l * l;
    for (int64_t x = 1, x2 = 1; x2 < l2; x2 += x + x + 1, ++x) {
        while (x2 + y2 > l2) {
            --y;
            y2 -= y + y + 1;
        }
        if (y < x)
            break;
        if (y2 + x2 == l2) {
            result = max(result, test(x) + 1);
            result = max(result, test(y) + 1);
        }
    }
    return m[l] = result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int l = 967525;
//    cin >> l;
//    for (int l = 967525 - 100; l <= 967525 + 100; ++l) {
//        if (l % 1000 == 0)
//            cerr << l << endl;
//        chrono::steady_clock::time_point start = chrono::steady_clock::now();
        int result = test(l);
        cout << result << endl;
//        chrono::steady_clock::time_point end = chrono::steady_clock::now();
//        int count = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
//        if (count > 500)
//            cout << l << ":\t" << result << "\t" << count << endl;
//    }
    return 0;
}
