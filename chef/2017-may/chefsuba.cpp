/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int k;
    int p;
    vector<int> v(n);
    for (auto& i : v) {
        string a;
        cin >> a;
        i = a == "1";
    }

    for (int i = 0; i < a
