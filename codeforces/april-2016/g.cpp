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

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    size_t f;
    size_t m;
    size_t t;
    cin >> f >> m >> t;
    vector<string> v(f);
    for (size_t i = 0; i < f; ++i) {
        cin >> v[i];
    }

    size_t result = 0;
    for (size_t i = 0; i < m; ++i) {
        size_t c = 0;
        for (size_t j = 0; j < f; ++j) {
            if (v[j][i] == 'Y')
                ++c;
        }
        if (c >= t) {
            ++result;
        }
    }
    cout << result << endl;



    return 0;
}
