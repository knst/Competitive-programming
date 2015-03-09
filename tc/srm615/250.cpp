#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct AmebaDiv1 {
    int count(vector<int> x) {
        set<int> s;
        set<int> ends;
        for (int i = 0; i < x.size(); ++i) {
            ends.insert(x[i]);
            int size = x[i];
            for (int j = 0; j < x.size(); ++j) {
                if (size == x[j]) {
                    size *= 2;
                }
            }
            s.insert(size);
        }
        int count = ends.size();
        for (auto i : ends) {
            if (s.find(i) != s.end())
                --count;
        }
        return count;
    }
};


int main() {
    AmebaDiv1 a;
    cout << a.count({3,2,1}) << endl;
    cout << a.count({2,2,2,2,2,2,4,2,2,2}) << endl;
    cout << a.count({1,2,4,8,16,32,64,128,256,1024,2048}) << endl;
    cout << a.count({1,4,2,8,5,16}) << endl;



    return 0;
}

