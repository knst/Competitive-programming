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


struct SortishDiv2 {
    int ways(int sorted, vector<int> seq) {
        vector<int> indexes;
        set<int> values;
        int n  =seq.size();
        for (int i = 1; i <= n; ++i)
            values.insert(i);
        for (int i = 0; i < n; ++i)
            if (seq[i] == 0)
                indexes.push_back(i);
            else
                values.erase(seq[i]);

        vector<int> newVal;
        for (auto i : values)
            newVal.push_back(i);

        int result = 0;
        do {
            for (int i = 0; i < indexes.size(); ++i)
                seq[indexes[i]] = newVal[i];

            int count = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = i+1; j < n; ++j) {
                    if (seq[i] < seq[j])
                        ++count;

                }
            }
            if (count == sorted)
                ++result;

        } while (next_permutation(indexes.begin(), indexes.end()));
        return result;

    }
};

int main() {
    SortishDiv2 s;
    cout << s.ways(5, {4, 0, 0, 2, 0}) << endl;
    cout << s.ways(4, {0, 0, 0, 0}) << endl;
    cout << s.ways(2, {1, 3, 2}) << endl;
    cout << s.ways(2, {1, 2, 0, 5, 0, 0}) << endl;


}
