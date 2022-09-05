#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
    }
};


class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root) return nullptr;
        if (root->left && root->right) {
            swap(root->left->val, root->right->val);
            swap(root->left->val, root->val);
            upsideDownBinaryTree(root->left);
            upsideDownBinaryTree(root->right);
        }
        return root;
    }
};

class Solution {
public:
    vector<int> p;

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        p.resize(upper + 100);
        for (int i = lower; i <= upper + 1; ++i) p[i] = i;

        for (int x : nums) {
            if (p[x] == x) p[x] = find(x + 1);
        }
        vector<string> res;

        for (int i = lower; i <= upper;) {
            while (p[i] != i) i = find(i);
            if (i > upper) break;
            int j = i;
            while (j <= upper && p[j] == j) ++j;
            if (j - 1 != i)
                res.push_back(to_string(i) + "->" + to_string(j - 1));
            else
                res.push_back(to_string(i));
            i = j;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> p;

    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        p.resize(upper - lower + 10);
        for (int i = 0; i <= upper - lower + 2; ++i) p[i] = i;

        for (int x : nums) {
            x -= lower;
            if (p[x] == x) p[x] = find(x + 1);
        }

        vector<string> res;

        for (int i = 0; i <= upper - lower;) {
            while (p[i] != i) i = find(i);
            if (i > upper - lower) break;
            int j = i;
            while (j <= upper - lower && p[j] == j) ++j;
            if (j - 1 != i)
                res.push_back(to_string(i + lower) + "->" + to_string(j - 1 + lower));
            else
                res.push_back(to_string(i + lower));
            i = j;
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}