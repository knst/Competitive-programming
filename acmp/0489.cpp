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

void Log(const vector<int>& left, const vector<int>& right, const string& comment) {
    return;
    cerr << comment << ":" << endl;
    cerr << "L: ";
    for (size_t i = 0; i < left.size(); ++i)
        if (left[i])
            cerr << ' ' << -static_cast<int>(i);
    cerr << "\nR: ";
    for (size_t i = 0; i < right.size(); ++i)
        if (right[i])
            cerr << ' ' << i;
    cerr << endl;
    cerr << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);

#ifdef _KNST
    istream& input = cin;
    ostream& output = cout;
#else
    ifstream input("INPUT.TXT");
    ofstream output("OUTPUT.TXT");
#endif

    size_t n, k;
    input >> n;
    input >> k;

    vector<int> left(1001);
    vector<int> right(1001);
    for (size_t i = 0; i < n; ++i) {
        int value;
        input >> value;
        if (value > 0)
            right[value]++;
        else
            left[-value]++;
    }
    Log(left, right, "INPUT");

    vector<int> end(n-1);
    for (auto& i : end)
        input >> i;


    for (size_t i = 0; i < k; ++i) {
        int value;
        input >> value;
        if (right[value]) {
            right[value]--;
            left[value]++;
        } else {
            right[value]++;
            left[value]--;
        }
    }
    Log(left, right, "SEQUENCE");

    for (auto i : end) {
        if (i > 0) {
            if (right[i])
                right[i]--;
            else {
                right[i]++;
                left[i] -= 2;
            }
        } else {
            if (left[-i])
                left[-i]--;
            else {
                left[-i]++;
                right[-i] -= 2;
            }
        }
        Log(left, right, "Next!");

    }
    Log(left, right, "END");
#if 0
    for (size_t i = 0; i < left.size(); ++i) {
        if (left[i] > right[i]) {
            left[i] -= right[i];
            right[i] = 0;
        } else {
            right[i] -= left[i];
            left[i] = 0;
        }
    }

    Log(left, right, "BALANCE");
#endif
    for (size_t i = 0; i < left.size(); ++i)
        if (left[i])
            output << -static_cast<int>(i) << endl;
    for (size_t i = 0; i < right.size(); ++i)
        if (right[i])
            output << i << endl;


    return 0;
}
