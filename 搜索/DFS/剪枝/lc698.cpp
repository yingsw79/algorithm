#include <bits/stdc++.h>
using namespace std;

// https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % k > 0) {
            return false;
        }
        s /= k;
        sort(nums.begin(), nums.end(), greater<>());
        if (nums.front() > s) {
            return false;
        }
        int n = nums.size();
        vector<bool> st(n, false);
        auto dfs = [&](auto dfs, int i, int t, int cnt) -> bool {
            if (cnt == 0) {
                return true;
            }
            if (t == 0) {
                return dfs(dfs, 0, s, cnt - 1);
            }
            for (int j = i; j < n; j++) {
                if (st[j] || nums[j] > t) {
                    continue;
                }
                st[j] = true;
                if (dfs(dfs, j + 1, t - nums[j], cnt)) {
                    return true;
                }
                st[j] = false;
                if (t == nums[j]) {
                    return false;
                }
                for (; j < n - 1 && nums[j] == nums[j + 1]; j++) {
                }
            }
            return false;
        };
        return dfs(dfs, 0, s, k);
    }
};
