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
    size_t m;

    input >> n >> m;

    vector<int> s(m);
    input >> s[0];
    for (size_t i = 1; i < m; ++i) {
        int x;
        input >> x;
        s[i] = s[i-1] + x;
    }
    for (size_t j = 1; j < n; ++j) {
        int x;
        input >> x;
        s[0] += x;
        for (size_t i = 1; i < m; ++i) {
            input >> x;
            s[i] = min(s[i - 1], s[i]) + x;
        }
    }
    output << s[m-1] << endl;
}
