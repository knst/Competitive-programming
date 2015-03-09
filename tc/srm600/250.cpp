#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;


struct ORSolitaire {
    int getMinimum(vector<int> numbers, int goal) {
        vector<int> n2;
        for (int i = 0; i < numbers.size(); ++i) {
            if ((numbers[i] | goal) == goal) {
                n2.push_back(numbers[i]);
            }
        }
        if (n2.empty()) {
            return 0;
        }
        int minimum = n2.size();
        for (int mask = 1; mask <= goal; mask <<= 1) {
            int count = 0;
            if (goal & mask) {
                for (int i = 0; i < n2.size(); ++i) {
                    if (n2[i] & mask)
                        count++;
                }
                minimum = min(count, minimum);
            }
        }
        return minimum;
    }

};


int main() {
    ORSolitaire ors;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(7);
    v.push_back(8);
    cout << ors.getMinimum(v, 7) << endl;
    cout << ors.getMinimum(v, 1) << endl;
    cout << ors.getMinimum(v, 2) << endl;
    cout << ors.getMinimum(v, 3) << endl;
    cout << ors.getMinimum(v, 8) << endl;



    return 0;
}

