#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
#ifdef _KNST
    istream& input = cin;
    ostream& output = cout;
#else
    ifstream input("INPUT.TXT");
    ofstream output("OUTPUT.TXT");
#endif

    size_t n;
    input >> n;
    vector<int> v(n);
    for (size_t i = 0; i < n; ++i)
        input >> v[i];
    int k;
    input >> k;

    vector<int> dyn(k + 1, k + 1);
    dyn[0] = 0;
    for (size_t i = 1; i < dyn.size(); ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i - v[j] < dyn.size())
                dyn[i] = min(dyn[i], dyn[i - v[j]] + 1);
        }
    }
    if (dyn[k] == k + 1)
        output << -1 << endl;
    else
        output << dyn[k] << endl;


}

