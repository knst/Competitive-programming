#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> sum(vector<int>& a, vector<int>& b)
{
    size_t n = max(a.size(), b.size());
    a.resize(n);
    b.resize(n);

    vector<int> result;
    int over = 0;
    for (size_t i = 0; i < n; ++i) {
        over += a[i] + b[i];
        result.push_back(over % 10);
        over /= 10;
    }
    if (over)
        result.push_back(over);
    return result;
}
int main() {
#ifdef _KNST
    istream& input = cin;
    ostream& output = cout;
#else
    ifstream input("INPUT.TXT");
    ofstream output("OUTPUT.TXT");
#endif

    size_t n;
    input >> n;
    vector<int> count0;
    vector<int> count1;
    count0.push_back(1);
    count1.push_back(1);

    for (size_t i = 0; i < n; ++i) {
        vector<int> count0_next = sum(count0, count1);
        vector<int> count1_next = count0;
        count0 = count0_next;
        count1 = count1_next;
    }

    for (size_t i = count0.size(); i > 0; --i)
        output << count0[i-1];
    output << endl;
}
