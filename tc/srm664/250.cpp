#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int64_t powmod(int64_t a, int64_t pow, int64_t mod) {
    if (pow == 0)
        return 1;
    if (pow == 1)
        return a % mod;
    int64_t result = 1;
    while (pow) {
        if (pow % 2 != 0) {
            result = result * a % mod;
            pow--;
        }
        a = a * a % mod;
        pow /= 2;
    }
    return result;
}
struct BearPlays
{
    int pileSize(int A, int B, int K) {
        int64_t mod = A + B;
        int64_t a = A;

        int64_t ak = (a * powmod(2, K, mod)) % mod;
        int64_t bk = mod - ak;
        return min(ak, bk % mod);
    }
};

int main() {
    BearPlays p;
    cout << p.pileSize(4, 7, 2) << endl;

}
