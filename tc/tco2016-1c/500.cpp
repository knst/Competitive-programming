#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <cmath>
#include <stack>

using namespace std;

struct ThreeProgrammers
{
    struct State {
        State() {
            a = b = c = nextB = nextC = 0;
        }
        size_t a;
        size_t b;
        size_t c;
        size_t nextB;
        size_t nextC;
        string backtrace;
        void pushA() {
            ++a;
            backtrace += 'A';
            nextB = 0;
            if (nextC > 0)
                nextC--;
        }
        void pushB() {
            ++b;
            backtrace += 'B';
            nextB = 1;
            if (nextC > 0)
                nextC--;
        }
        void pushC() {
            ++c;
            backtrace += 'C';
            nextC = 2;
            nextB = 0;
        }
        bool operator<(const State& s) const {
            if (a != s.a)
                return a < s.a;
            if (b != s.b)
                return b < s.b;
            if (c != s.c)
                return c < s.c;
            if (nextB != s.nextB)
                return nextB < s.nextB;
            return nextC < s.nextC;
        }
    };

    string validCodeHistory(string code) {
        size_t a = 0;
        size_t b = 0;
        size_t c = 0;
        for (auto i : code) {
            if (i == 'A')
                ++a;
            if (i == 'B')
                ++b;
            if (i == 'C')
                ++c;
        }

        size_t n = a + b + c;
        set<State> current;
        State start;
        current.insert(start);
        for (size_t i = 0; i < n; ++i) {
            set<State> newCurrent;
            for (auto s : current) {
                if (s.a < a) {
                    State x = s;
                    x.pushA();
                    newCurrent.insert(x);
                }
                if (s.b < b && s.nextB == 0) {
                    State x = s;
                    x.pushB();
                    newCurrent.insert(x);
                }
                if (s.c < c && s.nextC == 0) {
                    State x = s;
                    x.pushC();
                    newCurrent.insert(x);
                }
            }
            current = newCurrent;
        }
        if (current.size() > 0) {
            return current.begin()->backtrace;
        }
        return "impossible";
    }
};

int main() {
    ThreeProgrammers three;
    vector<string> tests{"CAB", "CBB", "BB", "BBA", "CAC", "ACAC", "ACABC", "BAABCABBCCACBAACABAABABBCCAACABCCAACCABCACACCBABAB", "CBACBACBACBACBB"};
    for (auto i : tests) {
        cout << three.validCodeHistory(i) << endl;
    }

}
