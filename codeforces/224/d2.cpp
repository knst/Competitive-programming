#include <iostream>
#include <vector>

using namespace std;

int getPathLen(vector<string> deck, vector<vector<int>> lengths, int i, int j, bool block = false) {

    if (block)
        deck[i][j] = '#';
    if (deck[i][j] == '#')
        return lengths[i][j] = 0;
    if (lengths[i][j])
        return lengths[i][j];
    if (depth > lengths.size() * lengths[0].size())
        return depth;
    switch (deck[i][j]) {
    case '>':
        return lengths[i][j] = getPathLen(i, j+1, depth+1) + 1;
    case '<':
        return lengths[i][j] = getPathLen(i, j-1, depth+1) + 1;
    case '^':
        return lengths[i][j] = getPathLen(i-1, j, depth+1) + 1;
    case 'v':
        return lengths[i][j] = getPathLen(i+1, j, depth+1) + 1;
    }
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<string> deck;
    vector<vector<bool>> sources(n);
    vector<vector<int>> lenghts(n);
    vector<vector<char>> masks(n);
    for (int i = 0; i < n; ++i) {
        cin >> deck[i];
        sources[i].resize(m);
        lengths[i].resize(m);
        masks[i].resize(m);
        for (int j = 0; j < m; ++j) {
            sources[i][j] = true;
            lengths[i][j] = 0;
            masks[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            switch (deck[i][j]) {
            case '>':
                sources[i][j+1] = false;
                break;
            case '<':
                sources[i][j-1] = false;
                break;
            case '^':
                sources[i-1][j] = false;
                break;
            case 'v':
                sources[i+1][j] = false;
                break;
            }
        }
    }
 

    int maxLength = -1;
    int maxI = 0;
    int maxJ = 0;
    bool cycle = false;
    for (short i = 0; i < n; ++i) {
        for (short j = 0; j < m; ++j) {
            if (lengths[i][j] != 0)
                continue;
            stack<pair<short,int>> s;
            s.push(make_pair(i, j));
            while (!s.empty()) {
                auto p = s.top();
                s.pop();
                if (masks[p.first][p.second] == 2) {
                    cycle = true;
                    s.pop();
                } else {
                    masks[p.first][p.second] = 1;
                }

            }
            lengths[i][j] = getPathLen(deck, lengths, i, j);
            if (lengths[i][j] > lengths.size() * lengths[0].size()) {
                cout << -1 << endl;
                return 0;
            }
            if (lengths[i][j] > maxLength) {
                maxLength = lengths[i][j];
                maxI = i;
                maxJ = j;
            }
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            lengths[i][j] = 0;
    getPathLen(deck, lengths, maxI, maxJ, true);
    block = false;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            lengths[i][j] = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (lengths[i][j] != 0)
                continue;
            if (deck[i][j] == '#')
                continue;
            lengths[i][j] = getPathLen(i, j);
            if (lengths[i][j] == maxLength) {
                cout << maxLength * 2 << endl;
                return 0;
            }
        }
    }
    if (maxLength)
        maxLength = maxLength * 2 - 1;
    cout << maxLength << endl;

}
