#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <random>
#include <vector>
#include <sys/time.h>

using namespace std;

#ifdef _knst
double in_time = 0.8;
#else
double in_time = 9.5;
#endif

namespace {
    double getTime() {
        timeval tv;
        gettimeofday(&tv, 0);
        return tv.tv_sec + tv.tv_usec * 1e-6;
    }
} // anonymous namespace

class PointsOnTheCircle {
    const int maxN = 200, minN = 20;
    const int maxP = 200, minP = 5;

    // number of points
    size_t n;

    // input matrix
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<size_t>> edges;

    // permutation of the points
    std::vector<int> perm;

    // cache of values for best choose
    std::vector<int64_t> score_cache;

    bool debug;

    double startTime;

    std::default_random_engine generator;


    static constexpr long double const_pi() { return std::atan(static_cast<long double>(1)) * 4; }
public:
    PointsOnTheCircle ()
    : startTime(getTime())
    , generator(0)
    {}

    double test_solution() {
        if (perm.size() != n) {
            throw std::runtime_error("permutation size mislead " + std::to_string(perm.size()) + " vs " + std::to_string(n));
        }

        // check that this is a valid permutation
        vector<bool> used(n);
        for (size_t i = 0; i < n; ++i) {
            if (perm[i] < 0 || perm[i] >= static_cast<int>(n)) {
                throw std::runtime_error("All elements of your return must be between 0 and " + std::to_string(n-1) + ", and your return contained " + std::to_string(perm[i]) + ".");
            }
            if (used[perm[i]]) {
                throw std::runtime_error("All elements of your return must be unique, and your return contained " + std::to_string(perm[i]) + " twice.");
            }
            used[perm[i]] = true;
        }

        // calculate score
        double score = 0;
        // score is sum of lengths of lines connecting permuted points (assuming circle radius = 1)
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j)
                if (matrix[perm[i]][perm[j]] == 1) {
                    double alpha = const_pi() / n * (j - i);
                    score += 2 * sin(alpha);
                    if (debug) {
                        cerr << "p[" << i << "] = " << perm[i] << ", " <<
                            "p[" << j << "] = " << perm[j] << ", " <<
                            "angle = " << alpha << ", " <<
                            "length = " << (2 * sin(alpha)) << endl;
                    }
                }
        }
        return score;
    }
    inline int64_t get_score(size_t diff) const noexcept {
        return score_cache[n + diff];
    }
    int64_t estimate_solution() {
        // calculate score
        int64_t score = 0;
        // score is sum of lengths of lines connecting permuted points (assuming circle radius = 1)
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                if (matrix[perm[i]][perm[j]] == 1) {
                    score += score_cache[j - i];
                }
            }
        }
        return score;
    }

    void init(const std::vector<int>& input) {
        n = sqrt(input.size());

        score_cache.resize(n + n);
        for (size_t i = 0; i < n; ++i) {
            double alpha = const_pi() / n * i;
            score_cache[i + n] = score_cache[i] = static_cast<int64_t>(1e9 * 2 * sin(alpha));
        }

        matrix.resize(n);
        int next = 0;
        size_t count = 0;
        for (size_t i = 0; i < n; ++i) {
            matrix[i].resize(n);
            for (size_t j = 0; j < n; ++j) {
                matrix[i][j] = input[next++];
                if (matrix[i][j]) {
                    ++count;
                }
            }
        }

        edges.resize(n);
        for (size_t i = 0; i < n; ++i) {
            edges[i].clear();
            for (size_t j = 0; j < n; ++j) {
                if (matrix[i][j]) {
                    edges[i].push_back(j);
                }
            }
        }
    }

    void input() {
        int m;
        cin >> m;
        std::vector<int> input(m);
        for (auto& i : input) {
            cin >> i;
        }
        init(input);
    }

    bool improve_permutation(int64_t& score) {
        bool improved = false;
        std::vector<size_t> inverse_perm(n);
        for (size_t i = 0; i < n; ++i) {
            inverse_perm[perm[i]] = i;
        }

        for (size_t i = 0; i < n; ++i) {
            int a = inverse_perm[i];
            int64_t sum1_a = 0;
            for (size_t k : edges[i]) {
                size_t c = inverse_perm[k];
                sum1_a += get_score(a - c);
            }

            for (size_t j = i + 1; j < n; ++j) {
                int64_t sum1 = sum1_a;
                int64_t sum2 = 0;
                int b = inverse_perm[j];
                for (size_t k : edges[i]) {
                    size_t c = inverse_perm[k];
                    sum2 += get_score(b - c);
                }
                for (size_t k : edges[j]) {
                    size_t c = inverse_perm[k];
                    sum1 += get_score(b - c);
                    sum2 += get_score(a - c);
                }
                if (sum1 > sum2) {
                    swap(perm[a], perm[b]);
                    swap(inverse_perm[i], inverse_perm[j]);
                    a = inverse_perm[i];

                    score = score - sum1 + sum2;
                    improved = true;
                }
            }
        }
        return improved;
    }
    void solve() {
        debug = false;
        perm.resize(n);
        for (size_t i = 0; i < n; ++i) {
            perm[i] = i;
        }
        int64_t best = estimate_solution();
        vector<int> best_perm = perm;

        {
            sort(perm.begin(), perm.end(), [&](int a, int b) {
                    return edges[a].size() > edges[b].size();
                    });
            std::deque<size_t> new_p;
            bool back = false;
            for (size_t i = 0; i < n; ++i) {
                if (back)
                    new_p.push_back(perm[i]);
                else
                    new_p.push_front(perm[i]);
                back = !back;
            }
            for (size_t i = 0; i < n; ++i) {
                perm[i] = new_p[i];
            }
        }
        while (getTime() - startTime < in_time) {
            shuffle(perm.begin(), perm.end(), generator);
            int64_t result = estimate_solution();
            if (result < best) {
                best = result;
                best_perm = perm;
            }
            while (improve_permutation(result) && getTime() - startTime < in_time) {
            }
            if (result < best) {
                best = result;
                best_perm = perm;
            }
        }
        perm = best_perm;
    }
    void output() {
        cout << perm.size() << endl;
        for (auto i : perm) {
            cout << i << '\n';
        }
    }
    void debugOutput() {
        debug = true;
        double result = test_solution();
        cerr << "score: " << result << endl;
    }

    std::vector<int> permute(const std::vector<int>& input) {
        init(input);
        solve();
        return perm;
    }
};

int main(int argc, char* []) {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    PointsOnTheCircle solver;
    solver.input();
    solver.solve();
    solver.output();

    if (argc != 1) {
        solver.debugOutput();
    }

    // test case of permute():
    {
        PointsOnTheCircle test;
        test.permute( {
            0, 0, 0, 0, 1, 0, 0, 0,
            0, 0, 0, 0, 1, 0, 0, 0,
            0, 0, 0, 0, 1, 0, 0, 1,
            0, 0, 0, 0, 1, 0, 1, 0,
            1, 1, 1, 1, 0, 0, 1, 0,
            0, 0, 0, 0, 0, 0, 0, 1,
            0, 0, 0, 1, 1, 0, 0, 1,
            0, 0, 1, 0, 0, 1, 1, 0 });
    }
}
