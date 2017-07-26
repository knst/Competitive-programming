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

#include <cmath>

using namespace std;

namespace std { template <class T1, class T2> struct hash<pair<T1, T2>> {
    size_t operator()(const pair<T1, T2>& p) const { return hash<T1>()(p.first) ^ hash<T2>()(p.second); }
};}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1)) * 4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

template<class T> T gcd(T A, T B) { return B == 0 ? A : gcd(B, A % B); }

uint64_t powMod(uint64_t G, uint64_t pow, uint64_t M) {
    if (pow == 0) return 1;
    return pow % 2 == 0 ? powMod(G * G % M, pow / 2, M) : powMod(G, pow - 1, M) * G % M;
}

uint64_t inverse(uint64_t X, uint64_t M) { return X == 1 ? 1 : powMod(X, M - 2, M); }

string proc(int k) {
    switch (k) {
        case 1: return "-1";
        case 2: return "1";
        case 3: return "7";
        case 4: return "4";
        case 5: return "2";
        case 6: return "0";
        case 7: return "8";
    }
    int n8 = k / 7;
    int rem = k - n8 * 7;
    string result;
    if (rem == 0) {
        for (int i = 0; i < n8; ++i) {
            result += '8';
        }
        return result;
    }
    if (rem == 1) {
        result = "10";
        for (int i = 1; i < n8; ++i) {
            result += '8';
        }
        return result;
    }
    if (rem == 2) {
        result = "18";
        for (int i = 1; i < n8; ++i) {
            result += '8';
        }
        return result;
    }
    if (rem == 3) {
        if (n8 > 1) {
            result = "200";
            for (int i = 2; i < n8; ++i) {
                result += '8';
            }
        } else {
            result = "22";
            for (int i = 1; i < n8; ++i) {
                result += '8';
            }
        }
        return result;
    }
    if (rem == 4) {
        result = "20";
        for (int i = 1; i < n8; ++i) {
            result += '8';
        }
        return result;
    }
    if (rem == 5) {
        result = "28";
        for (int i = 1; i < n8; ++i) {
            result += '8';
        }
        return result;
    }
    if (rem == 6) {
        result = "68";
        for (int i = 1; i < n8; ++i) {
            result += '8';
        }
        return result;
    }
    throw "???";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    map<int, char> digits = {
        {0, 6},
        {1, 2},
        {2, 5},
        {3, 5},
        {4, 4},
        {5, 5},
        {6, 6},
        {7, 3},
        {8, 7},
        {9, 6}
    };
    int k;
    cin >> k;
    cout << proc(k) << endl;;
    return 0;
    for (int k = 1; k < 60; ++k) {
        string s = proc(k);
        string s2 = "-1";
        for (int j = 0; j < 1000000; ++j) {
            int x = j;
            int count = 0;
            do {
                count += digits[x % 10];
                x /= 10;
            } while (x);
            if (count == k) {
                s2 = to_string(j);
                break;
            }
        }
        if (s != s2) {
            cout << k << ' ' << s << ' ' << s2 << endl;
        }
    }

    /*
    map<int, int> useful = {
        {0, 6},
        {1, 2},
        {2, 5},
        {4, 4},
        {6, 6},
        {7, 3},
        {8, 7}
    };
    */
}
