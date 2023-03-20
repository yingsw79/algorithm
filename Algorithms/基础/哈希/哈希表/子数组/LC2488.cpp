#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/count-subarrays-with-median-k/

class Solution {
public:
    int countSubarrays(vector<int> &nums, int k) {
        int pos = find(nums.begin(), nums.end(), k) - nums.begin(), n = nums.size();
        unordered_map<int, int> cnt;
        cnt[0] = 1;  // i=pos 的时候 c 是 0，直接记到 cnt 中，这样下面不是大于就是小于
        for (int i = pos + 1, c = 0; i < n; ++i) {
            c += nums[i] > k ? 1 : -1;
            ++cnt[c];
        }

        int ans = cnt[0] + cnt[1];  // i=pos 的时候 c 是 0，直接加到答案中，这样下面不是大于就是小于
        for (int i = pos - 1, c = 0; i >= 0; --i) {
            c += nums[i] < k ? 1 : -1;
            ans += cnt[c] + cnt[c + 1];
        }
        return ans;
    }
};

int main() {
    return 0;
}