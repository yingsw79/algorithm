#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/count-number-of-bad-pairs/

class Solution {
public:
    typedef long long LL;
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        LL res = (LL)n * (n - 1) / 2;
        unordered_map<int, LL> mp;
        for (int i = 0; i < n; i++) {
            int x = i - nums[i];
            if (mp.count(x)) {
                res -= mp[x];
            }
            mp[x]++;
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}