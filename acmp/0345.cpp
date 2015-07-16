/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool test(const map<string, vector<string>>& calls, const string& original, const string& name, set<string>& tested) {
    if (tested.find(name) != tested.end())
        return false;
    tested.insert(name);
    auto it = calls.find(name);
    if (it != calls.end())
        for (auto i : it->second) {
            if (i == original)
                return true;
            if (test(calls, original, i, tested))
                return true;
        }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;

    vector<string> names;
    map<string, vector<string>> calls;
    for (size_t i = 0; i < n; ++i) {
        string name;
        cin >> name;
        names.push_back(name);
        size_t k;
        cin >> k;
        for (size_t j = 0; j < k; ++j) {
            string call;
            cin >> call;
            calls[name].push_back(call);
        }
        cin >> name;
    }
    for (size_t i = 0; i < n; ++i) {
        set<string> tested;
        if (test(calls, names[i], names[i], tested))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
