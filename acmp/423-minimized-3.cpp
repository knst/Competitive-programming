// knst
#include <fstream>

char c, L, n, j, o, p[99], S[99], P[99] = {1};

main() {
    std::fstream I("INPUT.TXT");
    std::ofstream O("OUTPUT.TXT");

    for(
            ;
            I >> c;
            L = c - 48
    )
        for (
            j = 0;
            j <= n;
            n += P[n]
        )
            p[j] = S[j],
            o = (S[j] = P[j]) + o / 10 + (L * 10 + c < 82 && L) * p[j],
            P[j++] = o % 10;

    while(n--)
        O << +P[n];
}
