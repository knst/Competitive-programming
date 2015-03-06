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

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int mode = 0; // 1 - digit; 0 - char
        bool chars = true;
        int n = s.size();
        for (const auto& i : s) {
            if (i >= '0' && i <= '9')
                mode = 1;
            if (i >= 'A' && i <= 'Z' && mode == 1)
                chars = false;
        }
        if (chars) {
            int row = 0;
            int column = 0;
            for (const auto& i : s) {
                if (i >= 'A' && i <= 'Z') {
                    column = column * 26 + (i - 'A') + 1;
                } else {
                    row = row * 10 + (i - '0');
                }
            }
            cout << 'R' << row << 'C' << column  << endl;
        } else {
            int row = 0;
            int column = 0;
            bool mode = false;
            bool mode2 = false;
            for (const auto& i : s) {
                if (i == 'C')
                    mode = true;
                if (i == 'R' || i == 'C')
                    continue;
                if (mode)
                    column = column * 10 + (i -'0');
                else
                    row = row * 10 + (i - '0');

            }
            string out = "";
            do {
                column--;
                out = static_cast<char>(((column - 0) % 26)  + 'A') + out;
                column /= 26;
            } while (column);
            cout << out << row << endl;

        }
    }

    return 0;
}
