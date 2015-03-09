#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct WolvesAndSheep{
    int getmin(vector<string> field) {
        int n = field.size();
        int m = field[0].size();
        string last;
        for (int i = 0; i < m; ++i)
            last += '.';

        vector<int> ilines;
        ilines.push_back(0);

        for (int i = 0; i < n; ++i) {
            bool ok = false;
            cerr << last << endl;
            for (int j = 0; j < m; ++j) {
                if (field[i][j] == '.')
                    continue;
                if (field[i][j] != last[j] && last[j] != '.') {
                    ok = true;
                }
                last[j] = field[i][j];
            }
            if (ok) {
                cerr << "i+" << i << endl;
                ilines.push_back(i);
            }
        }
        ilines.push_back(n);

        vector<int> jlines;
        int k = ilines.size() - 1;
        for (int l = 0; l < m; ++l) {
            vector<char> area;
            for (int i = 0; i < k; ++i)
                area.push_back('.');
            bool ok = false;
            for (int i = 0; i < k; ++i) {
                for (int j = ilines[i]; j < ilines[i+1]; ++j) {
                    if (field[j][l] == '.')
                        continue;
                    if (field[j][l] != area[i] && area[i] != '.')
                        ok = true;
                    area[i] = field[j][l];

                }
            }
            if (ok) {
                cerr << "j+" << l << endl;
                jlines.push_back(l);
                }
        }
        cerr << ilines.size() << ' ' << jlines.size() << endl;
        return ilines.size() + jlines.size() - 2;
    }
};

int main() {
    WolvesAndSheep w;
    cout << w.getmin(
    {"W.WSS",
     "WW.S.",
     ".SSS.",
     "SSS.S",
     ".SS.S"}) << endl;
    return 0;
    cout << w.getmin({".....",
     ".....",
      "....."}) << endl;
      cout << w.getmin({".SS",
       "...",
        "S..",
         "W.W"}) << endl;
    cout << w.getmin({"WWWSWWSSWWW",
     "WWSWW.SSWWW",
      "WS.WSWWWWS."}) << endl;
    cout << w.getmin({".W.S.W.W",
     "W.W.S.W.",
      ".S.S.W.W",
       "S.S.S.W.",
        ".S.W.W.S",
         "S.S.W.W.",
          ".W.W.W.S",
           "W.W.S.S."}) << endl;
    cout << w.getmin({"W.SSWWSSSW.SS",
     ".SSSSW.SSWWWW",
      ".WWWWS.WSSWWS",
       "SS.WSS..W.WWS",
        "WSSS.SSWS.W.S",
         "WSS.WS...WWWS",
          "S.WW.S.SWWWSW",
           "WSSSS.SSW...S",
            "S.WWSW.WWSWSW",
             ".WSSS.WWSWWWS",
              "..SSSS.WWWSSS",
               "SSWSWWS.W.SSW",
                "S.WSWS..WSSS.",
                 "WS....W..WSS."}) << endl;
    cout << w.getmin({"WW..SS",
     "WW..SS",
      "......",
       "......",
        "SS..WW",
         "SS..WW"}) << endl;

}
