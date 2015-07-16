#include <fstream>

int e, f, w, p, j, B[9999], A[9999];

main() {
    std::fstream I("INPUT.TXT");
    std::ofstream O("OUTPUT.TXT");

    for (
        I >> e >> f >> p,
        f-= e;

        I >> p >> w;

    )
        for (j = w; e = B[j - w] + p, j <= f; ++j)
            if (j == w || e - p)
                B[j] < e && (B[j] = e),
                (e = A[j - w] + p) > A[j] && A[j] || (A[j] = e);
    !f | B[f]
        ? O << A[f] << ' ' << B[f]
        : O << "This is impossible.";
}
