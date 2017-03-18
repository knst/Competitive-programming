/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/
#include <bits/stdc++.h>

using namespace std;

struct Solver {
    Solver(
            const vector<vector<int>>& _v,
            const vector<int>& _v_count,
            const vector<int>& _nodes)
    : v(_v)
    , v_count(_v_count)
    , nodes(_nodes)
    , m(nodes.size())
    , best(0.0)
    , nodes_max{0}
    {}

    const vector<vector<int>> v;
    const vector<int> v_count;
    const vector<int> nodes;
    const int m;
    vector<int> subset;

    float best;
    vector<int> nodes_max;
vector<int> getResult() {return nodes_max;}

void test(int triangles, int start, int subCount) {
    if (start == m) return;

    static uint64_t iter = 0;
    iter += subCount;
    if (++iter > 200'000'000ll) return;
    int temp_triangles = triangles;
    int temp_vertex = subCount;
    bool to_check = false;
    for (int i = start; i < m; ++i) {
        int max_vertex = min<int>(v_count[i], temp_vertex + (m - i - 1));
        temp_triangles += (max_vertex - 1) * max_vertex;
        ++temp_vertex;
        if (temp_triangles > temp_vertex * best) {
            to_check = true;
            break;
        }
    }
    if (to_check == false) return;

    int newTriangles = triangles;
    int I = nodes[start];
    for (int j = 0; j < subCount; ++j) {
        int J = subset[j];
        if (!v[I][J]) continue;
        for (int k = j + 1; k < subCount; ++k) {
            int K = subset[k];
            if (v[I][K] && v[J][K]) {
                newTriangles++;
            }
        }
    }
    subset.push_back(I);
    float curr = newTriangles * 1.0f / (subCount + 1);
    if (curr > best) {
        best = curr;
        nodes_max = subset;
    }
    test(newTriangles, start + 1, subCount + 1);
    subset.pop_back();
    test(triangles, start + 1, subCount);
}
};

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (auto& i : v) {
        for (auto& j : i) {
            cin >> j;
        }
    }

    vector<int> nodes;
    for (int i = 0; i < n; ++i) {
        nodes.push_back(i);
    }
    bool clique4 = false;
    for (size_t i = 0; !clique4 && i < nodes.size(); ++i) {
        int I = nodes[i];
        for (size_t j = i + 1; j < nodes.size(); ++j) {
            int J = nodes[j];
            if (!v[I][J]) continue;
            for (size_t k = j + 1; k < nodes.size(); ++k) {
                int K = nodes[k];
                if (v[I][K] && v[J][K]) {
                    for (size_t l = k + 1; l < nodes.size(); ++l) {
                        int L = nodes[l];
                        if (v[I][L] && v[j][L] && v[k][L]) {
                            clique4 = true;
                        }
                    }
                }
            }
        }
    }

    bool changed;
    do {
        changed = false;
        vector<int> new_nodes;
        vector<int> used(nodes.size());
        for (size_t i = 0; i < nodes.size(); ++i) {
            int I = nodes[i];
            for (size_t j = i + 1; j < nodes.size(); ++j) {
                int J = nodes[j];
                if (!v[I][J]) continue;
                for (size_t k = j + 1; k < nodes.size(); ++k) {
                    int K = nodes[k];
                    if (v[I][K] && v[J][K]) {
                        used[i]++;
                        used[j]++;
                        used[k]++;
                    }
                }
            }
        }
        for (size_t i = 0; i < nodes.size(); ++i) {
            if (used[i] == 0 || (used[i] == 1 && clique4)) {
                for (size_t j = 0; j < nodes.size(); ++j) {
                    v[nodes[i]][nodes[j]] = 0;
                    v[nodes[j]][nodes[i]] = 0;
                }
                changed = true;
            } else {
                new_nodes.push_back(nodes[i]);
            }
        }
        nodes = new_nodes;
    } while (changed);

    vector<int> v_count;
    for (size_t i = 0; i < nodes.size(); ++i) {
        int count = 0;
        for (size_t j = 0; j < nodes.size(); ++j) {
            if (v[nodes[i]][nodes[j]]) {
                ++count;
            }
        }
        v_count.push_back(count);
    }
    for (size_t i = 0; i < nodes.size(); ++i) {
        for (size_t j = 1; j < nodes.size(); ++j) {
            if (v_count[j - 1] < v_count[j]) {
                swap(v_count[j - 1], v_count[j]);
                swap(nodes[j - 1], nodes[j]);
            }
        }
    }

    Solver s(v, v_count, nodes);
    s.test(0, 0, 0);
    auto nodes_max = s.getResult();

    sort(nodes_max.begin(), nodes_max.end());
    cout << nodes_max.size() << endl;
    for (auto i : nodes_max) {
        cout << i + 1 << ' ';
    }
    cout << endl;
    return 0;
}
