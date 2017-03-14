#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int t;
    cin >> n >> t;
    int result = 0;
    int sum = n;
    for(int c_i = 0; c_i < t; c_i++){
        if (sum < 5) {
            result += n - sum;
            sum = n;
        }
        int c;
       cin >> c;
        sum -= c;
    }
    cout << result << endl;
    return 0;
}

