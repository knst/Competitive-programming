// knst
#import <iostream>

int n, m, v[999999], i, d;

main() {
    std::cin >> n >> m;
    for (
        v[1] = 1 % m;
        ++i < n;

    )
        d = v[i] += (d + i % 2  * v[i / 2]) % m;
    std::cout << d;
}
