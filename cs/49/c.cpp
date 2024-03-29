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

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    vector<int> v(255);
    for (auto i : s) {
        ++v[i];
    }

    int maximum = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        maximum = max(v[i], maximum);
    }

    string lengthest;

    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == maximum) {
            string test;
            test += static_cast<char>(i);

            bool stop = false;
            while (!stop) {
                int count = 0;
                std::size_t found = s.find(test);
                while (found != std::string::npos) {
                    found = s.find(test, found + 1);
                    ++count;
                }
                if (count == maximum) {
                    if (test.size() > lengthest.size()) {
                        lengthest = test;
                    }
                    size_t next = s.find(test) + test.size();
                    if (next >= s.size()) stop = true;
                    else test += s[next];
                } else {
                    stop = true;
                }
            }
        }
    }
    cout << lengthest << endl;
}
