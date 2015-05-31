#include <iostream>
#include <vector>

using namespace std;

struct ModModMod
{
    long long findSum(vector<int> m2, int r) {
        int last = r + 1;
        vector<int> m;
        for (auto i : m2) {
            if (i < last) {
                m.push_back(i);
                last = i;
            }
        }
        vector<pair<int,int64_t>> v;
        v.push_back({r, 1});
        for (auto i : m) {
            vector<pair<int, int64_t>> v2;
            int64_t sum = 0;
            for (auto j : v) {
                sum += j.second * (j.first / i);
                v2.push_back({j.first % i, j.second});
            }
            v2.push_back({i - 1, sum});
            v = v2;
        }
        int64_t result = 0;
        for (auto i : v) {
            int64_t sum = 0;
            sum = i.first * (i.first + 1);
            sum /= 2;
            sum *= i.second;
            result += sum;
        }

        return result;
    }

};

int main() {
    ModModMod m;
    cout << m.findSum({5,3,2}, 10) << endl;
    cout << m.findSum({33,15,7,10,100,9,5}, 64) << endl;
    cout << m.findSum({995,149,28,265,275,107,555,241,702,462,519,212,362,478,783,381,602,546,183,886,59,317,977,612,328,91,771,131},
            992363) << endl;
    cout << m.findSum({100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100, 100},
            100) << endl;
    cout << m.findSum({2934},
            10000000) << endl;
}
