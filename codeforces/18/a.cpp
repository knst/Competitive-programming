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

int len(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool test(int x1, int y1, int x2, int y2, int x3, int y3) {
    int l1 = len(x1, y1, x2, y2);
    int l2 = len(x2, y2, x3, y3);
    int l3 = len(x3, y3, x1, y1);
    if (l1 == 0 || l2 == 0 || l3 == 0)
        return false;
    if (l1 + l2 == l3)
        return true;
    if (l1 + l3 == l2)
        return true;
    if (l2 + l3 == l1)
        return true;
    return false;
}
int A(int x) {
    return x > 0 ? x : -x;
}
int main() {
    std::ios_base::sync_with_stdio(false);

    int x1, y1;
    int x2, y2;
    int x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    bool A_ = false;
    bool B = false;
    for (int a1 = -1; a1 < 2; ++a1) {
        for (int b1 = -1; b1 < 2; ++b1) {
            for (int a2 = -1; a2 < 2; ++a2) {
                for (int b2 = -1; b2 < 2; ++b2) {
                    if (test(x1 + a1, y1 + b1, x2 + a2, y2 + b2, x3, y3)) {
                        int sum = A(a1) + A(a2) + A(b1) + A(b2);
                        if (sum == 0)
                            A_ = true;
                        if (sum == 1)
                            B = true;
                    }
                }
            }
        }
    }
    if (A_) {
        cout << "RIGHT";
    } else if (B)
        cout << "ALMOST";
    else
        cout << "NEITHER";

    return 0;
}
