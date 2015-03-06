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

const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, -1, 0, 1};

const int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main() {
    std::ios_base::sync_with_stdio(false);

    int x;
    cin >> x;
    int k = x > 0 ? x : -x;
    int sum = 0;
    int iter = 0;
    while (sum < k) {
        ++iter;
        sum += iter;
    }
    if (sum != k) {
        ++iter;
        if (iter % 2 == 0) {
            if ((k - sum) % 2 == 0)
                --iter;
            else
                ++iter;
        } else {
            if ((k - sum) % 2 != 0)
                iter =iter;
            else --iter;
        }
    }
    cout << iter << endl;
    return 0;
    for (int k = 0; k < 200; ++k) {
        set<int> values;
        values.insert(0);
        for (int i = 0; i < 10000; ++i) {
            set<int> values2;
            for (auto j : values) {
                values2.insert(i + j);
                values2.insert(j - i);
            }
/*            cout << i << ": ";
            for (auto j : values2) {
                if (j >= 0)
                    cout << j << " ";
            }
            cout << endl;
 */           values = values2;
            if (values2.find(k) != values2.end()) {
                cout << k << ":\t" << i << '\t';
                int sum = 0;
                int iter = 0;
                while (sum < k) {
                    ++iter;
                    sum += iter;
                }
                cout << iter << '\t';
                cout << i - iter << '\t';
                if (sum != k) {
                    ++iter;
                    if (iter % 2 == 0) {
                        if ((k - sum) % 2 == 0)
                            --iter;
                        else
                            ++iter;
                    } else {
                        if ((k - sum) % 2 != 0)
                            iter =iter;
                        else --iter;
                    }
                }
                cout << i - iter << '\t';
                for (int j = 0; j < i; ++j)
                    cout << '#';
                cout << endl;
                break;
            }
        }
    }




    return 0;
}
