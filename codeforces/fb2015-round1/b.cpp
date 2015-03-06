#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <sstream>
#include <memory>

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

    TrieNode* find(char c) const {
        for (auto& i : m_children) {
            if (i->value() == c)
                return i.get();
        }

        return nullptr;
    }
    void appendChild(shared_ptr<TrieNode> child) {
        m_children.push_back(child);
    }
    size_t insert(const string& s, size_t len);
    bool exist(const string& s, size_t len) const;

private:
    char m_value;
    bool m_flag;
    vector<shared_ptr<TrieNode>> m_children;
};

size_t TrieNode::insert(const string& s, size_t len)
{
    TrieNode* current = this;

    size_t result = 0;
    for (size_t i = 0; i < len; ++i) {
        TrieNode* child = current->find(s[i]);
        if (child != nullptr) {
            current = child;
        } else {
            shared_ptr<TrieNode> tmp(new TrieNode(s[i]));
            current->appendChild(tmp);
            current = tmp.get();
            if (result == 0)
                result = i + 1;
        }
    }
    current->setWordFlag();
    if (result == 0)
        result = len;
    return result;
}


bool TrieNode::exist(const string& s, size_t len) const
{
    const TrieNode* current = this;

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

    TrieNode trie;
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
