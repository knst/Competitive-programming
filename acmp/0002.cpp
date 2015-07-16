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

    int n;
    input >> n;

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    for (int i = n; i <= 1; ++i)
        sum += i;
    output << sum << endl;

}

