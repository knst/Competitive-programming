#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

using Eat = tuple<int, int, int>;

Eat In() {
    int a;
    int b;
    int c;
    cin >> a >> b >> c;
    return tie(a, b, c);
}

Eat operator+(const Eat& a, const Eat& b) {
    Eat result(get<0>(a) + get<0>(b), get<1>(a) + get<1>(b), get<2>(a) + get<2>(b));
    return result;
}
void solve() {
    tuple<int, int, int> target = In();
    int n;
    cin >> n;
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; ++i)  {
        v.push_back(In());
    }

    for (uint32_t mask = 0; mask < (1u << n); ++mask) {
        tuple<int, int, int> sum(0, 0, 0);
        for (int i = 0; i < n; ++i) {
            if (mask & (1u << i))
                sum = sum + v[i];
        }
        if (sum == target) {
            cout << "yes" << endl;
            return;
        }
    }
    cout << "no" << endl;
    return;

}
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
