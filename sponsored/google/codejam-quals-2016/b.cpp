#include <iostream>
#include <string>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    for (size_t t = 0; t < n; ++t) {
        string s;
        cin >> s;
        size_t count = 0;
        for (size_t j = 1; j < s.size(); ++j) {
            if (s[j] != s[j - 1])
                ++count;
        }
        if (s[s.size() - 1] == '-')
            ++count;
        cout << "Case #" << t + 1<< ": " << count << endl;
    }
}
