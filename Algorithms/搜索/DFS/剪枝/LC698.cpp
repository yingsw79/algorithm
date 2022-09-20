#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/

class Solution {
public:
    bool dfs(int start, int cur, int k, int target, vector<int>& nums, vector<bool>& st) {
        if (!k) return true;
        if (cur == target) return dfs(0, 0, k - 1, target, nums, st);
        for (int i = start; i < nums.size(); i++) {
            if (st[i]) continue;
            if (cur + nums[i] <= target) {
                st[i] = true;
                if (dfs(i + 1, cur + nums[i], k, target, nums, st)) return true;
                st[i] = false;
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
            if (!cur || cur + nums[i] == target) return false;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % k) return false;
        int target = sum / k;
        sort(nums.begin(), nums.end(), greater<int>());
        if (nums[0] > target) return false;
        vector<bool> st(nums.size());
        return dfs(0, 0, k, target, nums, st);
    }
};

int main() {
    return 0;
}