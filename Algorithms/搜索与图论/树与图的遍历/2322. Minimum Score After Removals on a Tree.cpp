#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef pair<int, int> PII;
typedef long long LL;

// https://leetcode.cn/problems/minimum-score-after-removals-on-a-tree/

class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> nes[n];
        for (auto& e : edges) {
            nes[e[0]].push_back(e[1]);
            nes[e[1]].push_back(e[0]);
        }

        int all = 0;
        for (int i : nums) all ^= i;

        int res = 2e9, s[n];

        function<void(int, int)> dfs = [&](int node, int pre) {
            s[node] = nums[node];
            for (int ne : nes[node]) {
                if (ne != pre) {
                    dfs(ne, node);
                    s[node] ^= s[ne];
                }
            }
        };

        function<void(int, int, int)> get = [&](int node, int pre, int sum) {
            for (auto ne : nes[node]) {
                if (ne != pre) {
                    int p1 = all ^ sum, p2 = sum ^ s[ne], p3 = s[ne];
                    res = min(res, max(p1, max(p2, p3)) - min(p1, min(p2, p3)));
                    get(ne, node, sum);
                }
            }
        };
        
        /* 枚举根节点，先进行一次 dfs，求出每个子树 i 的异或和 s[i]；
        首先从根节点枚举第一个删除的边，然后在其子树中枚举第二个删除的边 */

        for (int i = 0; i < n; ++i) {
            dfs(i, -1);
            for (int ne : nes[i]) {
                get(ne, i, s[ne]);
            }
        }

        return res;
    }
};

int main() {
    system("pause");
    return 0;
}
