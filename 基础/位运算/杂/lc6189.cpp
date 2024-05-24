#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/longest-subarray-with-maximum-bitwise-and/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int res = 1;
        for (int i = 0, k = 0; i < nums.size(); ++i) {
            if (nums[i] == mx)
                k++;
            else
                k = 0;
            res = max(res, k);
        }
        return res;
    }
};

int main() {
    return 0;
}