#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;


struct FixedDiceGameDiv1{
    unordered_map<int,double> getMap(int a, int b) {
        unordered_map<int,double> result;
        result[0] = 1;
        for (int i = 0; i < a; ++i) {
            unordered_map<int,double> result2;
            for (const auto& i : result) {
                for (int j = 1; j <= b; ++j) {
                    result2[i.first + j] += result[i.first];
                }
            }
            result.swap(result2);

        }
        return result;
    }
    double getExpectation(int a, int b, int c, int d) {
        int minimum = c;
        if (a * b <= c)
            return -1;
        cerr << "^1";
        auto result = getMap(a, b);
        cerr << "^2";
        auto result2 = getMap(c, d);
        cerr << "^3";
        cerr << endl;
        double totalsum = 0;
        double corrects= 0;
        double totalsum2 = 0;
        for (int i = 1; i <= a * b; ++i) {
            if (i > minimum) {
                totalsum2 += result2[i-1];

                corrects += result[i] * totalsum2;
                totalsum += i * result[i] * totalsum2;
            } 
        }
        cerr << totalsum << ' ' << corrects << endl;
        return totalsum /= corrects;

    }
};

int main() {
    FixedDiceGameDiv1 f;
    cout << f.getExpectation(1,2,1,5) << endl;
    cout << f.getExpectation(3,1,1,3) << endl;
    cout << f.getExpectation(1,5,1,1) << endl;
    cout << f.getExpectation(2,6,50,30) << endl;
    cout << f.getExpectation(50,11,50,50) << endl;
    cout << f.getExpectation(26,2,50,50) << endl;

}
