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

}
