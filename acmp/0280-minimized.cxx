// knst
#include "stdafx.h"

__int64 n, p, i = 2, c = 1;

int main() {
    for (_STD cin >> n; n + p++ -1; )
        n % i ? ++i,
            (--p && c *= p),
            p = 0
        :
            n /= i
        ;

    std::cout << c;
}
