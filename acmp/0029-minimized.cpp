#include <fstream>

int n, x, y, i, a, b, c;

using namespace std;

main() {
    fstream I("INPUT.TXT");

    for (
        I >> n >> i, y = i;

        --n;

        a = b,
        b = c,
        c = min(
            b - min(i - y, y - i),
            a - min(i - x, x - i) * 3
        )
    )
        x = y,
        y = i,
        I >> i;

    ofstream("OUTPUT.TXT") << c;
}
