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


struct RunningAroundPark{
    int numberOfLap(int N, vector<int> d) {
        int count = 1;
        for (size_t i = 1; i < d.size(); ++i) {
            if (d[i] <= d[i-1])
                ++count;
        }
        return count;
    }
};

int main() {
    int count = 0;
    for (int i = 0; i < 75; ++i)
        for (int j = i  +1; j < 75; ++j)
            for (int k = j + 1; k < 75; ++k)
                count++;
    cout << count << endl;

}
