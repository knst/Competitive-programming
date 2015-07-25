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
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
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

long long relevance(vector<long long>& ai, vector<long long>& fi) {
    long long result = 0;
    for (size_t i = 0; i < ai.size(); ++i) {
        result += fi[i] * ai[i];
    }
    return -result;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    vector<long long> ai(n);
    for (auto& i : ai)
        cin >> i;
    size_t d;
    cin >> d;
    map<size_t, vector<long long>> fi;
    set<pair<long long, size_t>> table;
    for (size_t i = 0; i < d; ++i) {
        vector<long long> f(n);
        for (auto& i : f)
            cin >> i;
        fi[i + 1] = f;
        long long r = relevance(ai, f);
        table.insert({r, i + 1});
    }
    size_t q;
    cin >> q;
    for (size_t i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            size_t k;
            cin >> k;
            for (auto i = table.begin(); k--; ++i) {
                cout << i->second << ' ';
            }
            cout << endl;
        } else {
            size_t d;
            size_t j;
            long long v;
            cin >> d >> j >> v;
            long long r = relevance(ai, fi[d]);
            table.erase({r, d});
            fi[d][j-1] = v;
            r = relevance(ai, fi[d]);
            table.insert({r, d});

        }
    }


    return 0;
}
