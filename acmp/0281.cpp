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

    unsigned int count = 0;
    for (unsigned int i = 0; i < (1u << n); ++i) {
        unsigned int s = i;
        unsigned int k = 0;
        while (s) {
            s = s & (s - 1);
            ++k;
        }
        if (k >= m)
            ++count;


    }

    output << count << endl;

}

