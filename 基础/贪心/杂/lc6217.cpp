#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/contest/weekly-contest-316/problems/minimum-number-of-operations-to-make-arrays-similar/
// 奇偶分组匹配

class Solution {
public:
    typedef long long LL;
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        LL res = 0;
        int js[2]{};
        for (int x : nums) {
            int p = x % 2, &j = js[p];
            while (target[j] % 2 != p) j++;
            res += abs(x - target[j++]);
        }
        return res / 4;
    }
};

int main() {
    return 0;
}