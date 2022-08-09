#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/minimum-replacements-to-sort-the-array/

class Solution {
public:
    typedef long long LL;
    long long minimumReplacement(vector<int>& nums) {
        int n = nums.size();
        LL res = 0;
        for (int i = n - 2, last = nums.back(); i >= 0; i--) {
            if (nums[i] <= last)
                last = nums[i];
            else {
                int k = (nums[i] + last - 1) / last;
                res += k - 1;
                last = nums[i] / k;
            }
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}