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
    vector<double> r(n + 1);
    vector<double> d(n + 1);
    vector<double> e(n + 1);

    r[0] = 100.0;
    for (size_t i = 0; i < n; ++i) {
        double D;
        double E;
        input >> D >> E;
        r[i + 1] = max(r[i], max(d[i] * D, e[i] * E));
        d[i + 1] = max(d[i], max(r[i] / D, e[i] * E / D));
        e[i + 1] = max(e[i], max(r[i] / E, d[i] * D / E));
    }
    output.precision(2);
    output << fixed << r[n] << endl;
}
