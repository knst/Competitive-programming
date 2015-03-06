#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

long long cycleLength;
long long reward = 1;
long long an;
int main() {
    long long a, b, w, x, c;
    cin >> a >> b >> w >> x >> c;
//    long long oa = a, ob = b, ow = w, ox = x, oc = c;
 //   while (c > a) {

    typedef struct nodeType { long long a; long long c; long long time; } node;
    node v[1010];
    for (long long i = 0; i < 1010; i++) {
        v[i].time = -1;
    }
    an = 0;
    while (an < 1000100 && c > a) {
        if (v[b].time == -1) {
            v[b].time = an;
            v[b].a = a;
            v[b].c = c;
        } else {
            cycleLength = an - v[b].time;
            reward = (v[b].c - v[b].a) - c + a;
        }
        if (b >= x)
            b = b -x;
        else {
            a--;
            b = w - x + b;
        }
        --c;
        an++;
    }
    if (a >= c) {
        cout << an << endl;
        return 0;
    }
    long long temp = max((c - a) / reward - 1, 0LL);
    an += temp * cycleLength;
    c -= temp * cycleLength;
    a -= temp * (cycleLength - reward);
    while (c > a) {
        if (b >= x) {
            b -= x;
        } else {
            --a;
            b = w - x + b;
        }
        --c;
        an++;
    }
    cout << an <<endl;




    return 0;
}
