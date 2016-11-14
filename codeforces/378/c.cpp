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

void EMPTY() {
    cout << "NO" << endl;
    exit(0);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n;
    cin >> n;

    int s1 = 0;
    int s2 = 0;
    vector<int> v(n);
    for (auto& i : v) {
        cin >> i;
        s1 += i;
    }

    size_t k;
    cin >> k;
    vector<int> u(k);
    for (auto& j : u) {
        cin >> j;
        s2 += j;
    }
    if (s1 != s2) {
        EMPTY();
    }

    vector<pair<size_t, char>> answer;
    for (size_t i = 0; i < k; ++i) {
        int sum = 0;
        size_t last = i;
        while (sum < u[i] && last < v.size()) {
            sum += v[last];
            ++last;
//            cerr << "t: " << last << ' ' << sum << endl;
        }
//        cerr << "s: " << sum << ' '<< endl;
        if (sum != u[i]) {
            EMPTY();
        }
//            cerr << "n: " << last << ' ' << i << endl;
        while (last - i > 1) {
            int best = -1;
            int bests = -1;
            pair<size_t, size_t> bestI = {0, 0};
            for (size_t j = i + 1; j < last; ++j) {
                if (v[j] > v[j-1]) {
                    if (v[j] > best) {
                        best = v[j];
                        bests = v[j] + v[j-1];
                        bestI = {j, j - 1};
                    }
                    if (v[j] == best && v[j] + v[j-1] > bests) {
                        best = v[j];
                        bests = v[j] + v[j-1];
                        bestI = {j, j - 1};
                    }
                }
                if (v[j] < v[j-1]) {
                    if (v[j - 1] > best) {
                        best = v[j - 1];
                        bests = v[j] + v[j-1];
                        bestI = {j - 1, j};
                    }
                    if (v[j - 1] == best && v[j] + v[j-1] > bests) {
                        best = v[j - 1];
                        bests = v[j] + v[j-1];
                        bestI = {j - 1, j};
                    }
                }
            }
//            cerr << "b: " << best << ' ' << bests << ' ' << bestI.first << ' '<<bestI.second << endl;
            if (best == -1) {
                EMPTY();
            }
            if (bestI.first < bestI.second) {
                answer.push_back({bestI.first, 'R'});
            } else {
                answer.push_back({bestI.first, 'L'});
                swap(bestI.first, bestI.second);
            }
            for (size_t k = bestI.second; k < v.size(); ++k) {
                v[k - 1] = v[k];
            }
            v.pop_back();
            v[bestI.first] = bests;
            --last;
        }
    }
    cout << "YES" << endl;
    for (auto i : answer) {
        cout << i.first + 1 << ' ' << i.second << endl;
    }
}
