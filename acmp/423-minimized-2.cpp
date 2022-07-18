#include <vector>
#include <fstream>

#define M(x, W) \
    char c, L, n, j; \
    main() { \
        x ifstream I("INPUT.TXT" ); \
        x ofstream O("OUTPUT.TXT" ); \
        x vector<int> P(99), p, S; \
        P[0] = 1; \
        W (I >> c) { \
             p = S, S = P, j = 0; \
           W ( \
                n += P[n], L * 10 + c < 82 && L && j < n \
            ) \
                P[j + 1] += (P[j] += p[j]) / 10, \
                P[j++] %= 10 \
            ; \
            L = c - 48; \
        } \
        W (n--) \
            O << P[n]; \
    }
M(std::, while )
