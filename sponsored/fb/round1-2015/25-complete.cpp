#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <sstream>

using namespace std;

class TrieNode {
public:
    TrieNode(char value = 0, bool flag = false)
    : m_value(value)
    , m_flag(flag)
    {}

    char value() const {
        return m_value;
    }

    bool isWord() const {
        return m_flag;
    }
    void setWordFlag() {
        m_flag = true;
    }

    TrieNode* find(char c) {
        for (auto& i : m_children) {
            if (i->value() == c)
                return i;
        }

        return nullptr;
    }
    void appendChild(TrieNode* child) {
        m_children.push_back(child);
    }

private:
    char m_value;
    bool m_flag;
    vector<TrieNode*> m_children;
};

class Trie {
public:
    Trie()
    : root(new TrieNode) {}
    size_t insert(const string& s, size_t len);
    bool exist(const string& s, size_t len) const;
private:
    TrieNode* root;
};

size_t Trie::insert(const string& s, size_t len)
{
    TrieNode* current = root;

    size_t result = 0;
    for (size_t i = 0; i < len; ++i) {
        TrieNode* child = current->find(s[i]);
        if (child != nullptr) {
            current = child;
        } else {
            TrieNode* tmp = new TrieNode(s[i]);
            current->appendChild(tmp);
            current = tmp;
            if (result == 0)
                result = i + 1;
        }
    }
    current->setWordFlag();
    if (result == 0)
        result = len;
    return result;
}


bool Trie::exist(const string& s, size_t len) const
{
    TrieNode* current = root;

    if (current == nullptr)
        return false;

    for (size_t i = 0; i < len; ++i) {
        current = current->find(s[i]);
        if (current == nullptr)
            return false;
    }

    return current->isWord();
}

void solve() {
    int n;
    cin >> n;

    Trie trie;
    size_t count = 0;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        count += trie.insert(s, s.size());
    }
    cout << count << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
}
