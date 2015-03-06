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
#include <unordered_map>
#include <unordered_set>


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

using Point = pair<int,int>;
double Len(int x1, int y1, int x2, int y2) {
    double s1 = (x2 - x1);
    double s2 = (y2 - y1);
    double l = s1 * s1 + s2 * s2;
    return sqrt(l);
}
double Len(const Point& a, const Point& b) {
    return Len(a.first, a.second, b.first, b.second);
}
bool isValid(const Point& p, int n, int m) {
    if (p.first < 0)
        return false;
    if (p.second < 0)
        return false;
    if (p.first >= n)
        return false;
    if (p.second >= m)
        return false;
    return true;
}
int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int m;
    cin >> n >> m;
++n;++m;
    //for (int n = 1; n < 10; ++n) {
    //    for (int m = 1; m < 10; ++m) {
    //        if (n * m < 4)
    //            continue;

     /*       double maximal = 0;
            vector<int> best;
            for (int x1 = 0; x1 < n; ++x1) {
            for (int y1 = 0; y1 < m; ++y1) {

            for (int x2 = 0; x2 < n; ++x2) {
            for (int y2 = 0; y2 < m; ++y2) {
                if (x2 == x1 && y2 == y1)
                    continue;

            for (int x3 = 0; x3 < n; ++x3) {
            for (int y3 = 0; y3 < m; ++y3) {
                if (x3 == x2 && y3 == y2)
                    continue;
                if (x3 == x1 && y3 == y1)
                    continue;

            for (int x4 = 0; x4 < n; ++x4) {
            for (int y4 = 0; y4 < m; ++y4) {
                if (x4 == x3 && y4 == y3)
                    continue;
                if (x4 == x2 && y4 == y2)
                    continue;
                if (x4 == x1 && y4 == y1)
                    continue;
                double l1 = Len(x1, y1, x2, y2);
                double l2 = Len(x3, y3, x2, y2);
                double l3 = Len(x3, y3, x4, y4);
                if (l1 + l2 + l3 > maximal) {
                    maximal = l1 + l2 + l3;
                    best = {x1, y1, x2, y2, x3, y3, x4, y4};

                }

            }
            }
            }
            }
            }
            }
            }
            }
      */
            vector<Point> points;
            points.push_back({0, 0});
            points.push_back({0, 1});
            points.push_back({1, 0});
            points.push_back({1, 1});

            points.push_back({n-1, 0});
            points.push_back({n-2, 0});
            points.push_back({n-1, 1});
            points.push_back({n-2, 1});

            points.push_back({n-1, m-1});
            points.push_back({n-2, m-1});
            points.push_back({n-1, m-2});
            points.push_back({n-2, m-2});

            points.push_back({0, m-1});
            points.push_back({1, m-1});
            points.push_back({0, m-2});
            points.push_back({1, m-2});
            double maximal2 = 0;
            vector<Point> best2;
            for (const auto& a : points) {
            for (const auto& b : points) {
            for (const auto& c : points) {
            for (const auto& d : points) {
                if (a == b)
                    continue;
                if (a == c)
                    continue;
                if (a == d)
                    continue;
                if (b == c)
                    continue;
                if (b == d)
                    continue;
                if (c == d)
                    continue;
                if (!isValid(a, n, m))
                    continue;
                if (!isValid(b, n, m))
                    continue;
                if (!isValid(c, n, m))
                    continue;
                if (!isValid(d, n, m))
                    continue;
                double len = Len(a, b) + Len(b, c) + Len(c, d);
                if (len > maximal2) {
                    maximal2 = len;
                    best2 = {a, b, c, d};
                }
            }
            }
            }
            }
            for (const auto& i : best2) {
                cout << i.first << ' ' << i.second << endl;;
            }
    //        cout<< maximal2 << endl;

//            if (maximal2 != maximal) {
 //               cout << "OLOLO";
  //          }
   //         cout << n << ' ' << m << ' ' << maximal << endl;
//            for (auto i : best) {
//////////////////                cout << i << ' ';
  //          }
 //           cout << endl;
//        }
 //   }


    return 0;
}
