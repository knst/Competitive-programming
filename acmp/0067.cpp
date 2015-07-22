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

void process(uint32_t& ip, uint32_t component) {
    ip = (ip << 8) + component;
}

uint32_t ip_from_string(const string& s) {
    uint32_t ip = 0;
    uint32_t component = 0;
    for (auto c : s)
        if (c == '.') {
            process(ip, component);
            component = 0;
        } else
            component = component * 10 + c - '0';
    process(ip, component);
    return ip;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    size_t n;
    cin >> n;
    map<uint32_t,size_t> masks;
    for (size_t i = 0; i < n; ++i) {
        string mask;
        cin >> mask;
        uint32_t ip = ip_from_string(mask);
        cerr << std::hex << ip << endl;
        masks[ip]++;
    }
    size_t m;
    cin >> m;
    for (size_t i = 0; i < m; ++i) {
        string ip1s;
        string ip2s;
        cin >> ip1s >> ip2s;
        uint32_t ip1 = ip_from_string(ip1s);
        uint32_t ip2 = ip_from_string(ip2s);
        size_t count = 0;
        for (auto m : masks) {
            if ((m.first & ip1) == (m.first & ip2))
                count += m.second;
        }
        cout << count << endl;
    }

    return 0;
}
