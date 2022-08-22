#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        auto check1 = [&](int mid) -> bool {
            int st = initialEnergy;
            for (auto x : energy) {
                if (st > x)
                    st -= x;
                else
                    return false;
            }
            return true;
        };

        auto check2 = [&](int mid) -> bool {
            int st = initialExperience;
            for (auto x : experience) {
                if (st > x)
                    st += x;
                else
                    return false;
            }
            return true;
        };

        int l1 = 0, r1 = 1e5;
        while (l1 < r1) {
            int mid1 = l1 + r1 >> 1;
            if (check1(mid1))
                r1 = mid1;
            else
                l1 = mid1 + 1;
        }

        int l2 = 0, r2 = 1e5;
        while (l2 < r2) {
            int mid2 = l2 + r2 >> 1;
            if (check1(mid2))
                r2 = mid2;
            else
                l2 = mid2 + 1;
        }

        int res = max(l1 - initialEnergy, 0) + max(l2 - initialExperience, 0);
        return res;
    }
};

class Solution {
public:
    string largestPalindromic(string num) {
        map<int, int, greater<int>> mp;
        for (auto& x : num) {
            mp[x - '0']++;
        }
        string res, tmp;
        for (auto& [x, y] : mp) {
            if (res.empty() && x == 0) continue;
            if (y % 2 == 0) {
                while (y != 0) {
                    res.push_back(x + '0');
                    tmp.push_back(x + '0');
                    y -= 2;
                }
            } else {
                while (y != 1) {
                    res.push_back(x + '0');
                    tmp.push_back(x + '0');
                    y -= 2;
                }
            }
        }
        for (auto& [x, y] : mp) {
            if (y == 1) {
                res.push_back(x + '0');
                break;
            }
        }
        reverse(tmp.begin(), tmp.end());
        return res + tmp;
    }
};

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
    static const int N = 100010;
    vector<int> g[N];
    void dfs(TreeNode* root) {
        if (!root->left && !root->right) return;
        if (root->left) {
            g[root->val].push_back(root->left->val);
            g[root->left->val].push_back(root->val);
            dfs(root->left);
        }
        if (root->right) {
            g[root->val].push_back(root->right->val);
            g[root->right->val].push_back(root->val);
            dfs(root->right);
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        dfs(root);
        queue<int> q;
        bool st[N];
        memset(st, 0, sizeof st);
        q.push(start);
        st[start] = true;
        int res = 1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int u = q.front();
                q.pop();
                for (auto v : g[u]) {
                    if (st[v]) continue;
                    q.push(v);
                    st[v] = true;
                }
            }
            res++;
        }
        return res;
    }
};

class Solution {
public:
    int minNumberOfHours(int a, int b, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            while (a <= energy[i]) {
                res++;
                a++;
            }
            while (b <= experience[i]) {
                res++;
                b++;
            }
            a -= energy[i];
            b += experience[i];
        }
        return res;
    }
};

class Solution {
public:
    struct Node {
        int l, r;
        long long sum;
        bool friend operator<(const Node& x, const Node& y) { return x.sum < y.sum; }
    };

    priority_queue<Node> q;

    Node make_Node(int l, int r, long long sum) {
        Node x;
        x.l = l, x.r = r, x.sum = sum;
        return x;
    }

    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0, res;
        for (int i = 1; i <= n; ++i) {
            sum += nums[i-1];
            q.push(make_Node(1, i, sum));
        }
        for (int i = 1; i <= k; ++i) {
            Node x = q.top();
            q.pop();
            res = x.sum;
            q.push(make_Node(x.l + 1, x.r, x.sum - nums[x.l]));
        }
        return res;
    }
};

int main() {
    return 0;
}