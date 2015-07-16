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

void Alien() {
    cout << "Alien" << endl;
    exit(0);
}

void Bear() {
    cout << "Bear" << endl;
    exit(0);
}

void Elephant() {
    cout << "Elephant" << endl;
    exit(0);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    vector<int> v(6);
    map<int,int> m;
    for (auto& i : v) {
        cin >> i;
        m[i]++;
    }
    if (m.size() > 3)
        Alien();

    if (m.size() == 1) {
        Elephant();
    }
    if (m.size() == 3) {
        auto it = m.begin();
        int x = it->first; ++it;
        int y = it->first; ++it;
        int z = it->first; ++it;
        if (m[x] == 4) {
            if (y != z)
                Bear();
            else
                Alien();
        }
        if (m[y] == 4) {
            if (x != z)
                Bear();
            Alien();
        }
        if (m[z] == 4) {
            if (x != y)
                Bear();
            Alien();
        }
        Alien();
    }
    auto it = m.begin();
    int x = it->first; ++it;
    int y = it->first; ++it;
    if (m[x] == 1)
        Bear();
    if (m[y] == 1)
        Bear();
    if (m[x] == 2 || m[y] == 2)
        Elephant();
    Alien();




    return 0;
}

