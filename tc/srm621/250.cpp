#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct RadioRange{
    double RadiusProbability(vector<int> x, vector<int> y, vector<int> r, int z) {
        size_t n = x.size();
        vector<pair<double, double> > v;
        v.push_back(make_pair<double, double>(0, z));
        for (size_t i = 0; i < n; ++i) {
            double di = sqrt(1.0 * x[i] * x[i] + 1.0 * y[i] * y[i]);
            double rmin = di + r[i];
            double rmax = max(0.0, di - r[i]);
            vector<pair<double, double>> v2;
            for (auto j : v) {
                if (j.first < rmax)
                    v2.push_back(make_pair(j.first, min(j.second, rmax)));
                if (j.second > rmin)
                    v2.push_back(make_pair(max(j.first, rmin), j.second));
            }
            v = v2;
        }
        double sum = 0;
        for (auto i : v) {
            sum += i.second - i.first;
        }
        return sum / z;
    }
};


int main() {
    RadioRange a;
    cout << a.RadiusProbability({0}, {0}, {5}, 10) << endl;
    cout << a.RadiusProbability({0}, {0}, {10}, 10) << endl;
    cout << a.RadiusProbability({10}, {10}, {10}, 10) << endl;
    cout << a.RadiusProbability({11, -11, 0, 0} ,
            {0, 0, 11, -11} ,
            {10, 10, 10, 10}, 31) << endl;



    return 0;
}

