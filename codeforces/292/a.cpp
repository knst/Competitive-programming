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

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(10, 0);
    for (auto i : s) {
        int I = i - '0';
        switch (I) {
        case 2:
            v[2]++;
            break;
        case 3:
            v[3]++;
            break;
        case 4:
            v[3]++;
            v[2]+=2;
            break;
        case 6:
            v[3]++;
        case 5:
            v[5]++;
            break;
        case 8:
            v[2]+=3;
        case 7:
            v[7]++;
            break;
        case 9:
            v[7]++;
            v[3]+=2;;
            v[2]++;
            break;
        default:
            break;
        }
    }

    for (size_t i = 7; i < 10; --i) {
        while (v[i]) {
            cout << i;
            --v[i];
        }
    }
    cout << endl;


    return 0;
}
