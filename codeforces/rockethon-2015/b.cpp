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
}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int f(vector<int>& values) {
    int sum = 0;
    for (size_t i = 0; i < values.size(); ++i) {
        for (size_t j = i; j < values.size(); ++j) {
            int minimum = values.size();
            for (size_t k = i; k <= j; ++k) {
                if (values[k] < minimum)
                    minimum = values[k];
            }
            sum += minimum;
        }
    }
    return sum;
}


int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    int m;
    cin >> n >> m;
    vector<int> v(n);
    for (size_t i = 0; i < n; ++i)
        v[i] = i + 1;
    int maximum = -1;
    int maximumi = 0;
    auto ans = v;
    int index = 0;
    map<int,int> M;
    do {
        int value = f(v);
        if (value > maximum) {
            maximum = value;
            maximumi = 0;
        }
        if (value == maximum) {
            maximumi++;
            if (maximumi == m)
                ans = v;
        }
        M[value]++;
        cout << value << ": " <<  1000 + index++ << " ";
        for (auto i : v)
            cout << i << ' ';
        cout << endl;

    } while (next_permutation(v.begin(), v.end()));
    for (auto i : M)
        cout << i.first << ' '<< i.second << endl;
    for (auto i : ans)
        cout << i << ' ';
    cout << endl;


    return 0;
}
