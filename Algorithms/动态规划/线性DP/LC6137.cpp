#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/check-if-there-is-a-valid-partition-for-the-array/

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<bool> f(n + 1);
        f[0] = true;
        for (int i = 1; i < n; i++) {
            if (f[i - 1] && nums[i - 1] == nums[i] ||
                i > 1 && f[i - 2] && (nums[i - 2] == nums[i - 1] && nums[i - 1] == nums[i] ||
                nums[i - 2] + 1 == nums[i - 1] && nums[i - 1] + 1 == nums[i])) f[i + 1] = true;
        }
        return f[n];
    }
};

int main() {
    system("pause");
    return 0;
}