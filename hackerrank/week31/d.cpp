#include <algorithm>
#include <iostream>
#include <vector>

struct Edge
{
    int i;
    int j;
    int a;
    int b;
    bool operator<(const Edge& p) {
        return a * p.b > b * p.a;
    }
    Edge operator+(const Edge & p) {
        return {0, 0, a + p.a, b + p.b};
    }
};

// Data structure Disjoint Set Union
class DSU {
    std::vector<size_t> sets;
public:
    DSU(size_t n)
    {
        for (size_t i = 0; i < n; ++i) {
            sets.push_back(i);
        }
    }
    size_t getSet(size_t index) const {
        if (sets[index] == index) return index;
        return getSet(sets[index]);
    }

    void setSet(size_t index, size_t newSet) {
        if (sets[index] == index) {
            sets[index] = newSet;
            return;
        }
        setSet(sets[index], newSet);
        sets[index] = newSet;
    }
};

std::vector<Edge> mstKruskal(size_t n, std::vector<Edge>& edges) {
    using namespace std;
    DSU dsu(n);
    sort(edges.begin(), edges.end());

    vector<Edge> mst;
    for (const Edge& e : edges) {
        size_t ui = dsu.getSet(e.i);
        size_t uj = dsu.getSet(e.j);
        if (ui == uj) continue;
        mst.push_back(e);
        dsu.setSet(e.j, ui);
    }
    return mst;
}

template<class T> T gcd(T A, T B) { return B == 0 ? A : gcd(B, A % B); }
int main() {
    using namespace std;
    size_t n;
    size_t m;
    cin >> n >> m;
    vector<Edge> edges;
    for (size_t i = 0; i < m; ++i) {
        int x;
        int y;
        int a;
        int b;
        cin >> x >> y >> a >> b;
        edges.push_back({x, y, a, b});
    }
    vector<Edge> mst = mstKruskal(n, edges);
    Edge sum{0, 0, 0, 0};
    for (auto i : mst) {
        sum = sum + i;
        cout << i.a << ' ' << i.b << endl;
        cout << "s: " << sum.a << ' ' << sum.b << endl;;
    }
    int g = gcd(sum.a, sum.b);
    cout << sum.a / g << '/' << sum.b /g << endl;

}
