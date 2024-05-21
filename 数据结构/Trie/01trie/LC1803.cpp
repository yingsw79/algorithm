#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/count-pairs-with-xor-in-a-range/

class Solution {
    struct Node {
        int cnt;
        vector<Node*> child;
        Node() {
            this->cnt = 0;
            this->child.resize(2, nullptr);
        }
    };
    Node* root;

    void insert(int num) {
        auto p = root;
        for (int i = 14; i >= 0; i--) {
            int c = num >> i & 1;
            if (!p->child[c]) {
                p->child[c] = new Node();
            }
            p = p->child[c];
            p->cnt++;
        }
    }

    int query(int num, int x) {
        int res = 0;
        auto p = root;
        for (int i = 14; i >= 0; i--) {
            int c = num >> i & 1;
            if (x >> i & 1) {
                if (p->child[c]) res += p->child[c]->cnt;
                if (!p->child[c ^ 1]) return res;
                p = p->child[c ^ 1];
            } else {
                if (!p->child[c]) return res;
                p = p->child[c];
            }
        }
        res += p->cnt;
        return res;
    }

    int calc(vector<int>& nums, int x) {
        root = new Node();
        int res = 0;
        for (int num : nums) {
            res += query(num, x);
            insert(num);
        }
        return res;
    }

public:
    int countPairs(vector<int>& nums, int low, int high) {
        return calc(nums, high) - calc(nums, low - 1);
    }
};

int main() {
    return 0;
}