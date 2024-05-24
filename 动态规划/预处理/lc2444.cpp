#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/count-subarrays-with-fixed-bounds/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        vector<int> p1(n, -1), p2(n, -1), p3(n, -1);  // 预处理左边最近的XX的位置
        for (int i = 0; i < n; ++i) {
            if (nums[i] == minK)
                p1[i] = i;
            else if (i >= 1)
                p1[i] = p1[i - 1];

            if (nums[i] == maxK)
                p2[i] = i;
            else if (i >= 1)
                p2[i] = p2[i - 1];

            if (nums[i] < minK || nums[i] > maxK)
                p3[i] = i;
            else if (i >= 1)
                p3[i] = p3[i - 1];
        }
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            int l = p3[i], r = min(p1[i], p2[i]);
            if (r > l) res += r - l;
        }
        return res;
    }
};

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int min_k, int max_k) {
        long long ans = 0L;
        int n = nums.size(), min_i = -1, max_i = -1, i0 = -1;
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            if (x == min_k) min_i = i;
            if (x == max_k) max_i = i;
            if (x < min_k || x > max_k) i0 = i;  // 子数组不能包含 nums[i0]
            ans += max(min(min_i, max_i) - i0, 0);
        }
        return ans;
    }
};

int main() {
    return 0;
}