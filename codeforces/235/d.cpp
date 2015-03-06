#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

inline vector<int> getDigit(long long n) {
    vector<int> d(10);
    do {
        d[n%10]++;
        n /= 10;
    } while (n);
    return d;
}
inline size_t lenLong(long long n) {
    size_t count = 0;
    do {
        ++count;
        n /= 10;
    } while (n);
    return count;
}
inline long long getLong(const vector<int>& v) {
    long long result = 0;
    for (size_t i = 9; i < 10; --i) {
        for (int j = 0; j < v[i]; ++j) {
            result *= 10;
            result += i;
        }
    }
    return result;
}

long long solve(long long n, long long mod) {
    map<pair<long long, long long>, long long> m;
    long long input = getLong(getDigit(n));
    m[make_pair(input, 0LL)] = 1;
    bool isFirst = true;
    for (size_t iteration = 0; iteration < lenLong(n); ++iteration) {
        map<pair<long long, long long>, long long> m_;
        //cout << endl;
        for (const auto& it : m) {
            //cout << it.first.first << ' ' << it.first.second << ' ' << it.second << endl;
            auto d = getDigit(it.first.first);
            for (size_t i = 0 + isFirst; i < 10; ++i) {
                if (d[i] == 0)
                    continue;
                --d[i];
                m_[make_pair(getLong(d), (it.first.second * 10 + i) % mod)] += it.second;
                //cout << "+" << ' ' << getLong(d) << ' ' << (it.first.second * 10 + i) % mod << ' ' << it.second << endl;
                ++d[i];
            }
        }
        m = m_;
        isFirst = false;
    }
    long long result = 0;
    for (const auto& it : m) {
        if (it.first.second % mod == 0)
            result += it.second;
    }
    return result;
}
long long solve2(long long n, long long mod) {
    vector<int> digits;
    do {
        digits.push_back(n % 10);
        n /= 10;
    } while (n);
    sort(digits.begin(), digits.end());
    int count = 0;
    do {
        if (digits[0] == 0)
            continue;
        long long m = 0;
        for (size_t i = 0; i < digits.size(); ++i) {
            m = (m * 10 + digits[i]) % mod;
        }
        if (m == 0)
            ++count;

    } while (next_permutation(digits.begin(), digits.end()));
    return count;
}
int main() {
    long long n;
    int mod;
    cin >> n >> mod;
    cout << solve(n, mod) << endl;
    if (false) {
        for (int n = 1; n < 1000; ++n) {
            for (int mod = 1; mod <= 100; ++mod) {
                long long result = solve(n, mod);
                long long res2 = solve2(n, mod);
                if (res2 != result)
                    cout << "!!! " << n << ' ' << mod << ' ' << result << ' ' << res2 << endl;
            }
        }
    }
    return 0;
}
