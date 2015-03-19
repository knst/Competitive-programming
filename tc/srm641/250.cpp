#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <cmath>
#include <stack>
using namespace std;

struct TrianglesContainOrigin
{
    constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }
    long long count(vector <int> X, vector <int> Y) {
        size_t n = X.size();
        vector<double> a;
        for (size_t i = 0; i < n; ++i) {
            int x = X[i];
            int y = Y[i];
            double r = 0;
            if (x == 0 && y > 0) {
                r = const_pi() / 2.0;
            } else if (x == 0 && y < 0) {
                r = 3 * const_pi() / 2.0;
            } else if (x > 0 && y >= 0) {
                r = atan(y * 1.0 / x);
            } else if (x > 0 && y < 0) {
                r = atan(y * 1.0 / x) + 2 * const_pi();
            } else {
                r = atan(y * 1.0 / x) + const_pi();
            }
            a.push_back(r);
        }
        sort(a.begin(), a.end());
//        cerr.precision(2);
//        for (auto i : a) {
//            cerr << fixed << i << endl;
//        }

        long long result = 0;
        for (size_t i = 0; i < a.size(); ++i) {
            size_t end = a.size();
            for (size_t j = i+1; j < a.size(); ++j) {
                if (a[j] - a[i] > const_pi()) {
                    end = j;
                    break;
                }
            }
//            cerr << i << '-' << end << endl;
            size_t start = i + 1;
            for (size_t j = end; j < a.size(); ++j) {
                while (start < j && a[j] - a[start] > const_pi())
                    ++start;
                if (start <= end)
                    result += end - start;
            }
        }
        return result;
    }

};

int main() {
    TrianglesContainOrigin t;
    cout << t.count({-1,-1,1},
            {1,-1,0}) << endl;

    cout << t.count({-1,-1,1,2},
            {1,-1,2,-1}) << endl;

}
