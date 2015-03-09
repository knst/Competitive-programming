#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;


class BigFatInteger {
public:
    int minOperations(int A, int B) {
        map<int, int> m;
        int a = A;
        for (int i = 2; i * i <= A; ++i) {
            while (a % i == 0) {
                ++m[i];
                a /= i;
            }
        }
        if (a != 1)
            ++m[a];
        int maximum = 0;
        for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
            maximum = max(maximum, it->second);
        }
        maximum *= B;
        int result = m.size();
        if (maximum > 1) {
            int cur = 1;
            while (cur < maximum) {
                cur *= 2;
                result++;
            }
        }
        return result;

    }

};


int main() {
    BigFatInteger bi;
    cout << bi.minOperations(6, 1) << ' '  << 2<< endl;
    cout << bi.minOperations(162, 1) << ' '  << 4 << endl;
    cout << bi.minOperations(999983, 9) << ' '  << 5 << endl;
    cout << bi.minOperations(360, 8) << ' '  << 8 << endl;
    cout << bi.minOperations(2, 15) << ' ' << 5 << endl;
    cout << bi.minOperations(2, 16) << ' ' << 5 << endl;
    cout << bi.minOperations(2, 17) << ' ' << 6 << endl;
    cout << bi.minOperations(15, 1) << ' ' << 3 << endl;
    cout << bi.minOperations(16, 1) << ' ' << 3 << endl;
    cout << bi.minOperations(17, 1) << ' ' << 4 << endl;
    return 0;
}

