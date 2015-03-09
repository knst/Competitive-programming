#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

struct SpamChecker {
    string spamCheck(string judgeLog, int good, int bad) {
        int result = 0;
        for (auto c : judgeLog) {
            if (c == 'o')
                result += good;
            if (c == 'x')
                result -= bad;
            if (result < 0)
                return "SPAM";
        }
        return "NOT SPAM";
    }
};

int main() {
    SpamChecker s;
    cout << s.spamCheck("ooooxxxo", 2, 3) << endl;


}
