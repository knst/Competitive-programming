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

string getPos(int i, int n) {
    if (i < n) {
        return "#.";
    } else return "O.";
}
string line(int index, int n) {
    string result = "";
    for (int i = 29 - index; i>= 0; i -= 3) {
        result += getPos(i, n);
    }
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    n = 34 - n;
    cout << "+------------------------+" << endl;
    cout << "|" << getPos(33, n) << line(0, n) << "|D|)" << endl;
    cout << "|" << getPos(32, n) << line(1, n) << "|.|" << endl;
    cout << "|" << getPos(31, n) << "......................|" << endl;
    cout << "|" << getPos(30, n) << line(2, n) << "|.|)" << endl;
    cout << "+------------------------+" << endl;

    return 0;
}

