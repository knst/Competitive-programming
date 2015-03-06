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
}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Trie {
public:
    Trie(char value = 0, bool flag = false)
    : m_value(value)
    , m_flag(flag)
    , m_children(3, nullptr)
    {}

    inline char value() const {
        return m_value;
    }

    inline bool isWord() const {
        return m_flag;
    }
    inline void setWordFlag() {
        m_flag = true;
    }

    inline Trie* find(char c) const {
        return m_children[c - 'a'];
    }

    size_t insert(const string& s);
    bool exist(const string& s) const;

    void appendChild(Trie* child) {
        m_children[child->value() - 'a'] = child;
    }

private:
    char m_value;
    bool m_flag;
    vector<Trie*> m_children;
};

size_t Trie::insert(const string& s)
{
    Trie* current = this;

    size_t result = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        Trie* child = current->find(s[i]);
        if (child != nullptr) {
            current = child;
        } else {
            Trie* tmp = new Trie(s[i]);
            current->appendChild(tmp);
            current = tmp;
            if (result == 0)
                result = i + 1;
        }
    }
    current->setWordFlag();
    if (result == 0)
        result = s.size();
    return result;
}


bool Trie::exist(const string& s) const
{
    const Trie* current = this;

    if (current == nullptr)
        return false;

    for (size_t i = 0; i < s.size(); ++i) {
        current = current->find(s[i]);
        if (current == nullptr)
            return false;
    }

    return current->isWord();
}



int main() {
    std::ios_base::sync_with_stdio(false);

    Trie t;
    size_t n;
    size_t m;
    cin >> n >> m;
    for (size_t i = 0; i < n; ++i) {
        string s;
        cin >> s;
        t.insert(s);
    }
    for (size_t i = 0; i < m; ++i) {
        string s;
        cin >> s;
        string s1 = s;
        bool ok =false;
        for (size_t i = 0; !ok && i < s.size(); ++i) {
            for (char a = 'a'; a <= 'c'; ++a) {
                if (a == s[i])
                    continue;
                s1[i] = a;
                if (t.exist(s1))
                    ok = true;

            }
            s1[i] = s[i];
        }
        if (ok) {
            cout << "YES" << endl;
        }else
            cout << "NO" << endl;
    }
    return 0;

}
