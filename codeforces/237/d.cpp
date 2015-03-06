#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    long long a000 = 0;
    long long a001 = 0;
    long long a010 = 0;
    long long a011 = 0;
    long long a100 = 1;
    long long a101 = 1;
    long long a110 = 0;
    long long a111 = 0;
    long long MOD = 1000 * 1000 * 1000 + 7;
    for (int i = 0; i < n; ++i) {
        long long a000_ = 0;
        long long a001_ = 0;
        long long a010_ = 0;
        long long a011_ = 0;
        long long a100_ = 0;
        long long a101_ = 0;
        long long a110_ = 0;
        long long a111_ = 0;
        switch(s[i]) {
        case '?': {
            a000_ = a100 + a000;
            a001_ = a100 + a000;
            a010_ = a101 + a001;
            a011_ = a101 + a001;
            a100_ = a010 + a110;
            a101_ = a010 + a110;
            a110_ = a011 + a111;
            a111_ = a011 + a111;
            break;
          }
        case '*': {
            a000_ = 0;
            a001_ = 0;
            a010_ = a101 + a001;
            a011_ = a101 + a001;
            a100_ = 0;
            a101_ = 0;
            a110_ = a011 + a111;
            a111_ = a011 + a111;
            break;
          }
        case '0': {
            a000_ = a100 + a000;
            a001_ = 0;
            a010_ = 0;
            a011_ = 0;
            a100_ = 0;
            a101_ = 0;
            a110_ = 0;
            a111_ = 0;
            break;
          }
        case '1': {
            a000_ = 0;
            a001_ = a100 + a000;
            a010_ = 0;
            a011_ = 0;
            a100_ = a010 + a110;
            a101_ = 0;
            a110_ = 0;
            a111_ = 0;
            break;
          }
        case '2': {
            a000_ = 0;
            a001_ = 0;
            a010_ = 0;
            a011_ = 0;
            a100_ = 0;
            a101_ = a010 + a110;
            a110_ = 0;
            a111_ = 0;
            break;
          }

        }
        a000 = a000_ % MOD;
        a001 = a001_ % MOD;
        a010 = a010_ % MOD;
        a011 = a011_ % MOD;
        a100 = a100_ % MOD;
        a101 = a101_ % MOD;
        a110 = a110_ % MOD;
        a111 = a111_ % MOD;

    }
    cout << (a000 + a010 + a100 + a110) % MOD << endl;

}
