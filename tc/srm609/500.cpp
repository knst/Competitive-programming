#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

struct PackingBallsDiv1 {
    int minPacks(int k, int a, int b, int c, int d) {
        vector<int> x(k);
        x[0] = a;
        int maximal = 0;
        cout << x[0];
        for (int i = 1; i < k; ++i) {
            x[i] = (x[i-1] * b + c) % d + 1;
            maximal = max(x[i], maximal);
            cout << ' ' << x[i];
        }
        cout << endl;

        return maximal;
    }
};

int main() {
    PackingBallsDiv1 m;
    cout << m.minPacks(23, 10988, 5573, 4384, 100007) << endl;


}
