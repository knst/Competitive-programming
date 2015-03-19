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


struct GoodSubset {
    int numberOfSubsets(int goodValue, vector <int> d) {
        map<int,int> m;
        m[1] = 1;
        const int MAX = 2 * 1000 * 1000 * 1000;
        const int MOD = 1000 * 1000 * 1000 + 7;
        for (const auto& i : d) {
            if (goodValue % i != 0)
                continue;
            map<int,int> m2 = m;
            for (const auto& j : m) {
                long long value = j.first * i;
                if (value > MAX)
                    continue;
                m2[value] = (static_cast<long long>(j.second) + m2[value]) % MOD;
            }
            m.swap(m2);
        }
        if (goodValue == 1)
            return m[goodValue] - 1;
        return m[goodValue];
    }
};

int main() {
    GoodSubset g;;
    cout << g.numberOfSubsets(10, {2,3,4,5}) << endl;
    cout << g.numberOfSubsets(10, {2,3,4,5}) << endl;
    cout << g.numberOfSubsets(6, {2,3,4,5,6}) << endl;
    cout << g.numberOfSubsets(1, {1,1,1}) << endl;
    cout << g.numberOfSubsets(12, {1,2,3,4,5,6,7,8,9,10,11,12}) << endl;
    cout << g.numberOfSubsets(5, {1,2,3,4}) << endl;
    cout << g.numberOfSubsets(5, {2    , 3    ,   5    ,   7    ,   11    ,  13    ,  17    ,  19    ,  23    ,  29,
            31    ,  37    ,  41    ,  43    ,  47    ,  53    ,  59    ,  61    ,  67    ,  71,
            73    ,  79    ,  83    ,  89    ,  97    ,  101    , 103    , 107    , 109    , 113,
            127    , 131    , 137    , 139    , 149    , 151    , 157    , 163    , 167    , 173,
            179    , 181    , 191    , 193    , 197    , 199    , 211    , 223    , 227    , 229,
            233    , 239    , 241    , 251    , 257    , 263    , 269    , 271    , 277    , 281,
            283    , 293    , 307    , 311    , 313    , 317    , 331    , 337    , 347    , 349,
            353    , 359    , 367    , 373    , 379    , 383    , 389    , 397    , 401    , 409,
            419    , 421    , 431    , 433    , 439    , 443    , 449    , 457    , 461    , 463,
            467    , 479    , 487    , 491    , 499    , 503    , 509    , 521    , 523    , 541,}) << endl;

}
