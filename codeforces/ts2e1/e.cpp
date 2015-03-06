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

    set<int> blocksTr;
    map<int,set<int>> xs;
    set<int> xLocked;
    map<int,int> sharedCount;
    char c;
    while ((cin >> c), c != '#') {
        int tr;
        int res;
        cin >> tr >> res;

//        cerr << c << '\t' << tr % 1000 << '\t' << res % 1000 << "\t:\t";

        if (blocksTr.find(tr) != blocksTr.end()) {
            cout << "IGNORED" << endl;
            continue;
        }

        if (xLocked.find(res) != xLocked.end()) {
            if (xs[res].size() == 1 && *(xs[res].begin()) == tr)
                cout << "GRANTED" << endl;
            else {
                cout << "DENIED" << endl;
                blocksTr.insert(tr);
            }
        } else {
            if (c == 'X') {
                if (xs[res].size() > 1 || (xs[res].size() == 1 && *(xs[res].begin()) != tr)) {
                    cout << "DENIED" << endl;
                    blocksTr.insert(tr);
                } else {
                    cout << "GRANTED" << endl;
                    xs[res].insert(tr);
                    xLocked.insert(res);
                }
            } else {
                cout << "GRANTED" << endl;
                xs[res].insert(tr);
            }

        }

    }


    return 0;
}
