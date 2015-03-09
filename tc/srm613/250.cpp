#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct TaroFriends {
    int getNumber(vector<int> coor, int X) {
        vector<int> poss;
        for (auto i : coor) {
            poss.push_back(i - X);
            poss.push_back(i + X);
        }
        int minimal = 1000*1000*1000;
        for (auto i : poss) {
            for (auto j : poss) {
                if (i > j)
                    continue;
                bool ok = true;
                for (auto k : coor) {
                    if (! (
                            (k - X >= i && k - X <= j) ||
                            (k + X >= i && k + X <= j)
                          ))

                        ok = false;
                }
                if (ok) {
//                    cout << "+" << i << ' ' << j << endl;
                    minimal = min(minimal, j - i);
                }
//                else
 //                   cout << "-" << i << ' ' << j << endl;
            }
        }
        return minimal;
    }
};


int main() {
    TaroFriends tf;
    cout << tf.getNumber({-3, 0, 1}, 3) << endl;
    cout << tf.getNumber({4, 7, -7}, 5) << endl;
    cout << tf.getNumber({-100000000, 100000000}, 100000000) << endl;
    cout << tf.getNumber({3, 7, 4, 6, -10, 7, 10, 9, -5}, 7) << endl;
    cout << tf.getNumber({-4, 0, 4, 0}, 4) << endl;
    cout << tf.getNumber({7}, 0) << endl;
    return 0;
}

