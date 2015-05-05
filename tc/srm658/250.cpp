#include <iostream>
#include <vector>

using namespace std;

class OddEvenTree
{
    vector <int> getTree(vector <string> x) {
        size_t n = x.size();
        for (size_t i = 0; i < n; ++i) {
            if (x[i][i] != 'E')
                return {-1};
        }
        vector<vector<int>> v(n, vector<int>(n));
        for (size_t i = 0; i < n; ++i)
            for (size_t j = 0; j < n; ++j)
                v[i][j] = (x[i][j] == 'O');

        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (v[i][j] != (v[0][i] + v[0][j]) % 2)
                    return {-1};
            }
        }
        bool ok = false;
        size_t index = 0;
        for (size_t i = 0; i < n; ++i)
            if (x[0][i] == 'O') {
                ok = true;
                index = i;
            }
        if (n > 1 && !ok)
            return {-1};

        vector<int> result;
        for (size_t i = 0; i < n; ++i) {
            if (x[0][i] == 'O') {
                result.push_back(1);
                result.push_back(i + 1);
            }
        }
        for (size_t i = 1; i < n; ++i) {
            if (x[0][i] == 'E') {
                result.push_back(index);
                result.push_back(i);
            }

        }
        return result;
    }
};

int main() {
}
