#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


struct TypoCoderDiv1{
    int getmax(vector <int> D, int X) {
        map<int, int> a;
        map<int, int> b;
        a[X] = 0;
        for (const auto& d : D) {
            map<int, int> a1;
            map<int, int> b1;
            for (const auto& i : a) {
//                a1[i.first] = max(a1[i.first], i.second);
                int d1 = i.first + d;
                if (d1 >= 2200) {
                    b1[d1] = max(b1[d1], i.second + 1);
                } else {
                    a1[d1] = max(a1[d1], i.second);
                }
                int d2 = max(0, i.first - d);
                a1[d2] = max(a1[d2], i.second);
            }
            for (const auto& i : b) {
                int d1 = max(0, i.first - d);
                if (d1 < 2200) {
                    a1[d1] = max(a1[d1], i.second + 1);
                }
            }
            a = a1;
            b = b1;
            for (auto i : a)
                cout << "a: " << i.first << ' ' << i.second << endl;
            for (auto i : b)
                cout << "b: " << i.first << ' ' << i.second << endl;
            cout << endl;
        }
        int maximum = 0;
        for (auto i : a)
            maximum = max(i.second, maximum);
        for (auto i : b)
            maximum = max(i.second, maximum);
        return maximum;
    }
};

int main() {
//    vector<int> D = {100, 200, 100, 1, 1};
    vector<int> D = {2048,1024,5012,256,128,64,32,16,8,4,2,1,0};
    TypoCoderDiv1 t;
//    cerr << t.getmax(D, 2000) << endl;
    cerr << t.getmax(D, 2199) << endl;



}
