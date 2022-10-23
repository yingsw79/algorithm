#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/create-components-with-same-value/

class Solution {
public:
    int componentValue(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int target;
        function<int(int, int)> dfs = [&](int u, int fa) -> int {
            int res = nums[u];
            for (int v : g[u]) {
                if (v == fa) continue;
                int t = dfs(v, u);
                if (t == -1) return -1;
                res += t;
            }
            if (res > target) return -1;
            return res < target ? res : 0;
        };
        int sum = accumulate(nums.begin(), nums.end(), 0);
        for (int i = n; i; --i) {
            if (sum % i == 0) {
                target = sum / i;
                if (dfs(0, -1) != -1) return i - 1;
            }
        }
        return -1;
    }
};

int main() {
    return 0;
}