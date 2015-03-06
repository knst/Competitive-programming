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

using Point = pair<int,int>;

int dist(const pair<Point,int> &p1, const pair<Point,int> &p2) {
    Point a = p1.first;
    Point b = p2.first;
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

bool check(const vector<pair<Point,int>>& v) {
    for (int i = 0; i < 2; ++i) {
        if (dist(v[i * 4 + 0], v[i * 4 + 1]) != dist(v[i * 4 + 2], v[i * 4 + 3]))
            return false;

        if (dist(v[i * 4 + 1], v[i * 4 + 2]) != dist(v[i * 4 + 0], v[i * 4 + 3]))
            return false;
    }

    vector<long long> values;
    for (int i = 0; i < 4; ++i) {
        for (int j = i+1; j < 4; ++j) {
            values.push_back(dist(v[i], v[j]));
        }
    }
    sort(values.begin(), values.end());
    for (int i = 1; i < 4; ++i)
        if (values[i] != values[i-1])
            return false;
    if (values[4] != values[3] * 2)
        return false;
    if (values[5] != values[4])
        return false;
    if (values[5] == 0)
        return false;

    vector<long long> valuesB;
    for (int i = 0; i < 4; ++i) {
        for (int j = i+1; j < 4; ++j) {
            valuesB.push_back(dist(v[i+4], v[j+4]));
        }
    }
    sort(valuesB.begin(), valuesB.end());
    if (valuesB[0] != valuesB[1])
        return false;
    if (valuesB[2] != valuesB[3])
        return false;
    if (valuesB[4] != valuesB[5])
        return false;
    if (valuesB[0] + valuesB[2] != valuesB[4])
        return false;
    if (valuesB[0] == 0 || valuesB[2] == 0)
        return false;
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    vector<pair<Point, int>> v(8);
    for (int j = 0; j < 8; ++j) {
        auto &i = v[j].first;
        cin >> i.first >> i.second;
        v[j].second = j + 1;
    }
    sort(v.begin(), v.end());
    do {
        if (check(v)) {
            cout << "YES" << endl;
            for (int k = 0; k < 2; ++k) {
                for (int i =0; i < 4; ++i)
                    cout << v[k * 4 + i].second << ' ';
                cout << endl;
            }
            return 0;
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << "NO" << endl;
    return 0;
}
