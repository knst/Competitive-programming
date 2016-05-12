#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

struct LCMGCD
{
    using P = pair<size_t, size_t>;

    pair<size_t, size_t> calc(int i) {
        pair<size_t, size_t> n;
        while (i % 2 == 0) {
            n.first++;
            i /= 2;
        }
        while (i % 3 == 0) {
            n.second ++;
            i /= 3;
        }
        cerr << n.first << n.second << endl;
        return n;
    }
    uint32_t p2u(pair<size_t, size_t> n) {
        size_t v = n.first * 3 + n.second;
        return v;
    }

    pair<size_t, size_t> Min(P a, P b) {
        return {min(a.first, b.first), min(a.second, b.second)};
    }

    P Max(P a, P b) {
        return {max(a.first, b.first), max(b.second, b.second)};
    }

    void Trim(vector<P>& v) {
        v.erase(unique(v.begin(), v.end()), v.end());
    }
    void Trim(vector<vector<P>>& v) {
        v.erase(unique(v.begin(), v.end()), v.end());
    }
    string isPossible(vector <int> X, int T)
    {
        pair<size_t, size_t> t = calc(T);

        vector<P> values;
        for (auto i : X) {
            pair<size_t, size_t> n = calc(i);
            if (n.first < t.first)
                n.first = 0;
            else if (n.first > t.first)
                n.first = 2;
            else
                n.first = 1;
            if (n.second < t.second)
                n.second = 0;
            else if (n.second > t.second)
                n.second = 2;
            else
                n.second = 1;
            cerr << n.first << ' ' << n.second << endl;
            values.push_back(n);
        }
        Trim(values);
        vector<vector<P>> possibles;
        possibles.push_back(values);
        while (possibles[0].size() > 1) {
            vector<vector<P>> possibles_new;
            for (auto V : possibles) {
                size_t n = V.size();
                for (size_t i = 0; i < n; ++i) {
                    for (size_t j = i + 1; j < n; ++j) {
                        vector<P> result_min;
                        vector<P> result_max;
                        for (size_t k = 0; k < n; ++k) {
                            if (k != i && k != j) {
                                result_min.push_back(V[k]);
                                result_max.push_back(V[k]);
                            }
                        }
                        result_min.push_back(Min(V[i], V[j]));
                        result_max.push_back(Max(V[i], V[j]));
                        Trim(result_min);
                        Trim(result_max);
                        possibles_new.push_back(result_min);
                        possibles_new.push_back(result_max);
                    }
                }
            }
            Trim(possibles_new);
            possibles = possibles_new;
        }
        for (auto i : possibles) {
            if (i[0].first == 1 && i[0].second == 1) {
                return "Possible";
            }
        }
        return "Impossible";
    }


};

int main() {
    LCMGCD l;
    cout << l.isPossible({6,27,81,729}, 6);


    return 0;
}
