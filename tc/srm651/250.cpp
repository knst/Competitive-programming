#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

struct RobotOnMoon {
    int longestSafeCommand(vector<string> board) {
        size_t x = 0;
        size_t y = 0;
        for (size_t i = 0; i < board.size(); ++i) {
            for (size_t j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'S') {
                    x = i;
                    y = j;
                }
            }
        }
        size_t maximal = board.size() + board[0].size() - 2;
        for (size_t i = 0; i < board.size(); ++i)
            if (board[i][y] == '#')
                maximal = -1;
        for (size_t j = 0; j < board[0].size(); ++j)
            if (board[x][j] == '#')
                maximal = -1;
        return maximal;
    }
};


int main() {
    RobotOnMoon r;
    cout << r.longestSafeCommand({"#####",
             "#...#",
              "#.S.#",
               "#...#",
                "#####"}) << endl;
    cout << r.longestSafeCommand({"S......"} ) << endl;
    cout << r.longestSafeCommand({"#.######",
             "#.#..S.#",
              "#.#.##.#",
               "#......#",
                "########"}) << endl;
    cout << r.longestSafeCommand({"S"} ) << endl;
    return 0;
}

