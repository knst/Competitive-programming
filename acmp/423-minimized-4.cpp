#include <vector>
#include <fstream>

char c, L, n, j, o;

main() {
    std::ifstream I("INPUT.TXT");
    std::ofstream O("OUTPUT.TXT");
    std::vector<int> P(99), p, S;
    P[0] = 1;
    n = 1;
    while (I >> c) {
        p = S, S = P;
        for (o = j = 0; j < n; ) {
            if (L * 10 + c < 82 && L) {
                o = P[j] += p[j];
                P[j + 1] += o / 10;
            }
            P[j++] %= 10;

        }
        n += P[n];

        L = c - 48;
    }
    while (n--)
        O << P[n];
}
