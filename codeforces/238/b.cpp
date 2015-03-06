#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    int s = 1000 * 1000;
    int n;
    cin >> n;

    vector<int> v(s+1);
    for (auto& i : v)
        i = 0;

    set<int> ns;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        ns.insert(value);
        v[value] = true;
    }

    vector<int> result;
    int count = 0;
    for (auto& i : ns) {
        if (ns.find(s - i + 1) == ns.end()) {
            result.push_back(s - i + 1);
            v[s-i + 1] = true;
        } else {
            ++count;
        }
    }
    int index = 1;
    while (count) {
        if (!v[index]) {
            result.push_back(index);
            result.push_back(s - index+1);
            count -= 2;
        }
        ++index;
    }
    cout << result.size() << endl;
    for (auto& i : result)
        cout << i << ' ';

    return 0;
}
