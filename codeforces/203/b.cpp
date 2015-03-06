#include <iostream>
#include <vector>
#include <set>

using namespace std;
vector<int> t;
vector<int> v;
vector<int> m;
vector<int> count;
set<int> used;

void compute(int index) {
    if (used.find(index) != used.end())
        return;
    used.insert(index);
    if (m[index] != -1) {
        return;
    }
    if (v[index] == -1) {
        m[index] = 0;
        return;
    }
    if (
        count[v[index]] > 1 ||
        t[v[index]] == 1)
    {
        m[index] = 0;
        return;
    }
    if (t[v[index]] == 0) {
        if (m[v[index]] == -1) {
            compute(v[index]);
        }
        if (m[v[index]] == -4)
            m[index] = -1;
        else
            m[index] = m[v[index]] + 1;
        return;
    }
}

int main() {
    int n;
    cin >> n;

    v.resize(n);
    t.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        --v[i];
    }

    count.resize(n);
    m.resize(n);
    for (int i = 0; i < n; ++i) {
        m[i] = -1;
        count[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        if (v[i] != -1)
            ++count[v[i]];
    }

    for (int i = 0; i < n; ++i) {
        compute(i);
    }

    int maximum = -1;
    int maxI = -1;
    for (int i = 0; i < n; ++i) {
        if (t[i] == 1 && m[i] > maximum) {
            maximum = m[i];
            maxI = i;
        }
    }
    cout << maximum + 1 << endl;
    vector<int> result;
    result.push_back(maxI);
    if (maximum > 0) {
        int last = maxI;
        for (int i = 1; i <= maximum; ++i) {
            last = v[last];
            result.push_back(last);
        }
    }
    for (size_t i = result.size() - 1; i < result.size(); --i) {
        cout << result[i] + 1 << ' ';
    }
    cout << endl;
}
