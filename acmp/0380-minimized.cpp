// knst
#import <bits/stdc++.h>

using namespace std;

int n, p[200], q[200], r, k, i, j, s, e, S, E, o,
    v[100][4];

main() {
    cin >> n;

    for (auto& i : v) {
        cin >> s >> e >> S >> E;
        if (s > S)
            swap(s, S);
        if (e > E)
            swap(e, E);
        *i = p[j] = s;
        i[1] = q[j++] = e;
        i[2] = p[j] = S;
        i[3] = q[j++] = E;
    }
    sort(p, p + 200);
    sort(q, q + 200);

    e = *p;
    for (auto i : p) {
        s = e;
        e = i;
        E = *q;
        for (auto k : q) {
            S = E;
            E = k;
            o = 1;
            for (auto l : v)
                o *= *l > s || l[2] < e || l[1] > S || l[3] < E;
            r += !o * (e - s) * (E - S);
        }
    }
    cout << r;
}
