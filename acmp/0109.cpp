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

const long double const_pi = std::atan(static_cast<long double>(1))*4;

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

#ifdef _KNST
    istream& input = cin;
    ostream& output = cout;
#else
    ifstream input("INPUT.txt");
    ofstream output("OUTPUT.txt");
#endif

    string s;
    input >> s;
    bool first = true;
    int a = 0;
    int b = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '/')
            first = false;
        else {
            if (first)
                a = a * 10 + s[i] - '0';
            else
                b = b * 10 + s[i] - '0';
        }
    }

    output << a / b;
    a = a % b;
    if (a != 0) {
        output << ".";
        map<int, int> remaindersPos;
        string part;
        int count = 0;
        do {
            ++count;
            remaindersPos[a] = count;
            a *= 10;
            part += static_cast<char>(a / b + '0');
            a %= b;
        } while (a && remaindersPos[a] == 0);
        if (a == 0) {
            output << part;
        } else {
            output << part.substr(0, remaindersPos[a] - 1);
            output << "(" << part.substr(remaindersPos[a] - 1, part.size() - remaindersPos[a] + 1) << ")";
        }
    }
    output << endl;
    return 0;
}
