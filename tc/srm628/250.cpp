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


struct DivisorsPowerWeak {
    long long Pow(long long x, long long pow) {
        double result = 1;
        for (int i = 0; i < pow; ++i)
            result *= x;
        if (result > 1e18)
            return 0;
        return result;
    }
    long long find_pow(long long pow, long long x) {
        long long in = 1;
        while (Pow(in, pow) < x && Pow(in, pow) != 0)
            in *= 2;
        if (Pow(in, pow) == 0)
            return -1;
        long long low = 1;
        long long high = in;
        while (low < high) {
            long long medium = (high + low) / 2;
            long long p = Pow(medium, pow);
            if (p == x)
                return medium;
            if (p < x) {
                low = medium + 1;
            } else {
                high = medium;
            }
        }
        if (Pow(low, pow) == x)
            return low;
        return -1;

    }
    long long findArgument(long long x){
        vector<long long> in;
        for (int pow = 1; pow < 63; ++pow) {
            long long y = find_pow(pow, x);
//            cerr << y << ' ' << pow << ' ' << x << endl;
            if (y != -1)
                in.push_back(y);
        }
        sort(in.begin(), in.end());
        for (auto & i : in) {
            //cerr << i << endl;
            long long p = Pow(i, d(i));
//            cout << i << ' ' << d(i) << ' ' << p << ' ' << x << endl;
            if (p == x)
                return i;
        }
        return -1;
    }
    long long d(const long long v) {
        long long count = 1;
        long long s = sqrt(v);
        //cout << '?' << v << endl;
        for (long long i = 2; i < s; ++i) {
            if (v % i == 0)
                ++count;
        }
        count *= 2;
        if (s * s == v)
            ++count;
        return count;
    }
};
struct DivisorsPower {
    long long Pow(long long x, long long pow) {
        double result = 1;
        long long result2 = 1;
        for (int i = 0; i < pow; ++i) {
            result *= x;
            result2 *= x;
        }
        if (result > 1e18)
            return 0;
        return result2;
    }
    long long find_pow(long long pow, long long x) {
        long long in = 1;
        while (Pow(in, pow) < x && Pow(in, pow) != 0)
            in *= 2;
        if (Pow(in, pow) == 0)
            return -1;
        long long low = 1;
        long long high = in;
        while (low < high) {
            long long medium = (high + low) / 2;
            long long p = Pow(medium, pow);
            if (p == x)
                return medium;
            if (p < x) {
                low = medium + 1;
            } else {
                high = medium;
            }
        }
        if (Pow(low, pow) == x)
            return low;
        return -1;

    }
    long long findArgument(long long x){
        vector<long long> in;
        for (int pow = 1; pow < 63; ++pow) {
            long long y = find_pow(pow, x);
//            cerr << y << ' ' << pow << ' ' << x << endl;
            if (y != -1)
                in.push_back(y);
        }
        sort(in.begin(), in.end());
        for (auto & i : in) {
            //cerr << i << endl;
            long long p = Pow(i, d(i));
            cout << i << ' ' << d(i) << ' ' << p << ' ' << x << endl;
            if (p == x)
                return i;
        }
        return -1;
    }
    long long d(const long long v) {
        int count = 1;
        int s = sqrt(v);
        //cout << '?' << v << endl;
        for (int i = 2; i < s; ++i) {
            if (v % i == 0)
                ++count;
        }
        count *= 2;
        if (s * s == v)
            ++count;
        return count;
    }
};

int main() {
    DivisorsPower p;
    DivisorsPowerWeak pW;
    for (int i = 0; i < 1; ++i) {
        unsigned long long value = 0;
        for (int i= 0; i < 8; ++i) {
            value *= 0x100;
            value += rand();
        }
        value %= (1000L * 1000 * 1000 * 1000 * 1000 * 1000);
        long long a = p.findArgument(value);
//        long long b = pW.findArgument(value);
        long long b = a;
        if (a != b)
            cout << value << ' ' << a << ' ' << b << endl;
    }
    cout << p.findArgument(4) << endl;
    cout << p.findArgument(10) << endl;
    cout << p.findArgument(64) << endl;
    cout << p.findArgument(10000) << endl;
    cout << p.findArgument(2498388559757689) << endl;
    cout << p.findArgument(1000L * 1000 * 1000 * 1000 * 1000 * 1000) << endl;

}
