// knst
#import <iostream>

int64_t n, p, i = 2, c = 1;

main() {
    for (std::cin >> n; n - 1 + p ; p++ )
        n % i ? ++i,
            c *= p ?: 1,
            p = -1
        :
            n /= i
        ;

    std::cout << c;
}
