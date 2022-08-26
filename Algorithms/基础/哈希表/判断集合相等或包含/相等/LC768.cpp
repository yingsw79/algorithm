#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/max-chunks-to-make-sorted-ii/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> nums = arr;
        sort(nums.begin(), nums.end());
        unordered_map<int, int> cnt;
        int res = 0;
        for (int i = 0, diff = 0; i < arr.size(); i++) {
            if (++cnt[nums[i]] == 1) ++diff;
            if (--cnt[arr[i]] == 0) --diff;
            if (!diff) res++;
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}