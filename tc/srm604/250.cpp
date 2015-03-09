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
    

struct PowerOfThree{
    long long abs(long long a) {
        return a < 0 ? -a : a;
    }
    pair<long long, long long> make_pair2(long long x, long long y) {
        if (x < y)
            swap(x, y);
        return make_pair(x, y);
    }
    const string possible = "Possible";
    const string impossible = "Impossible";
    string ableToGet(int x, int y) {
        if (x == 0 && y == 0)
            return possible;
        if (x < y)
            swap(x, y);

        long long sum = x + y;
        long long sumiter = 0;
        long long iter2 = 1;
        set<pair<long long,long long>> p;
        p.insert(make_pair(0, 0));
        while ((sumiter + iter2) / 9 <= abs(sum)) {
            set<pair<long long, long long>> p2;
            for (const auto i : p) {
                if (i.first + i.second + iter2 > 0) {
                    p2.insert(make_pair2(i.first, i.second + iter2));
                    p2.insert(make_pair2(i.first + iter2, i.second));
                }
                if (i.first + i.second - iter2 < 0) {
                    p2.insert(make_pair2(i.first, i.second - iter2));
                    p2.insert(make_pair2(i.first - iter2, i.second));
                }
            }
            p = p2;
            if (p.find(make_pair<long long, long long>(x, y)) != p.end())
                return possible;
            iter2 *= 3;
            sumiter += iter2;
        }
        return impossible;
    }
};

int main() {
    PowerOfThree p;
    cout << "- " << p.ableToGet(-49655226, -128491440) << endl;
    cout << "1 " << p.ableToGet(0, 0) << endl;
    cout << "1 " << p.ableToGet(1, 3) << endl;
    cout << "1 " << p.ableToGet(0, 2) << endl;
    cout << "0 " << p.ableToGet(1, 9) << endl;
    cout << "0 " << p.ableToGet(3, 0) << endl;
    cout << "0 " << p.ableToGet(1, 1) << endl;
    cout << "1 " << p.ableToGet(-6890, 18252) << endl;
    cout << "0 " << p.ableToGet(1000000000, -1000000000) << endl;

}
