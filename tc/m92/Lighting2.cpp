// C++11
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <sys/time.h>

using namespace std;

class Lighting {
    using Point = pair<int, int>;
    vector<vector<int>> map;

    bool trace(int x0, int y0, int x1, int y1) const {
        bool steep = false;
        if (abs(x1 - x0) < abs(y1 - y0)) {
            swap(x1, y1);
            swap(x0, y0);
            steep = true;
        }
        if (x1 < x0) {
            swap(x1, x0);
            swap(y1, y0);
        }

        int dx = x1 - x0;
        int dy = y1 - y0;
        float derror = std::abs(static_cast<float>(dy) / dx);
        float error = 0;
        int y = y0;

        if (x0 < 0) {
            error = derror * x0;
            y += (y1 > y0 ? 1 : -1) * truncf(error);
            error = error - truncf(error);
            x0 = 0;
        }

        for (int x = x0; x <= x1; ++x) {
            if (steep) {
                if (map[y][x] < 0)
                    return false;
            } else {
                if (map[x][y] < 0)
                    return false;
            }
            error += derror;
            if (error > 0.5) {
                y +=  (y1 > y0 ? 1 : -1);
                error -= 1.0;
            }
        }
        return true;
    }
    static int distance(Point a, Point b) {
        int x = a.first - b.first;
        int y = a.second - b.second;
        return x * x + y * y;
    }

    vector<Point> buildArea(int i, int j, int d) const {
        vector<Point> result;

        if (map[i][j] < 0) {
            return result;
        }
        int n = map.size();
        for (int a = -d; a <= d; ++a) {
            int x = a + i;
            if (x < 0 || x >= n) {
                continue;
            }
            for (int y = max(0, j - d); y <= min(n - 1, j + d); ++y) {
                int b = y - j;
                if (a * a + b * b > d * d) {
                    continue;
                }
                if (map[x][y] < 0) {
                    continue;
                }
                if (!trace(x, y, i, j)) {
                    continue;
                }
                result.push_back({x, y});
            }
        }
        return result;
    }

    int pretend(const vector<Point>& area) const {
        int score = 0;
        for (const auto& i : area) {
            if (map[i.first][i.second] == 0) {
                ++score;
            }
        }
        return score;
    }
    int pretendWithRemove(const vector<Point>& area) const {
        int score = 0;
        for (const auto& i : area) {
            if (map[i.first][i.second] == 1) {
                ++score;
            }
        }
        return score;
    }

    double getTime() {
        timeval tv;
        gettimeofday(&tv, 0);
        return tv.tv_sec + tv.tv_usec * 1e-6;
    }
    vector<Point> process(int d, size_t l) {
        int n = map.size();
        vector<Point> result;
        vector<vector<vector<Point>>> areas(n, vector<vector<Point>>(n));
        double startTime = getTime();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                areas[i][j] = buildArea(i, j, d);
            }
        }
        cerr << "build areas: " << getTime() - startTime << endl;
        while (l--) {
            if (getTime() - startTime > 18.0) {
                cerr << "getTime: " << getTime() << endl;
                cerr << "tl: " << getTime() - startTime << endl;
                cerr << "TL!!!" << endl;
                cerr << "TL!!!" << endl;
                cerr << "TL!!!" << endl;
                cerr << "TL!!!" << endl;
                // todo random fill
                return result;
            }
            int bestI = rand() % n;
            int bestJ = rand() % n;
            int bestScore = 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    int score = pretend(areas[i][j]);
                    if (score > bestScore) {
                        bestScore = score;
                        bestI = i;
                        bestJ = j;
                    }
                }
            }
            cerr << bestI << ' ' << bestJ << endl;
            result.push_back({bestI, bestJ});
            const auto& points = areas[bestI][bestJ];
            for (const auto& i : points) {
                ++map[i.first][i.second];
            }
        }
        while (getTime() - startTime < 18.0) {
            vector<pair<int, Point>> scores;
            for (auto p : result) {
                int score = pretendWithRemove(areas[p.first][p.second]);
                scores.push_back({score, p});
            }
            sort(scores.begin(), scores.end());
            bool changed = false;
            for (auto& s : scores) {
                if (getTime() - startTime > 18.0) {
                    break;
                }
                const auto& points = areas[s.second.first][s.second.second];
                for (const auto& i : points) {
                    --map[i.first][i.second];
                }
                int bestScore = pretend(areas[s.second.first][s.second.second]);
                int bestI = s.second.first;
                int bestJ = s.second.second;
                for (int i = 0; i < n; ++i) {
                    if (i == bestI) {
                        continue;
                    }
                    for (int j = 0; j < n; ++j) {
                        if (j == bestJ) {
                            continue;
                        }
                        bool needToTest = false;
                        for (const auto& p : scores) {
                            if (p.second == s.second) {
                                continue;
                            }
                            if (distance(p.second, {i, j}) <= (d + d) * (d + d)) {
                                needToTest = true;
                                break;
                            }
                        }
                        int score = areas[i][j].size();
                        if (needToTest) {
                            score = pretend(areas[i][j]);
                        }
                        if (score > bestScore) {
                            bestI = i;
                            bestJ = j;
                            bestScore = score;
                        }
                    }
                }
                if (bestScore != s.first) {
                    changed = true;
                    s.first = bestScore;
                    s.second.first = bestI;
                    s.second.second = bestJ;
                }
                const auto& newPoints = areas[bestI][bestJ];
                for (const auto& i : newPoints) {
                    ++map[i.first][i.second];
                }
            }
            if (changed) {
                result.clear();
                for (auto i : scores) {
                    result.push_back(i.second);
                }
            } else {
                break;
            }
        }
        if (getTime() - startTime > 18.0) {
            cerr << "TL throwed";
        }
        return result;
    }
    const int Empty = 0;
    const int Wall = -1;
    const int InWall = -2;
    const int Light = -3;
public:
    vector<string> setLights(vector<string> _map, int D, int L) {
        vector<string> ret;
        cerr << _map.size() << ' ' << D << ' ' << L << endl;
        for (auto i : _map)
            cerr << i << endl;
        cerr << endl;
        size_t S = _map.size();
        const size_t step = min<size_t>(100, 75. / pow(S * D, 0.5));
        size_t Ss = S * step;
        map.resize(Ss);
        for (auto& i : map) {
            i.resize(Ss);
        }
        for (size_t i = 0; i < S; ++i) {
            for (size_t j = 0; j < S; ++j) {
                int value = Empty;
                if (_map[i][j] == '#') {
                    value = Wall;
                }
                for (size_t a = 0; a < step; ++a) {
                    for (size_t b = 0; b < step; ++b) {
                        map[i * step + a][j * step + b] = value;
                    }
                }
            }
        }
        vector<Point> result = process(D * step, L);
        for (auto i : result) {
            string point = point2string(i.first, i.second, step);
            ret.push_back(point);
        }
        for (auto i : ret)
            cerr << i << endl;
        cerr << endl;
        return ret;
    }
    string point2string(int i, int j, int step) const {
        double a = (1. * i + .5) / step;
        double b = (1. * j + .5) / step;
        stringstream pointStream;
        pointStream.precision(2);
        pointStream << fixed << b << ' ' << a;
        string r = pointStream.str();
        return r;
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