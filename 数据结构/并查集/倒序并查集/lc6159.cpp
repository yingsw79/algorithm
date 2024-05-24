#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// 删除操作后的最大子段和
// https://leetcode.cn/problems/maximum-segment-sum-after-removals/
// 注意本题中nums[i]>0,不需要线段树

class Solution {
public:
    typedef long long LL;
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<int> p(n);
        vector<LL> sum(n), res;
        for (int i = 0; i < n; i++) p[i] = i;
        function<int(int)> find = [&](int x) -> int {
            return p[x] == x ? x : p[x] = find(p[x]);
        };
        LL maxs = 0;
        for (int i = n - 1; i >= 0; i--) {
            res.push_back(maxs);
            int x = removeQueries[i];
            sum[x] = nums[x];
            for (int j = x - 1; j <= x + 1; j += 2) {
                if (j >= 0 && j < n && sum[j]) {
                    int y = find(j);
                    sum[x] += sum[y];
                    p[y] = x;
                }
            }
            maxs = max(maxs, sum[x]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        int fa[n + 1];
        iota(fa, fa + n + 1, 0);
        long long sum[n + 1];
        memset(sum, 0, sizeof(sum));
        function<int(int)> find = [&](int x) -> int { return fa[x] == x ? x : fa[x] = find(fa[x]); };

        vector<long long> ans(n);
        for (int i = n - 1; i > 0; --i) {
            int x = removeQueries[i];
            int to = find(x + 1);
            fa[x] = to;  // 合并 x 和 x+1
            sum[to] += sum[x] + nums[x];
            ans[i - 1] = max(ans[i], sum[to]);
        }
        return ans;
    }
};

int main() {
    return 0;
}