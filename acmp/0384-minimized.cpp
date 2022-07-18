// knst

#import <iostream>

int B = 1, p, n, m, M = 1e9;

main() {
    for (std::cin >> n >> p; m = p; n = m)
        p = n % m;

    for (; --n; B = p % M)
        p = m + B,
        m = B;

    std::cout << B;
}
