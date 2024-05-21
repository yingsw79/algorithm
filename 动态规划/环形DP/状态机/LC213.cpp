#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

class Solution {
public:
    int rob(vector<int>& nums) {  //断环成链,两次DP
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<vector<int>> f(2, vector<int>(2));  //滚动数组优化
        int res = 0;
        f[0][0] = 0, f[0][1] = nums[0];
        for (int i = 1; i < n; i++) {
            f[i & 1][0] = max(f[i - 1 & 1][0], f[i - 1 & 1][1]);
            f[i & 1][1] = f[i - 1 & 1][0] + nums[i];
        }
        res = max(res, f[n - 1 & 1][0]);

        f[n - 1 & 1][0] = 0, f[n - 1 & 1][1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            f[i & 1][0] = max(f[i + 1 & 1][0], f[i + 1 & 1][1]);
            f[i & 1][1] = f[i + 1 & 1][0] + nums[i];
        }
        res = max(res, f[0][0]);
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}