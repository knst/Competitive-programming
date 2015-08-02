#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct BearPlays
{
    int pileSize(int A, int B, int K) {
        cerr << A <<  ' ' << B << ' ' << K << endl;
        for (int i = 0; i < K; ++i) {
            int a2 = A + A;
            B -= A;
            A = a2;
            if (A > B)
                swap(A, B);
        }
        return A;
    }
};

int main() {
    BearPlays p;
    cout << p.pileSize(7, 1000 * 1000 * 1000, 2000000000) << endl;

}
