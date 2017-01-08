// C++11
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Lighting {
public:
    vector<string> setLights(vector<string> map, int D, int L) {
        vector<string> ret;
        cerr << map.size() << ' ' << D << ' ' << L << endl;
        for (auto i : map)
            cerr << i << endl;
        cerr << endl;
        size_t S = map.size();
        for (int i = 0; i < L; ++i) {
            double bestCount = -1;
            int bestX = 0;
            int bestY = 0;
            for (size_t x = 0; x < S; ++x) {
                for (size_t y = 0; y < S; ++y) {
                    double count = 0;
                    int penalty = 1.0;
                    if (map[x][y] != '.') {
                        continue;
                    }
                    for (int p = -D; p <= D; ++p) {
                        for (int q = -D; q <= D; ++q) {
                            if (p * p + q * q > D * D) {
                                continue;
                            }
                            if (p + x < S && q + y < S) {
                                if (map[p + x][q + y] == '.') {
                                    count += 1.0;
                                }
                                if (map[p + x][q + y] == '*') {
                                    penalty *= (p * p + q * q) / D / D;
                                }
                            }
                        }
                    }
                    count *= penalty;
                    if (count > bestCount) {
                        bestCount = count;
                        bestX = x;
                        bestY = y;
                    }
                }
            }
            map[bestX][bestY] = '*';
            double a = bestX + 0.5;
            double b = bestY + 0.5;
            stringstream pointStream;
            pointStream.precision(2);
            pointStream << fixed << a << ' ' << b;
            string r = pointStream.str();
            ret.push_back(r);
//            ret.push_back(to_string(rand() % S) + "." + to_string(rand() % 90 +10) + " "
//                        + to_string(rand() % S) + "." + to_string(rand() % 90 +10));


//            ret.push_back(to_string(rand() % S) + "." + to_string(rand() % 90 +10) + " "
//                        + to_string(rand() % S) + "." + to_string(rand() % 90 +10));
        }
        for (auto i : ret)
            cerr << i << endl;
        cerr << endl;
        return ret;
    }
};
// -------8<------- end of solution submitted to the website -------8<-------

template<class T> void getVector(vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i)
        cin >> v[i];
}

int main() {
    Lighting l;
    int S;
    cin >> S;
    vector<string> map(S);
    getVector(map);

    int D;
    cin >> D;

    int maxL;
    cin >> maxL;

    vector<string> ret = l.setLights(map, D, maxL);
    cout << ret.size() << endl;
    for (size_t i = 0; i < ret.size(); ++i)
        cout << ret[i] << endl;
    cout.flush();
}
