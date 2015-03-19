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


struct GameOfStones {
    int count(vector<int> stones) {
        int sum = 0;
        for (auto i : stones) {
            sum += i;
        }
        int count = stones.size();
        int target = sum / count;
        cerr << sum << ' ' << count << ' ' << target << endl;
        if (sum % count)
            return -1;
        int result = 0;
        for (auto i : stones) {
            if ((i - target) % 2)
                return -1;
            int delta = (i - target) / 2;
            if (delta < 0)
                delta = -delta;
            result += delta;
        }
        return result / 2;
    }
};

int main() {
    GameOfStones g;
    cout << g.count(
            {7, 15, 9, 5}) << endl;
    cout << g.count({10, 16}) << endl;
    cout << g.count({17}) << endl;
    cout << g.count({10, 15, 20 , 12, 1, 20}) << endl;
    cout << g.count({7, 15, 9, 5, 41, 9, 9, 9}) << endl;

}

