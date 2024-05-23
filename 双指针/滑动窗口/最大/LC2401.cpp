#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/longest-nice-subarray/

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int res = 0;
        for (int i = 0, j = 0, state = 0; i < nums.size(); i++) {
            while (state & nums[i]) {  // 同一位上出现1
                state ^= nums[j++];
            }
            state |= nums[i];
            res = max(res, i - j + 1);
        }
        return res;
    }
};

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int cnt[40] = {0};
        int res = 0;
        for (int i = 0, j = 0, tot = 0; i < nums.size(); i++) {
            for (int k = 0; k < 31; k++)
                if (nums[i] >> k & 1) {
                    if (++cnt[k] > 1)
                        tot++;
                }
            while (tot) {
                for (int k = 0; k < 31; k++)
                    if (nums[j] >> k & 1) {
                        if (--cnt[k] == 1)
                            tot--;
                    }
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};

int main() {
    return 0;
}