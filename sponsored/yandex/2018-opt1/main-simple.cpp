#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

using Point = pair<int, int>;

struct Step {
    int dx;
    int dy;
    vector<int> taxis;
};

double estimate(Point a, Point b) {
    int x = b.first - a.first;
    int y = b.second - a.second;
    return std::sqrt(x * x + y * y);
}

int main() {
    int t;
    cin >> t;
    vector<Point> taxi(t);
    for (auto& i : taxi) {
        cin >> i.first >> i.second;
    }
    int p;
    cin >> p;
    vector<Point> fan(p);
    for (auto& i : fan) {
        cin >> i.first >> i.second;
    }
    int z;
    cin >> z;
    vector<Point> zone(z);
    for (auto& i : zone) {
        cin >> i.first >> i.second;
    }

    vector<Step> steps;
    for (int i = 0; i < p; ++i) {
        double taxi_est = estimate(taxi[0], fan[i]);
        int taxi_best = 0;
        for (int j = 0; j < t; ++j) {
            double d = estimate(taxi[j], fan[i]);
            if (d < taxi_est) {
                taxi_est = d;
                taxi_best = j;
            }
        }

        double zone_est = estimate(zone[0], fan[i]);
        int zone_best = 0;
        for (int j = 0; j < z; ++j) {
            double d = estimate(zone[j], fan[i]);
            if (d < zone_est) {
                zone_est = d;
                zone_best = j;
            }
        }
        for (int j = 0; j < t; ++j) {
            if (taxi[j] == zone[zone_best]) {
                taxi_best = j;
            }
        }
        steps.push_back({fan[i].first - taxi[taxi_best].first, fan[i].second - taxi[taxi_best].second, {taxi_best}});
        steps.push_back({zone[zone_best].first - fan[i].first, zone[zone_best].second - fan[i].second, {taxi_best}});
        taxi[taxi_best] = zone[zone_best];
    }

    cout << steps.size() << endl;
    for (auto i : steps) {
        cout << "MOVE " << i.dx << ' ' << i.dy << ' ' << i.taxis.size();
        for (auto j : i.taxis) {
            cout << ' ' << j + 1;
        cout << endl;
        }
    }
}
