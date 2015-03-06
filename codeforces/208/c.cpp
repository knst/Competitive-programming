#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n) {
        int next;
        vector<int> v;
        do {
            cin >> next;
            --n;
            v.push_back(next);
        } while (next != 0 && n != 0);
        bool Flag = false;
        if (v[v.size() - 1] == 0) {
            v.pop_back();
            Flag = true;
        }
        vector<int> R = v;
        sort(R.begin(), R.end());
        vector<int> p;
        for (int i = 0; i < 3; ++i) {
            if (!R.empty()) {
                p.push_back(R[R.size() - 1]);
                R.pop_back();
            }
        }

        int countMaximal = 0;
        for (int i = 0; i < v.size(); ++i) {
            bool flag2 = false;
            for (int j = 0; j < p.size(); ++j) {
                if (v[i] == p[j]) {
                    flag2 = true;
                    p[j] = -1;
                    ++countMaximal;
                    switch(countMaximal) {
                        case 1:
                            cout << "pushStack" << endl;
                            break;
                        case 2:
                            cout << "pushQueue" << endl;
                            break;
                        case 3:
                            cout << "pushFront" << endl;
                            break;
                    }
                    break;
                }
            }
            if (!flag2) {
                cout << "pushBack" << endl;
            }
        }
        if (Flag) {
            cout << countMaximal;
            switch (countMaximal) {
                case 3:
                    cout << " popFront";
                case 2:
                    cout << " popQueue";
                case 1:
                    cout << " popStack";
            }
            cout << endl;
        }
    }



    return 0;
}
