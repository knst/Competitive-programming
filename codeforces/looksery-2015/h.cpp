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

vector<double> solve(int64_t A, int64_t B, int64_t C) {
    double a = A;
    double b = B;
    double c = C;

    if (A == 0) {
        return {-c / b};
    }

    double d = b * b - 4 * a * c;
    if (d < 0)
        return {};
    double s = sqrt(d);
    double s1 = (-b + s) / 2 / a;
    double s2 = (-b - s) / 2 / a;
    return {s1, s2};
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int64_t a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<double> solutions;
    for (int64_t i = -1; i < 2; ++i) {
        for (int64_t j = -1; j < 2; ++j) {
            for (int64_t k = -1; k < 2; ++k) {
                vector<double> v = solve(
                    i * j - k,
                    i * d + j * a - b - k * c,
                    a * d - b * c
                );
                for (auto I : v)
                    solutions.push_back(I);
            }
        }
    }
    double M = abs(solutions[0]);
    for (auto i : solutions)
        if (abs(i) < M)
            M = abs(i);
    cout.precision(18);
    cout << fixed << M << endl;


    return 0;
}
