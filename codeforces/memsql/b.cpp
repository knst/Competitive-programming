#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    if (N == 0) {
        cout << 1;
        return 0;
    }
    if (N == 1) {
        cout << 2;
        return 0;
    }

    int Nc = 0;
    long long t = N;
    while (t % 2 == 0) {
        Nc++;
        t /= 2;
    }

    set<long long> delims;
    int sq = sqrt(t);
    for (int k = 1; k < 30; k+=2) {
        if (t % k == 0) {
            delims.insert(k);
            delims.insert(t / k);
        }
    }
    for (int K = 0; K <= sq + 1; K += 30) {
        int k;
        k = K + 1;
        if (t % k == 0) {
            delims.insert(k);
            delims.insert(t / k);
        }
        k = K + 7;
        if (t % k == 0) {
            delims.insert(k);
            delims.insert(t / k);
        }
        k = K + 11;
        if (t % k == 0) {
            delims.insert(k);
            delims.insert(t / k);
        }
        k = K + 13;
        if (t % k == 0) {
            delims.insert(k);
            delims.insert(t / k);
        }
        k = K + 17;
        if (t % k == 0) {
            delims.insert(k);
            delims.insert(t / k);
        }
        k = K + 19;
        if (t % k == 0) {
            delims.insert(k);
            delims.insert(t / k);
        }
        k = K + 23;
        if (t % k == 0) {
            delims.insert(k);
            delims.insert(t / k);
        }
        k = K + 29;
        if (t % k == 0) {
            delims.insert(k);
            delims.insert(t / k);
        }
    }
    set<long long> ks;
    for (set<long long>::iterator i = delims.begin(); i != delims.end(); ++i) {
        long long k = *i;
        long long s2 = N / k - (k - 3) / 2;
        if (s2 != 0 && (s2 & (s2 -1)) == 0)
            ks.insert(s2 * k);
    }
    if (ks.size() == 0)
        cout << "-1";
    for (set<long long>::iterator i = ks.begin(); i != ks.end(); ++i)
        cout << *i << endl;

    return 0;
}

