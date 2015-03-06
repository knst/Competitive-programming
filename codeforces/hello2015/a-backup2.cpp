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

inline vector<char> prods(uint32_t mask) {
    vector<char> result;
    static const char primes[]   = {2, 2, 2,  2,  2, 3, 3, 3 , 5, 5 , 7, 7 , 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    for (size_t i = 0; i < 25; ++i) {
        if (mask & (1 << i))
            result.push_back(primes[i]);
    }

    return result;
}

constexpr int MOD = 1000 * 1000 * 1000 + 7;

inline long long Mod(const vector<char>& p) {
    long long result = 1;
    for (auto i : p)
        result = result * i % MOD;
    return result;
}

inline bool Less(const vector<char>& a, const vector<char>& b) {
    long long a1 = 1;
    long long b1 = 1;
    long long a2 = 1;
    long long b2 = 1;
    for (size_t i = 0; i + 1 < a.size(); i += 2) {
        a1 *= a[i];
        a2 *= a[i+1];
    }
    if (a.size() & 1)
        a1 *= a.back();

    for (size_t i = 0; i + 1 < b.size(); i += 2) {
        b1 *= b[i];
        b2 *= b[i+1];
    }
    if (b.size() & 1)
        b1 *= b.back();

    double result = static_cast<double>(a1) / b1 * a2 / b2;
    if (result < 1.0)
        return true;
    return false;
}

uint32_t Mask(int value) {
    uint32_t mask = 0u;
    static const char divisors[] = {2, 4, 8, 16, 32, 3, 9, 27, 5, 25, 7, 49, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    for (size_t i = 0; i < 25; ++i) {
        if (value % divisors[i] == 0)
            mask = mask | (1ull << i);
    }
    return mask;
}

string Print(const vector<char>& c) {
    string result;
    for (auto i : c) {
        result = result + static_cast<char>(i + '0') + ' ';
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    size_t m;
    cin >> n >> m;
    vector<uint32_t> a(n);

    for(size_t i = 0; i < n; ++i) {
        int value;
        cin >> value;
        a[i] = Mask(value);
    }

//    vector<double> M(1 << 25);
//    for (uint32_t i = 0; i < (1 << 25); ++i) {
//        i = Double(

    vector<uint32_t> r(n, numeric_limits<uint32_t>::max());
    for (size_t i = 0; i < n; ++i) {
        uint32_t mask = 0;
        for (size_t j = i; j < n; ++j) {
            mask = mask | a[j];

            size_t index = j - i;

            if ((mask & r[index]) == r[index])
                continue;
            if (r[index] == numeric_limits<uint32_t>::max() || (r[index] & mask) == mask) {
                r[index] = mask;
            } else {
                uint32_t a = mask ^ (mask & r[index]);
                uint32_t b = r[index] ^ (mask & r[index]);
                auto pa = prods(a);
                auto pb = prods(b);
                if (Less(pa, pb)) {
                    r[index] = mask;
                }
            }
        }
    }

    vector<int> result(n);
    for (size_t i = 0; i < n; ++i)
        result[i] = Mod(prods(r[i]));

    for (size_t i = 0; i < m; ++i) {
        int index;
        cin >> index;
        cout << result[index-1] << '\n';
    }
    cout.flush();


    return 0;
}
