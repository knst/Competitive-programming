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


struct PartisanGame
{
     int getWinner_slow(int n, vector <int> a, vector <int> b) {
         int r = 1;
         for (auto i : a)
             r *= i;
         for (auto j : b)
             r *= j;
         vector<int> v(n + 1);
         v[0] = 1;
         int value = 0;
         vector<int>& A = a;
         vector<int>& B = b;
         for (int i = 1; i <= n; ++i) {
             bool ok = false;
             for (auto j : A) {
                 if (i - j < 0)
                     continue;
                if (value == v[i - j])
                    ok = true;
             }
             swap(A, B);
             if (ok)
                 v[i] = value;
             else
                 v[i] = !value;
             value = !value;
         }
         return v[n];
     }
     string getWinner(int n, vector <int> a, vector <int> b) {
 //        int original = getWinner_slow(n, a, b);
         int r = 1;
         for (auto i : a)
             r *= i;
         for (auto j : b)
             r *= j;
         if (n > r) {
             n = n % r + r;
         }
         vector<int> v(n + 1);
         vector<int> u(n + 1);
         v[0] = 0;
         u[0] = 1;
         vector<int>& A = a;
         vector<int>& B = b;
         for (int i = 1; i <= n; ++i) {
             bool ok = false;
             bool ok2 = false;
             for (auto j : A) {
                 if (i - j < 0)
                     continue;
                if (0 == u[i - j])
                    ok = true;
             }
             for (auto j : B) {
                 if (i - j < 0)
                     continue;
                if (1 == u[i - j])
                    ok2 = true;
             }
             v[i] = ok2;
             u[i] = ok;
         }
 //        for (auto i : v)
  //         cout << i << ' ';
   //    cout << endl;;
  //       if (v[n] != original)
   //              cerr << "wtf" << endl;

         if (v[n] == 0 || u[n] == 0) {
             return "Alice";
         }
         return "Bob";
     }
};

int main() {
 PartisanGame p;
    if (p.getWinner(7, {3, 4}, {4}) == "Alice") cout << "OK" << endl; else cout << "WRONG" << endl;
    if (p.getWinner(10, {1}, {4, 3, 2})  == "Bob") cout << "OK" << endl; else cout << "WRONG" << endl;
    if (p.getWinner(104982, {2, 3, 4, 5}, {2, 5}) == "Alice") cout << "OK" << endl; else cout << "WRONG" << endl;
//    if (p.getWinner(104985, {2, 4, 5}, {2, 5}) == "Alice") cout << "OK" << endl; else cout << "WRONG" << endl;
 //   if (p.getWinner(104984, {2, 3, 5}, {2, 5}) == "Alice") cout << "OK" << endl; else cout << "WRONG" << endl;
  //  if (p.getWinner(104983, {1, 3, 4, 5}, {2, 5}) == "Alice") cout << "OK" << endl; else cout << "WRONG" << endl;
    if (p.getWinner(999999999, {4}, {5}) == "Bob") cout << "OK" << endl; else cout << "WRONG" << endl;
    if (p.getWinner(1000000000, {1,2,3,4,5}, {1,2,3,4,5}) == "Alice") cout << "OK" << endl; else cout << "WRONG" << endl;


}
