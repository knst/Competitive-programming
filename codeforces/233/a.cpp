#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

int main() {
    long long a_;
    long long b_;

    cin >> a_ >> b_;
    if (true) {
    }
//    for (int A = 0; A <= a_; ++A) {
//        for (int B = 0; B <= b_; ++B) {
        long long a = a_;
        long long b = b_;
        long long res1 = 0;
        long long res2 = 0;
    if (false) {
        vector<int> v;
        for (int i = 0; i < a; ++i)
            v.push_back(0);
        for (int j = 0; j < b; ++j)
            v.push_back(1);
        int maximum = -a * a - b * b;
        do {
 //           cout << "p: ";
//            for (int i = 0; i < v.size(); ++i){
   //             cout << v[i] << ' ';
  //          }
            int index = 0;
            int combo_index = 1;
            int result = 0;
            int n = v.size();
            while (index < n) {
                ++index;
                combo_index = 1;
                while (index < n && v[index] == v[index-1]) {
                    ++combo_index;
                    index++;
                }
                if (v[index-1] == 1)
                    result -= combo_index * combo_index;
                else
                    result +=combo_index *combo_index;
            }

    //        cout << result << ' ' << endl;
            maximum = max(result, maximum);


        } while (next_permutation(v.begin(), v.end()));
//        cout << maximum << endl;
        res1 = maximum;
    }

        long long maximum = a * a - b * b - 7;
        long long best_groups;
        if (b <= 1) {
            maximum = a * a - b;
        } if (a == 0) {
            maximum = - b * b;
        } else 
        for (long long groups = 1; groups <= min(b, a + 1); ++groups) {
            long long result = 0;
            result -= (b / groups) * (b/ groups) * (groups - b %groups);
            result -= (b / groups + 1) * (b / groups + 1) * (b % groups);
            result += min(a, groups - 2);
            result += min(a, a - groups + 2) * min (a, a - groups + 2);
            if (result > maximum)  {
                maximum = max(maximum, result);
                best_groups = groups;
            }
        }
        res2 = maximum;
        cout << maximum << endl;
        if (b <= 1 || a == 0) {
            for (int i = 0; i < b; ++i)
                cout << "x";
            for (int i = 0; i < a; ++i)
                cout << "o";
        } else {
            for (int i = 0; i < best_groups; ++i) {
                if (i < b % best_groups)
                    cout << "x";
                for (int j= 0; j < b / best_groups; ++j)
                    cout << "x";
                if (i < best_groups - 1) {
                    if (i == best_groups - 2) 
                        for (int j = 0; j < a-best_groups + 1; ++j)
                            cout << "o";
                    cout << "o";
                }
            }
        }
        cout << endl;
//    cout << a << '\t' << b << '\t' << res1 << '\t' << res2 << '\t';
//    if (res1 == res2) {
 //       cout << '+';
  //  } else {
   //     cout << "-1111!!!!!!";
    //}
 //   cout << endl;
//        }
 //   }
    return 0;
}
