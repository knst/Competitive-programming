#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int getPathLen(int I, int J, vector<string>& deck, vector<vector<int>>& lengths, bool block = false)
{
    stack<pair<int,int>> poses;
    poses.push({I, J});

    size_t Maximal = lengths.size() * lengths[0].size();
    while (!poses.empty()) {
        auto T = poses.top();
        int i = T.first;
        int j = T.second;

        if (poses.size() > Maximal)
            lengths[i][j] = Maximal+1;

        if (lengths[i][j]) {
            poses.pop();
            continue;
        }

        if (deck[i][j] == '#') {
            poses.pop();
            continue;
        }

        int newI = i;
        int newJ = j;
        switch (deck[i][j]) {
        case '>':
            newJ++;
            break;
        case '<':
            newJ--;
            break;
        case '^':
            newI--;
            break;
        case 'v':
            newI++;
        }
        if (lengths[newI][newJ] || deck[newI][newJ] == '#') {
            lengths[i][j] = lengths[newI][newJ] + 1;
            if (block)
                deck[i][j] = '#';
        } else
            poses.push({newI, newJ});

    }
    return lengths[I][J];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<string> deck(n);
    vector<vector<int>> lengths(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i)
        cin >> deck[i];
    int maxLength = -1;
    int maxI = 0;
    int maxJ = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (lengths[i][j] != 0)
                continue;
            lengths[i][j] = getPathLen(i, j, deck, lengths);
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
    getPathLen(maxI, maxJ, deck, lengths, true);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            lengths[i][j] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (lengths[i][j] != 0)
                continue;
            if (deck[i][j] == '#')
                continue;
            lengths[i][j] = getPathLen(i, j, deck, lengths);
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
