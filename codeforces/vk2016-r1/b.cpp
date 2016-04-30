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

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    size_t n, k, q;
    cin >> n >> k >> q;
    vector<uint32_t> t(n);
    for (auto& i : t) {
        cin >> i;
    }
    set<size_t> indexes;
    set<pair<uint32_t, size_t>> s;
    for (size_t i = 0; i < q; ++i) {
        int type;
        cin >> type;
        size_t id;
        cin >> id;
        --id;
        if (type == 1) {
            s.insert({t[id], id});
            indexes.insert(id);
            if (s.size() > k) {
                auto value = s.begin();
                indexes.erase(value->second);
                s.erase(value);
            }
        } else {
            if (indexes.find(id) == indexes.end()) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }


    return 0;
}
