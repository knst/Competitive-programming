#include <bits/stdc++.h>

using namespace std;

struct sync_initer {
    sync_initer() {
        std::ios_base::sync_with_stdio(false);
        cin.tie(0);
    }
} sync_init;

class Solver {
    vector<int> c;
    vector<vector<int>> edges;
    vector<bool> mask;
    int n;
    vector<bool> used;

    mutable vector<int> path;
    int target;

    public:
    Solver(int n, const vector <int>& c, const vector<vector<int>>& graph)
        : c(c)
          , edges(graph)
          , n(n)
          , used(n)
    {
    }

    bool dfs(int v, int p) const noexcept{
        for (const auto& u : edges[v]) {
            if (u == p) continue;
            if (u == target) {
                path.push_back(c[u]);
                path.push_back(c[v]);
                return true;
            }
            if (mask[u]) continue;
            if (dfs(u, v)) {
                path.push_back(c[v]);
                return true;
            }
        }
        return false;
    }

    vector<int> solve(const vector<pair<int, int>>& queries) noexcept {
        vector<int> answers;
        for (const auto& q : queries) {
            used[q.first] = true;
            used[q.second] = true;
        }
        mask.resize(edges.size());
        queue<int> qq;
        for (size_t i = 0; i < edges.size(); ++i) {
            int t = i;
            if (edges[t].size() == 1) {
                mask[t] = true;
                if (!used[t]) {
                    int p = edges[t][0];
                    edges[p].erase(find(edges[p].begin(), edges[p].end(), t));
                    qq.push(p);
                }
            }
        }
        while (!qq.empty()) {
            int t = qq.front();
            qq.pop();
            if (mask[t]) continue;
            if (edges[t].size() == 1) {
                mask[t] = true;
                if (!used[t]) {
                    int p = edges[t][0];
                    edges[p].erase(find(edges[p].begin(), edges[p].end(), t));
                    qq.push(p);
                }
            }
        }

        for (const auto &q : queries) {
            int u = q.first;
            int v = q.second;
            if (u == v) {
                answers.push_back(max(c[u], 0));
                continue;
            }
            path.clear();
            target = v;
            dfs(u, -1);


            int max_ending_here_0 = max(path[0], 0);
            int max_so_far_0 = max_ending_here_0;
            int max_ending_here_1 = max(path[1], 0);
            int max_so_far_1 = max_ending_here_1;
            for (size_t i = 2; i < path.size(); ++i) {
                max_ending_here_0 = max(path[i], max_ending_here_0 + path[i]);
                max_so_far_0 = max(max_so_far_0, max_ending_here_0);

                if (++i == path.size()) continue;
                max_ending_here_1 = max(path[i], max_ending_here_1 + path[i]);
                max_so_far_1 = max(max_so_far_1, max_ending_here_1);

            }
            answers.push_back(max(max_so_far_0, max_so_far_1));
        }
        return answers;
    }
};

vector <int> skippingSubpathSum(int n, const vector <int>& c, const vector<vector<int>>& graph,
        const vector<pair<int, int>>& queries) {
    Solver solver(n, c, graph);
    return solver.solve(queries);
}

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }
    vector<vector<int>> graph(n);
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int q;
    cin >> q;
    vector<pair<int, int>> queries;
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        queries.push_back(make_pair(u,v));
    }
    vector <int> answers = skippingSubpathSum(n, c, graph, queries);
    for (size_t i = 0; i < answers.size(); i++) {
        cout << answers[i] << (i + 1 != answers.size() ? "\n" : "");
    }
    cout << endl;
}
