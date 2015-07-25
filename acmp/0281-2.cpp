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

    unsigned int n;
    unsigned int m;
    input >> n >> m;

    vector<int> v(n + 1);
    v[0] = 1;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = n; j > 0; --j) {
            v[j] = v[j] + v[j-1];
        }
    }
    int count = 0;
    for (size_t i = m; i <= n; ++i)
        count += v[i];
    output << count << endl;

}

