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

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int weight(uint32_t x) {
    int result = 0;
    while (x) {
        x = x & (x - 1);
        ++result;
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    uint32_t m = v[0].size();

    map<int,int> M;
    map<uint32_t, vector<vector<string>>> SetMap;
    set<uint32_t> tested;
    set<uint32_t> probs = {0};
    SetMap[0] = {v};
    while (!probs.empty()) {
        set<uint32_t> probs2;
        for (auto i : probs) {
            if (tested.find(i) != tested.end())
                continue;
            tested.insert(i);

            for (uint32_t s = 0; s < m; ++s) {
                uint32_t mask = 1;
                if (s)
                    mask <<= s;
                uint32_t prob = i | mask;
                if (prob == i)
                    continue;
                if (tested.find(prob) != tested.end())
                    continue;
                if (SetMap.find(prob) != SetMap.end())
                    continue;
                probs2.insert(prob);
                vector<vector<string>> sets = SetMap[i];

                for (uint32_t i = 0; !sets.empty() && i < m; ++i) {
                    if (!(prob & (1 << i)))
                        continue;
                    vector<vector<string>> sets2;
                    for (auto V : sets) {
                        for (char c = 'A'; c <= 'z'; ++c) {
                            if (c == '[')
                                c = 'a';
                            vector<string> newVector;
                            for (auto j : V)
                                if (j[i] == c)
                                    newVector.push_back(j);
                            if (newVector.size() > 1)
                                sets2.push_back(newVector);
                        }
                    }
                    sets = sets2;
                }
                SetMap[prob] = sets;
                if (sets.empty())
                    M[weight(prob)]++;
            }
        }
        probs = probs2;
    }
    int sum = 0;
    int total = 0;
    for (auto i : M) {
        sum += i.first;
        total += i.second;
    }
    cout.precision(20);
    cout << fixed << total *1.0L / sum << endl;

    return 0;
}
