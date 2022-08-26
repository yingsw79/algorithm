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
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        int diff = 0, n = target.size();
        for (int i = 0; i < n; i++) {
            int x = target[i], y = arr[i];
            if (mp[x] == 0)
                ++diff;
            else if (mp[x] == -1)
                --diff;
            ++mp[x];
            if (mp[y] == 1)
                --diff;
            else if (mp[y] == 0)
                ++diff;
            --mp[y];
        }
        return diff == 0;
    }
};

class Solution {
public:
    int h;
    vector<vector<string>> res;

    int get(TreeNode* root) {
        if (!root) return 0;
        return max(get(root->left), get(root->right)) + 1;
    }

    void dfs(TreeNode* root, int r, int c) {
        res[r][c] = to_string(root->val);
        if (root->left) {
            int lr = r + 1, lc = c - (1 << (h - r - 2));
            dfs(root->left, lr, lc);
        }
        if (root->right) {
            int rr = r + 1, rc = c + (1 << (h - r - 2));
            dfs(root->right, rr, rc);
        }
    }

    vector<vector<string>> printTree(TreeNode* root) {
        h = get(root);
        int m = h, n = (1 << m) - 1;
        res.resize(m, vector<string>(n));
        dfs(root, 0, (n - 1) / 2);
        return res;
    }
};

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + (blocks[i - 1] == 'B');
        }
        int res = 0;
        for (int i = k; i <= n; i++) {
            res = min(res, k - (sum[i] - sum[i - k]));
        }
        return res;
    }
};

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.length();
        int res = 0;
        while (true) {
            bool flag = true;
            for (int i = 1; i < n;) {
                if (s[i - 1] == '0' && s[i] == '1') {
                    swap(s[i - 1], s[i]);
                    i += 2;
                    flag = false;
                } else
                    i++;
            }
            if (flag) break;
            res++;
        }
        return res;
    }
};

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> diff(n + 3);
        for (auto& sh : shifts) {
            int l = sh[0] + 1, r = sh[1] + 1, c = sh[2];
            int d = c ? 1 : -1;
            diff[l] += d;
            diff[r + 1] -= d;
        }
        for (int i = 1; i <= n; i++) {
            diff[i] += diff[i - 1];
            int x = s[i - 1] - 'a';
            s[i - 1] = 'a' + (((x + diff[i]) % 26 + 26) % 26);
        }
        return s;
    }
};

class Solution {
public:
    static const int N = 100010;
    int w[N];

    struct Node {
        int l, r;
        int sum, lmax, rmax, tmax;
    } tr[N * 4];

    void pushup(Node& u, Node& l, Node& r) {
        u.sum = l.sum + r.sum;
        u.lmax = max(l.lmax, l.sum + r.lmax);
        u.rmax = max(r.rmax, r.sum + l.rmax);
        u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
    }

    void pushup(int u) {
        pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
    }

    void build(int u, int l, int r) {
        if (l == r)
            tr[u] = {l, r, w[r], w[r], w[r], w[r]};
        else {
            tr[u] = {l, r};
            int mid = l + r >> 1;
            build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
            pushup(u);
        }
    }

    void modify(int u, int x, int v) {
        if (tr[u].l == x && tr[u].r == x)
            tr[u] = {x, x, v, v, v, v};
        else {
            int mid = tr[u].l + tr[u].r >> 1;
            if (x <= mid)
                modify(u << 1, x, v);
            else
                modify(u << 1 | 1, x, v);
            pushup(u);
        }
    }

    Node query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r)
            return tr[u];
        else {
            int mid = tr[u].l + tr[u].r >> 1;
            if (r <= mid)
                return query(u << 1, l, r);
            else if (l > mid)
                return query(u << 1 | 1, l, r);
            else {
                auto left = query(u << 1, l, r);
                auto right = query(u << 1 | 1, l, r);
                Node res;
                pushup(res, left, right);
                return res;
            }
        }
    }

    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        memset(w, 0, sizeof w);
        int n = nums.size();
        for (int i = 1; i <= n; i++) w[i] = nums[i - 1];
        build(1, 1, n);

        vector<long long> res;
        for (auto& x : removeQueries) {
            modify(1, x + 1, 0);
            res.push_back(query(1, 1, n).tmax);
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}