#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>

using namespace std;


struct HappyLetterDiv1 {
    string getHappyLetters(string letters) {
        vector<char> count(26, 0);
        for (auto& l : letters) {
            count[l-'a']++;
        }
        string result = "";
        for (int base = 0; base < 26; ++base) {
            if (!count[base])
                continue;

            priority_queue<pair<int,char>> count2;
            for (int i = 0; i < 26; ++i) {
                if (i != base && count[i])
                    count2.push({count[i], i});
            }
            while (count2.size() >= 2) {
                auto f1 = count2.top();
                count2.pop();
                auto f2 = count2.top();
                count2.pop();
                f1.first--;
                f2.first--;
                if (f1.first)
                    count2.push(f1);
                if (f2.first)
                    count2.push(f2);
            }
            if (count2.empty() || count2.top().first < count[base])
                result += static_cast<char>('a' + base);
/*            while (!count2.empty()) {
                cout << static_cast<char>('a' + count2.top().second);
                count2.pop();
            }
            cout << endl;
*/
        }
        return result;
    }
};

int main() {
    HappyLetterDiv1 h;
    cout << h.getHappyLetters("aabbacccc") << endl;
    cout << h.getHappyLetters("aaaaaaaccdd") << endl;
    cout << h.getHappyLetters("ddabccadb") << endl;
    cout << h.getHappyLetters("aaabbb") << endl;
    cout << h.getHappyLetters("rdokcogscosn") << endl;

}
