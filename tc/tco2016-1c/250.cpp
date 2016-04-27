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

struct SumFullSet
{
 string isSumFullSet(vector <int> elements) {
     set<int> s;
     for (auto i : elements) {
         s.insert(i);
     }
     for (size_t i = 0; i < elements.size(); ++i) {
         for (size_t j = 0; j < elements.size(); ++j) {
             if (i == j)
                 continue;
             int x = elements[i] + elements[j];
             if (s.find(x) == s.end())
                 return "not closed";
         }
     }
     return "closed";

 }
};

int main() {


}
