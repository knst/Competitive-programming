#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <cmath>
#include <stack>

using namespace std;


struct AlmostFibonacciKnapsack
{
    vector<int> Calc(const vector<long long>& values, long long x,size_t last) {
        if (x == 0) {
            return {};
        }
        if (x < 2) {
            return {-1};
        }
        for (size_t i = last - 1; i < values.size(); --i) {
            vector<int> res = Calc(values, x - values[i], i);
            if (res.size() == 1 && res[0] == -1)
                continue;
            res.push_back(i + 1);
            return res;
        }
        return {-1};

    }
    vector <int> getIndices(long long x) {
        vector<long long> values = {2, 3};
        long long plast = 2;
        long long last = 3;
        while (last < x) {
            long long next = last + plast - 1;
            values.push_back(next);
            plast = last;
            last = next;
        }
        return Calc(values, x, values.size());
    }
};

int main() {
    AlmostFibonacciKnapsack ak;
    for (long long i = 0; i < 10; ++i) {
//    for (long long  i = 1e18; i < 1e18 + 1000; ++i) {
        vector<int> v = ak.getIndices(i);
        cout << i << ": ";
        for (auto j : v) {
            cout << j << ' ';
        }
        cout << endl;
    }


}
