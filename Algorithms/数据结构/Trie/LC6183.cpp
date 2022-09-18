#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/sum-of-prefix-scores-of-strings/
// Trie
class Solution {
    struct Node {
        vector<Node*> children;
        int cnt;
        Node() {
            this->children.resize(26, nullptr);
            this->cnt = 0;
        }
    };

    Node* root = new Node();

    void insert(string word) {
        auto p = root;
        for (char c : word) {
            c -= 'a';
            if (!p->children[c]) p->children[c] = new Node();
            p = p->children[c];
            p->cnt++;
        }
    }

    int search(string word) {
        auto p = root;
        int res = 0;
        for (char c : word) {
            c -= 'a';
            p = p->children[c];
            res += p->cnt;
        }
        return res;
    }

public:
    vector<int> sumPrefixScores(vector<string>& words) {
        for (auto& word : words) insert(word);
        vector<int> res;
        for (auto& word : words) res.push_back(search(word));
        return res;
    }
};

const int N = 1000010;

int tr[N][26], cnt[N], idx;

class Solution {
public:
    void insert(string& word) {
        int p = 0;
        for (auto c : word) {
            int u = c - 'a';
            if (!tr[p][u]) tr[p][u] = ++idx;
            p = tr[p][u];
            cnt[p]++;
        }
    }

    int query(string& word) {
        int p = 0, res = 0;
        for (auto c : word) {
            int u = c - 'a';
            p = tr[p][u];
            res += cnt[p];
        }
        return res;
    }

    vector<int> sumPrefixScores(vector<string>& words) {
        idx = 0;
        memset(tr, 0, sizeof tr);
        memset(cnt, 0, sizeof cnt);

        for (auto& word : words) insert(word);

        vector<int> res;
        for (auto& word : words)
            res.push_back(query(word));
        return res;
    }
};

// 字符串哈希
class Solution {
public:
    using ULL = unsigned long long;
    vector<int> sumPrefixScores(vector<string>& words) {
        unordered_map<ULL, int> mp;
        for (auto& word : words) {
            ULL hash = 0;
            for (auto& ch : word) {
                hash = hash * 131 + ch;
                ++mp[hash];
            }
        }
        vector<int> res;
        for (auto& word : words) {
            ULL hash = 0;
            int cnt = 0;
            for (auto& ch : word) {
                hash = hash * 131 + ch;
                cnt += mp[hash];
            }
            res.push_back(cnt);
        }
        return res;
    }
};

int main() {
    return 0;
}