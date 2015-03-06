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

double gcd(double a, double b) {
    static const double eps = 1e-3;
    if (b < eps)
        return a;
    return gcd(b, a - floor(a / b) * b);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    vector<pair<double, double>> points(3);
    for (auto& i : points)
        cin >> i.first >> i.second;

    double lens[3];
    for (int i = 0; i < 3; ++i) {
        int j = (i + 1) % 3;
        double a1 = points[i].first - points[j].first;
        double a2 = points[i].second- points[j].second;
        lens[i] = sqrt(a1 * a1 + a2 * a2);
        cerr << lens[i] << ' ';
    }
    cerr << endl;
    double angles[3];
    for (int i = 0; i < 3; ++i) {
        int a = i;
        int b = (i + 1) % 3;
        int c = (i + 2) % 3;
        double angle = acos((- lens[c] * lens[c] + lens[a] * lens[a] + lens[b] * lens[b]) / 2.0 / lens[a] / lens[b]);
        cerr << angle << ' ' << angle / const_pi() * 180 << endl;
        angles[i] = angle;
    }
    cerr << endl;
    double g = gcd(angles[0], gcd(angles[1], angles[2]));
    cerr << g << endl;
//    double Angle = angles[0] * angles[1] * angles[2] / g / g;
    double Angle = g * 2;
    int n = round(2.0 * const_pi() / Angle);
    cerr << n << ' ' << Angle << endl;

    double p = (lens[0] + lens[1] + lens[2]) / 2.0;
    double s = n / 32.0 * (lens[0] * lens[1] * lens[2]) * (lens[0] * lens[1] * lens[2]) / p / (p-lens[0]) / (p - lens[1]) / (p-lens[2]) * sin(2 * const_pi() / n);
    cerr << p << ' ' << s << endl;
    cout.precision(20);
    cout << s << endl;



    return 0;
}
