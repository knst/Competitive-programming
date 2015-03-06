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

int w(uint64_t x) {
    int count = 0;
    while (x) {
        ++count;
        x = x & (x-1);
    }
    return count;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        uint64_t l;
        uint64_t r;
        cin >> l >> r;
        uint64_t mask = 1;
        mask = mask << 63;
        uint64_t value1 = 0;
        uint64_t value2 = 0;
        while (mask && (mask & l) == (mask & r)) {
            if (mask & l) {
                value1 = value1 | mask;
                value2 = value2 | mask;
            }
            mask = mask >> 1;
        }
        if (mask & r) {
            value2 = value2 | mask;
        }
        uint64_t mask2 = mask;
        mask = mask >> 1;
        while (mask) {
            value1 = value1 | mask;
            mask = mask >> 1;
        }
        while (mask2 && !(mask2 & r)) {
            mask2 = mask2 >> 1;
        }
        mask2 = mask2 >> 1;
        while (mask2) {
            value2 = value2 | mask;
            mask2 = mask2 >> 1;
        }
        int count1 = w(value1);
        int count2 = w(value2);
        int count3 = w(r);
        if (count1 >= count2 && count1 >= count3)
            cout << value1 << endl;
        else if (count2 >= count3)
            cout << value2 << endl;
        else
            cout << r << endl;
    }


    return 0;
}

