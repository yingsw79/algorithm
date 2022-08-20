#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

/* struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
}; */

class Solution {
public:
    int alls[150010], diff[150010], sum[150010], k = 0, n;

    int query(int x) {
        return lower_bound(alls, alls + n, x) - alls + 1;
    }

    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        for (auto& t : tiles) {
            alls[k++] = t[0];
            alls[k++] = t[1];
            alls[k++] = max(t[1] - carpetLen + 1, 0);
        }
        alls[k++] = 0;
        sort(alls, alls + k);
        n = unique(alls, alls + k) - alls;
        memset(diff, 0, sizeof diff);
        memset(sum, 0, sizeof sum);
        for (auto& t : tiles) {
            int l = query(t[0]), r = query(t[1]);
            diff[l]++;
            diff[r + 1]--;
        }
        for (int i = 1; i <= n; i++) {
            diff[i] += diff[i - 1];
            sum[i] = sum[i - 1] + diff[i];
        }
        int res = 0;
        for (auto& t : tiles) {
            int l = query(max(t[1] - carpetLen + 1, 0)), r = query(t[1]);
            res = max(res, sum[r] - sum[l - 1]);
        }
        return res;
    }
};


int main() {
    system("pause");
    return 0;
}