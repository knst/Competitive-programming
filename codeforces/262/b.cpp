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

int sumdigit(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}
int main() {
    std::ios_base::sync_with_stdio(false);

    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    set<long long> results;
    for (long long s = 1; s <= 90; ++s) {
        long long sp = 1;
        for (int i = 0; i < a; ++i) {
            sp *= s;
            if (sp >= 1000 * 1000 * 1000)
                sp = 0;
        }
        if (sp) {
            long long result = b * sp + c;
            if (result < 1000 * 1000 * 1000 && sumdigit(result) == s) {
                results.insert(result);
            }

        }

    }
    cout << results.size() << endl;
    if (results.size()) {
        for (auto i : results) {
            cout << i << ' ';
        }
        cout << endl;
    }


    return 0;
}
