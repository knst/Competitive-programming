#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <stack>
#include <ctime>

using namespace std;

typedef pair<int,int> Point;
typedef vector<pair <unsigned int, Point> > Costs;

class Timer {
    clock_t startTime;
public:
    Timer() {
        startTime = std::clock();
    }
    double getTime() {
        return static_cast<double>(std::clock() - startTime) / CLOCKS_PER_SEC;
    }
};

class ColorLinker {
    Timer timer;
    int ColorCount;
    int Penalty;
    vector<vector<char> > Grid;
    vector<string> BaseGrid;
    int N;
    vector<vector<Point> > Colors;
    vector<vector<unsigned int> > PathGrid;
    vector<vector<Point> > FromGrid;
    static const int dx[4];
    static const int dy[4];
    static const double TIME_LIMIT;
    static const double LINES_TIME_LIMIT;
private:
    int GetCost(char color) {
        int count = 0; 
        while (color) {
            count++;
            color = color & (color - 1);
        }
        return count + count * (count - 1) * Penalty;
    }

    vector<Point> MakePath(const set<Point>& areaFrom, set<Point>& areaEnd, int color) {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                PathGrid[i][j] = -1;
        queue<Point> q;
        for (const auto& p : areaFrom) {
            PathGrid[p.first][p.second] = 0;
            q.push(p);
        }

        set<Point> ends;
        while (!q.empty()) {
            Point p = q.front();
            q.pop();
            if (areaEnd.find(p) != areaEnd.end()) {
                ends.insert(p);
                continue;
            }

            if (BaseGrid[p.first][p.second] != '-' && areaFrom.find(p) == areaFrom.end())
                continue;

            for (int i = 0; i < 4; ++i) {
                int x = p.first + dx[i];
                int y = p.second + dy[i];
                if (x < 0 || y < 0 || x >= N || y >= N)
                    continue;
                unsigned int newCost = GetCost(Grid[x][y] | (1 << color)) + PathGrid[p.first][p.second];
                if (newCost < PathGrid[x][y]) {
                    PathGrid[x][y] = newCost;
                    FromGrid[x][y] = p;
                    q.push(make_pair(x, y));
                }
            }
        }
        if (ends.empty()) {
            cerr << "end not reachable: " << endl;
            for (const auto& p : ends)
                cerr << "\t" << p.first << ' ' << p.second << endl;
            throw "wtf! end not reachable";
        }
        unsigned int minimalEnd = -1;
        Point end;
        for (const auto& point: ends) {
            unsigned int cost = PathGrid[point.first][point.second];
            if (cost < minimalEnd) {
                minimalEnd = cost;
                end = point;
            }
        }
        vector<Point> v;
        Point p = end;
        while (areaFrom.find(p) == areaFrom.end()) {
            if (areaEnd.find(p) == areaEnd.end())
                v.push_back(p);
            p = FromGrid[p.first][p.second];
        }

        return v;
        
    }
    bool IsColored(int i, int j, int color) {
        if (BaseGrid[i][j] - '0' == color)
            return true;

        if (BaseGrid[i][j] != '-')
            return false;

        if (Grid[i][j] & (1 << color))
            return true;
        return false; 
    }
    void PrintSolution() {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (BaseGrid[i][j] == '-') {
                    if (Grid[i][j])
                        cerr << +Grid[i][j] << ' ';
                    else
                        cerr << "  ";
                } else {
                    cerr << BaseGrid[i][j] << '!';
                }
            }
            cerr << endl;
        }
        cerr << endl;
    }

    void TrivialSolve() {
        // trivial solution
        for (size_t color = 0; color < Colors.size(); ++color) {
            set<Point> area;
            set<Point> additionalArea;
            for (size_t index = 1; index < Colors[color].size(); ++index) {
                area.insert(Colors[color][index-1]);

                additionalArea.clear();
                additionalArea.insert(Colors[color][index]);

                vector<Point> path = MakePath(additionalArea, area, color);
                for (size_t pathIndex = 0; pathIndex < path.size(); ++pathIndex) {
                    Point p = path[pathIndex];
                    Grid[p.first][p.second] |= (1 << color);
                    area.insert(p);
                }
            }
        }
        PrintSolution();
    }

    bool RemoveExpensive(const Costs& costs) {
        bool updated = false;
        for (const auto& c : costs) {
            if (timer.getTime() > TIME_LIMIT)
                break;
            Point p = c.second;
            for (int color = 0; color < ColorCount; ++color) {
                bool canCleared = true;
                if (Grid[p.first][p.second] & (1 << color)) {
                    Grid[p.first][p.second] ^= (1 << color);
                    // start!
                    set<Point> points;
                    for (int i = 0; i < N; ++i) {
                        for (int j = 0; j < N; ++j) {
                            if (IsColored(i, j, color))
                                points.insert(make_pair(i, j));
                        }
                    }
                    if (points.size() >= 2) {
                        stack<Point> s;
                        s.push(Colors[color][0]);
                        while (!s.empty()) {
                            Point p = s.top();
                            s.pop();

                            for (int i = 0; i < 4; ++i) {
                                int x = p.first + dx[i];
                                int y = p.second + dy[i];
                                if (x < 0 || y < 0 || x >= N || y >= N)
                                    continue;
                                Point p = make_pair(x, y);
                                if (points.erase(p))
                                    s.push(p);
                            }
                        }
                        for (const auto& p : points) {
                            if (BaseGrid[p.first][p.second] != '-') {
                                canCleared = false;
                                break;
                            }
                        }
                        if (canCleared) {
                            for (const auto& p : points) {
                                if (Grid[p.first][p.second] & (1 << color))
                                    Grid[p.first][p.second] ^= (1 << color);
                            }
                        }
                    }
                    if (!canCleared)
                        Grid[p.first][p.second] ^= (1 << color);
                    else
                        updated = true;

                }
            }
            
        }
        return updated;
    }
    bool RemoveWithRestruct(const Costs& costs, unsigned long sumCost) {
        bool updated = false;
        for (const auto& c : costs) {
            if (timer.getTime() > TIME_LIMIT)
                break;
            if (c.first == 1)
                continue;
            Point p = c.second;
            for (int color = 0; color < ColorCount; ++color) {
                bool canCleared = true;
                if (Grid[p.first][p.second] & (1 << color)) {
                    // off p-point in one color
                    Grid[p.first][p.second] ^= (1 << color);
                    set<Point> points;
                    for (int i = 0; i < N; ++i) {
                        for (int j = 0; j < N; ++j) {
                            if (IsColored(i, j, color))
                                points.insert(make_pair(i, j));
                        }
                    }
                    if (points.size() >= 2) {
                        set<Point> summaryArea;
                        while (!points.empty()) {
                            set<Point> firstArea;
                            canCleared = true;

                            stack<Point> s;
                            Point firstPoint = *points.begin();
                            firstArea.insert(firstPoint);
                            points.erase(firstPoint);
                            s.push(firstPoint);
                            while (!s.empty()) {
                                Point p = s.top();
                                s.pop();
                                Grid[p.first][p.second] |= (1 << color);
                                firstArea.insert(p);

                                for (int i = 0; i < 4; ++i) {
                                    int x = p.first + dx[i];
                                    int y = p.second + dy[i];
                                    if (x < 0 || y < 0 || x >= N || y >= N)
                                        continue;
                                    Point p = make_pair(x, y);
                                    if (points.erase(p))
                                        s.push(p);
                                }
                            }
                            bool isNeeded = false;
                            for (const auto& p : firstArea) {
                                if (BaseGrid[p.first][p.second] != '-') {
                                    isNeeded = true;
                                    break;
                                }
                            }
                            if (isNeeded) {
                                if (summaryArea.empty()) {
                                    summaryArea = firstArea;
                                } else {
                                    vector<Point> path = MakePath(firstArea, summaryArea, color);
                                    for (size_t pathIndex = 0; pathIndex < path.size(); ++pathIndex) {
                                        Point p = path[pathIndex];
                                        Grid[p.first][p.second] |= (1 << color);
                                        summaryArea.insert(p);
                                        points.erase(p);
                                    }
                                    for (const auto& p : firstArea)
                                        summaryArea.insert(p);
                                }
                            }
                        }
                    }
                    if (! (Grid[p.first][p.second] & (1 << color))) {
                        updated = true;
                    }

                }
            }
            
        }
        return updated;
    }
    bool RestructLines() {
        bool updated = false;
        for (int color = 0; color < ColorCount; ++color) {
            set<Point> points;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (timer.getTime() > LINES_TIME_LIMIT)
                        return updated;
                    if (BaseGrid[i][j] != '-')
                        continue;
                    if (!(Grid[i][j] & (1 << color)))
                        continue;
                    if (Grid[i][j] ^ (1 << color))
                        continue;

                    int count = 0;
                    Point p = make_pair(i, j);
                    for (int i = 0; i < 4; ++i) {
                        int x = p.first + dx[i];
                        int y = p.second + dy[i];
                        if (x < 0 || y < 0 || x >= N || y >= N)
                            continue;
                        if (IsColored(x, y, color))
                            count++;
                    }
                    if (count == 2)
                        points.insert(make_pair(i, j));
                }
            }
            vector<set<Point>> v;
            while (!points.empty()) {
                if (timer.getTime() > LINES_TIME_LIMIT)
                    return updated;
                Point first = *points.begin();
                stack<Point> s;
                s.push(first);
                set<Point> vi;
                while (!s.empty()) {
                    Point p = s.top();
                    s.pop();
                    vi.insert(p);
                    for (int i = 0; i < 4; ++i) {
                        int x = p.first + dx[i];
                        int y = p.second + dy[i];
                        if (x < 0 || y < 0 || x >= N || y >= N)
                            continue;
                        if (!points.erase(make_pair(x,y)))
                            continue;
                        s.push(make_pair(x, y));
                    }
                }
                for (const auto& p : vi)
                    points.erase(p);
                if (vi.size() > 4)
                    v.push_back(vi);
            }
            for (const auto& vi : v) {
                if (timer.getTime() > LINES_TIME_LIMIT)
                    return updated;
                vector<Point> ends;
                for (const auto& p : vi) {
                    int count = 0;
                    for (int i = 0; i < 4; ++i) {
                        int x = p.first + dx[i];
                        int y = p.second + dy[i];
                        if (x < 0 || y < 0 || x >= N || y >= N)
                            continue;
                        if (vi.find(make_pair(x,y)) == vi.end())
                            continue;
                        count++;
                    }
                    if (count == 1)
                        ends.push_back(p);
                }
                if (ends.size() != 2) {
                    cerr << "assert: size ends in line optimization = " << ends.size() << endl;
                }
                for (const auto& p : vi) {
                    if (p != ends[0] && p != ends[1]) {
                        Grid[p.first][p.second] |= (1 << color);
                        Grid[p.first][p.second] ^= (1 << color);
                    }
                }
                set<Point> startArea;
                startArea.insert(ends[0]);
                set<Point> endArea;
                endArea.insert(ends[1]);
                vector<Point> path = MakePath(startArea, endArea, color);
                for (size_t pathIndex = 0; pathIndex < path.size(); ++pathIndex) {
                    Point p = path[pathIndex];
                    Grid[p.first][p.second] |= (1 << color);
                }

            }
        }
        return updated;
    }

    void Solve() {
        TrivialSolve();

        bool clearedOnce = false;
        unsigned int sumCost = 0;
        int iteration_count = 0;
        do {
            ++iteration_count;
            // remove expensive points
            Costs costs;
            sumCost = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (Grid[i][j]) {
                        if (BaseGrid[i][j] == '-') {
                            unsigned int cost = GetCost(Grid[i][j]);
                            costs.push_back(make_pair(cost, make_pair(i, j)));
                            sumCost += cost;
                        } else
                            ++sumCost;
                    }
                }
            }
            sort(costs.begin(), costs.end());
            reverse(costs.begin(), costs.end());

            clearedOnce |= RemoveExpensive(costs);

            costs.clear();
            sumCost = 0;
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (Grid[i][j]) {
                        if (BaseGrid[i][j] == '-') {
                            unsigned int cost = GetCost(Grid[i][j]);
                            costs.push_back(make_pair(cost, make_pair(i, j)));
                            sumCost += cost;
                        } else
                            ++sumCost;
                    }
                }
            }

            sort(costs.begin(), costs.end());
            reverse(costs.begin(), costs.end());

            clearedOnce |= RemoveWithRestruct(costs, sumCost);

            // restruct lines.


        } while (clearedOnce && timer.getTime() < TIME_LIMIT);
        RestructLines();
        cerr << "iter: " << iteration_count << endl;
        cerr << "total: " << sumCost << endl;

        PrintSolution();
    }

    void AddTriple(vector<int>& solution, int i, int j, int color) {
        solution.push_back(i);
        solution.push_back(j);
        solution.push_back(color);
    }

    vector<int> MakeSolution() {
        vector<int> solution;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (BaseGrid[i][j] != '-')
                    AddTriple(solution, i, j, BaseGrid[i][j] - '0');
                else {
                    for (int c = 0; c < ColorCount; ++c) {
                        if (Grid[i][j] & (1 << c))
                            AddTriple(solution, i, j, c);
                    }
                }
            }
        }
        return solution;
    }

    void Init(const vector<string>& grid, int penalty) {
        N = grid.size();
        BaseGrid = grid;
        Penalty = penalty;

        ColorCount = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid[i][j] != '-')
                    ColorCount = max(ColorCount, BaseGrid[i][j] - '0' + 1);
            }
        }

        Colors.resize(ColorCount);
        Grid.resize(N);
        PathGrid.resize(N);
        FromGrid.resize(N);
        for (int i = 0; i < N; ++i) {
            Grid[i].resize(N);
            PathGrid[i].resize(N);
            FromGrid[i].resize(N);
            for (int j = 0; j < N; ++j) {
                if (BaseGrid[i][j] != '-') {
                    int color = BaseGrid[i][j] - '0';
                    Colors[color].push_back(make_pair(i, j));
                    Grid[i][j] = 1 << color;
                } else {
                    Grid[i][j] = 0;
                }
            }
        }
    }
public:
    vector<int> link(vector<string> grid, int penalty) {
        Init(grid, penalty);
        Solve();
        return MakeSolution();
    }
};

const int ColorLinker::dx[] = {-1, 0, 0, 1};
const int ColorLinker::dy[] = {0, -1, 1, 0};
const double ColorLinker::TIME_LIMIT = 7.0;
const double ColorLinker::LINES_TIME_LIMIT = 8.0;
int main() {
    int gridSize;
    int penalty;
    cin >> gridSize;
    cin >> penalty;

    vector<string> grid(gridSize);
    for (int i = 0; i < gridSize; ++i) {
        cin >> grid[i];
        cerr << grid[i] << endl;
    }
    ColorLinker cl;
    vector<int> ret = cl.link(grid, penalty);
    cout << ret.size() << endl;
//    for (int i = 0; i < ret.size(); i += 3) {
//        cout << ret[i] << ' ' << ret[i + 1] << ' ' << ret[i + 2] << endl;
//    }
    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i] << endl;
    }

    return 0;
}
