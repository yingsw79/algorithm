#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimize-maximum-of-array/

class Solution {
public:
    bool check(vector<int>& a, int mid) {
        int n = a.size();
        vector<long> nums(n);
        for (int i = 0; i < n; ++i) nums[i] = a[i];
        for (int i = n - 1; i >= 1; --i) {
            if (nums[i] > mid) {
                long t = nums[i] - mid;
                nums[i] -= t;
                nums[i - 1] += t;
            }
        }
        return nums[0] <= mid;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int l = 0, r = mx;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(nums, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

int main() {
    return 0;
}