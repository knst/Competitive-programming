#import <iostream>

int64_t n, p, i = 2, c = 1, KNST;

main() {
    for (std::cin >> n; n + p++ -1; )
        n % i ? ++i,
            c *= p - 1 ?: 1,
            p = 0
        :
            n /= i
        ;

    std::cout << c;
}
