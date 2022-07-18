// knst

#include <vector>
#include <fstream>
#include <string>

char c, L, i, n=1, j;

main() {
    std::ifstream I("INPUT.TXT");
    std::ofstream O("OUTPUT.TXT");
    std::vector<int> S(99), p, P;
    S[0] = 1;
    P = p = S;
    while (I >> c) {
        if (L * 10 + (c -= 48) < 34 && L)
            for (j = 0; j < n; ++j)
                P[j + 1] += (P[j] += p[j]) / 10,
                P[j] %= 10;

        n += P[n];
        p = S;
        S = P;
        L = c;
    }
    while (n--)
        O << S[n];
}
