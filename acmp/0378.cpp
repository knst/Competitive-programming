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

    vector<bool> mask(n * 100 + 1);
    mask[0] = 1;
    for (size_t i = 0; i < n; ++i) {
        size_t value;
        input >> value;
        if (!value)
            continue;
        for (size_t j = mask.size(); j >= value; --j) {
            if (mask[j - value])
                mask[j] = true;
        }
    }

    size_t count = 0;
    for (size_t i = 0; i < mask.size(); ++i)
        if (mask[i])
            ++count;

    output << count << endl;

}

