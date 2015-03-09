#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

namespace std {
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
};
    

struct MagicalStringDiv1 {
    int getLongest(string s) {
        int a = 0;
        int b = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '<')
                ++b;
        }
        int maximal = 0;
        for (int i = 0; i < s.size(); ++i) {
            maximal = max(maximal, min(a, b));
            if (s[i] == '>')
                ++a;
            if (s[i] == '<')
                --b;
        }
        return maximal * 2;
    }
};

int main() {
    MagicalStringDiv1 m;
    cout << m.getLongest("<><><<>") << endl;
    cout << m.getLongest(">>><<<") << endl;
    cout << m.getLongest("<<<>>>") << endl;
    cout << m.getLongest("<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>") << endl;


}
