#include <bits/stdc++.h>

using namespace std;

class Solver {
    vector<int> c;
    vector<vector<int>> edges;
    int n;

    vector<int> path;
    vector<int> oddPath;
    vector<int> evenPath;
    int target;

    public:
    Solver(int n, const vector <int>& c, const vector<vector<int>>& graph)
        : c(c)
          , edges(graph)
          , n(n)
    {
    }

    bool dfs(int v, int p) {
        if (v == target) {
            path.push_back(v);
            return true;
        }
        for (const auto& u : edges[v]) {
            if (u == p) continue;
            if (dfs(u, v)) {
                path.push_back(v);
                return true;
            }
        }
        return false;
    }

    vector<int> solve(const vector<pair<int, int>>& queries) {
        vector<int> answers;
        answers.reserve(queries.size());
        for (const auto &q : queries) {
            path.clear();
            oddPath.clear();
            evenPath.clear();
            int u = q.first;
            int v = q.second;
            if (u == v) {
                answers.push_back(max(c[u], 0));
                continue;
            }
            target = v;
            dfs(u, -1);


            int max_ending_here_0 = max(c[path[0]], 0);
            int max_so_far_0 = max_ending_here_0;
            int max_ending_here_1 = max(c[path[1]], 0);
            int max_so_far_1 = max_ending_here_1;
            for (size_t i = 2; i < path.size(); ++i) {
                max_ending_here_0 = max(max(0, c[path[i]]), max_ending_here_0 + c[path[i]]);
                max_so_far_0 = max(max_so_far_0, max_ending_here_0);

                if (++i == path.size()) continue;
                max_ending_here_1 = max(max(0, c[path[i]]), max_ending_here_1 + c[path[i]]);
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
