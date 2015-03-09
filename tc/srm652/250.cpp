#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct ThePermutationGame {
    int findMin(int N) {
        long long MOD = 1000000007;
        long long ans = 1;
        vector<int> primes;
        for (int i = 2; i <= N; ++i) {
            bool ok = true;
            for (size_t j = 0; ok && j <  primes.size()&& primes[j] * primes[j] <= i ; ++j)
                if (i % primes[j] == 0)
                    ok = false;
            if (ok)
                primes.push_back(i);
        }
        vector<int> mask(primes.size());
        for (int i = 2; i <= N; ++i) {
            int value = i;
            for (size_t j = 0; j < primes.size() && value != 1; ++j) {
                int count = 0;
                if (value % primes[j] == 0) {
                    while (value % primes[j] == 0) {
                        ++count;
                        value /= primes[j];
                    }
                    mask[j] = max(count, mask[j]);
                    if (value != 1) {
                        auto it = lower_bound(primes.begin(), primes.end(), value);
                        if (it != primes.end() && *it == value) {
                            size_t index = distance(it, primes.end());
                            mask[index] = max(1, mask[index]);
                        }


                    }
                }
            }
        }
        for (size_t i = 0; i < primes.size(); ++i) {
            for (size_t c = 0; c < mask[i]; ++c) {
                ans = (ans * primes[i]) % MOD;
            }
        }
        return ans;
    }
};


int main() {
    ThePermutationGame g;
    cout << g.findMin(2) << endl;
    cout << g.findMin(3) << endl;
    cout << g.findMin(4) << endl;
    cout << g.findMin(5) << endl;
    cout << g.findMin(6) << endl;
    cout << g.findMin(11) << endl;
    cout << g.findMin(102) << endl;
    cout << g.findMin(9999) << endl;
    cout << g.findMin(100000) << endl;


    return 0;
}

