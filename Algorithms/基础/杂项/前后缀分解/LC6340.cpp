#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/count-increasing-quadruplets/

class Solution {
    int great[4000][4001];

public:
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size(), less[n + 1];
        for (int k = n - 2; k >= 2; k--) {
            memcpy(great[k], great[k + 1], sizeof(great[k + 1]));
            for (int x = nums[k + 1] - 1; x > 0; x--)
                great[k][x]++;  // x < nums[k+1]，对于 x，大于它的数的个数 +1
        }

        long ans = 0;
        memset(less, 0, sizeof(less));
        for (int j = 1; j < n - 2; j++) {
            for (int x = nums[j - 1] + 1; x <= n; x++)
                less[x]++;  // x > nums[j-1]，对于 x，小于它的数的个数 +1
            for (int k = j + 1; k < n - 1; k++)
                if (nums[j] > nums[k])
                    ans += less[nums[k]] * great[k][nums[j]];
        }
        return ans;
    }
};

class Solution {
public:
    typedef long long LL;
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        LL sum = 0;
        vector<LL> v(n);  // 132
        for (int i = 0; i < n; i++) {
            int z = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    sum += v[j];
                    z++;
                } else {
                    v[j] += z;
                }
            }
        }
        return sum;
    }
};

int main() {
    return 0;
}