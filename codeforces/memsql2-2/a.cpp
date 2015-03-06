/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
//test speed
/*
namespace std {
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}; */
namespace std {
    template <>
    class hash<pair<long long,long long>> {
    public:
        size_t operator()(const pair<long long, long long>& p) const {
            return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 32);
        }
    };
};

long long gcd(long long a, long long b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long C(long long n, long long k) {
    long long result = 1;
    for (long long i = k + 1; i <= n; ++i) {
        result *= i;
    }
    for (long long i = 1; i <= n - k; ++i) {
        result /= i;
    }
    return result;
}

void OutDiv(long long a, long long d) {
    long long g = gcd(a, d);
    cout << a / d << ' ' << a % d / g << "/" << d / g;
}
void calc(long long p, long long& a, long long& b, long long& d) {
    a = 0;
    b = 0;
    d = 1;
    for (int i = 0; i <= p; ++i) {
        long long k =1;
        for (int j = 0; j < i / 2; ++j)
            k *= 5;
        if (i % 2 ==0)
            a += k * C(p, i);
        else
            b += k * C(p, i);

        d *= 2;
    }
    d /= 2;
}

vector<int> process(const string& s) {
    vector<int> a;
    for (size_t i = s.size() - 1; i < s.size(); --i)
        a.push_back(s[i] - '0');
    while (!a.empty() && a.back() == 0)
        a.pop_back();
    return a;
}

void WriteRes(char c) {
    cout << c << endl;
    exit(0);
}

double getFromVec(const vector<int>& v) {
    double result = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == 1) {
            long long a;
            long long b;
            long long d;
            calc(i, a, b, d);
            result += a * 1.0 / d + b * sqrt(5) / d;
        }
    }
    return result;
}

typedef uint32_t ui32;
vector<int> geni(ui32 x) {
    vector<int> r;
//    cout << x << ": ";
    do {
        r.push_back(x % 2);
        x /= 2;
    } while (x);
 //   for (auto i : r)
  //      cout << i;
   // cout << endl;
    return r;
}
void PrintVec(const vector<int>& a) {
        for (auto& i : a)
            cout << i;
        cout << endl;
}


void Normal(vector<int>& v) {
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    vector<size_t> indexes;
    for (size_t i = v.size() - 2; i < v.size(); --i)
        indexes.push_back(i);
    while (!indexes.empty()) {
        vector<size_t> indexes_next;
        for (const auto& it : indexes) {
            size_t i = it;
            if (v[i] == 1 && v[i-1] == 1) {
                v[i+1] = 1;
                v[i] = v[i-1] = 0;
                indexes_next.push_back(i+2);
            }
        }
        indexes = indexes_next;
    }
    while (!v.empty() && v.back() == 0)
        v.pop_back();

}

char compare(const vector<int>& a1, const vector<int> a2) {
        if (a1.size() > a2.size())
            return '>';
        if (a1.size() < a2.size())
            return '<';
        for (size_t i = a1.size() - 1; i < a1.size(); --i) {
            if (a1[i] < a2[i])
                return ('<');
            if (a1[i] > a2[i])
                return ('>');
        }
        return ('=');
}
int main() {
    std::ios_base::sync_with_stdio(false);

    if (1) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        vector<int> a1 = process(s1);
        vector<int> a2 = process(s2);
    //    for (ui32 i = 0; i < 100; ++i) {
     //       for (ui32 j = 0; j < 100; ++j) {
//                if (i != 55 || j != 63)
 //                   continue;

 //           vector<int> a1 = geni(i);
  //          vector<int> a2 = geni(j);

//            PrintVec(a1);
 //           PrintVec(a2);
      //  cout << i << ' ' << j << ' ' ;
   //     double sum1 = getFromVec(a1);
    //    double sum2 = getFromVec(a2);
     //       if (sum1 + 1e-9  < sum2)
      //          cout << "< ";
       //     else if (sum1 - 1e-9 > sum2)
        //        cout << "> ";
         //   else cout << "= ";

        Normal(a1);
        Normal(a2);

        cout << compare(a1, a2);
        cout << endl;
  //      PrintVec(a1);
   //     PrintVec(a2);
//    }}



    }
    return 0;

    cout << " ";
    for (ui32 i = 0; i < 100; ++i)
        cout << ' ' << i % 10;
    cout << endl;
    for (ui32 i = 0; i < 100; ++i) {
        cout << i % 10 << " ";
        for (ui32 j = 0; j < 100; ++j) {
            vector<int> a = geni(i);
            vector<int> b = geni(j);
            double sum1 = getFromVec(a);
            double sum2 = getFromVec(b);
            if (sum1 + 1e-9  < sum2)
                cout << "< ";
            else if (sum1 - 1e-9 > sum2)
                cout << "> ";
            else cout << "= ";
        }
        cout << endl;
    }
    return 0;
    cout << getFromVec({1,1,1}) << " ";
    cout << getFromVec({0,0,0,1}) << endl;
    cout << getFromVec({1,1,1,1}) << " ";
    cout << getFromVec({0,0,0,0,1}) << endl;
    cout << getFromVec({1,1,1,1,1}) << " ";
    cout << getFromVec({0,0,0,0,0,1}) << endl;
    cout << getFromVec({0,0,0,1,1,1,1,1,1,1,1,1,1,1}) << " ";
    cout << getFromVec({0,0,0,0,0,0,0,0,0,0,0,1,1,0,1}) << endl;


    for (int p = 0; 0 && p < 20; ++p) {
        for (int i = 0; i <= p; ++i) {
//            cout << p << '-' << i << '\t' << C(p, i) << endl;
        }
        long long a, b, d;
        calc(p, a, b, d);
        cout << p << ": ";
        OutDiv(a, d);
        cout << "  ;  ";
        OutDiv(b, d);
        cout << "        ";
        cout << a * 2 / d << ' ' << b * 2 / d;
        cout << endl;

    }
    cout << endl;

    double sum = 0;
    for (int p = 0; p < 20; ++p) {
        double q = (sqrt(5.0L) + 1) / 2;
        double r = 1;
        for (int i = 0; i < p; ++i) {
            r *= q;
        }
        cout << p << ' ' << r << ' ' << sum << endl;
        sum += r;
    }



    return 0;
}
