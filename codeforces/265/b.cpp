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
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
};

long long len_p(const int a[3], const int b[3]) {
    long long x = b[0] - a[0];
    long long y = b[1] - a[1];
    long long z = b[2] - a[2];
    return x * x + y * y + z * z;
}
bool test_cube(const int points[8][3]) {
    vector<long long> v;
    for (int i = 0; i < 8; ++i) {
        for (int j = i + 1; j < 8; ++j) {
            v.push_back(len_p(points[i], points[j]));
        }
    }
    sort(v.begin(), v.end());
    if (v[0] < 1)
        return false;
    for (int i = 1; i < 12; ++i) {
        if (v[i] != v[i-1])
            return false;
    }
    if (v[12] != v[0] * 2)
        return false;
    for (int i = 12 + 1; i < 24; ++i) {
        if (v[i] != v[i-1])
            return false;
    }
    if (v[24] != v[0] * 3)
        return false;
    for (int i = 24 + 1; i < 28; ++i) {
        if (v[i] != v[i-1])
            return false;
    }

    cout << "YES" << endl;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << points[i][j] << ' ';
        }
        cout << endl;
    }
    return true;
}

bool try_next(int points[8][3], int depth) {
    if (depth == 8) {
        return test_cube(points);
    }
    sort(points[depth], points[depth] + 3);
    do {
        if(try_next(points, depth + 1))
            return true;
    } while (next_permutation(points[depth], points[depth] + 3));
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int points[8][3];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> points[i][j];
        }
        sort(points[i], points[i] + 3);
    }
    if (!try_next(points, 1))
        cout << "NO" << endl;

    return 0;
}

