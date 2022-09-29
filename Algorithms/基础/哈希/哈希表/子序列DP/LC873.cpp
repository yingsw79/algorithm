#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/length-of-longest-fibonacci-subsequence/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), res = 0;
        unordered_map<int, int> pos;
        //定义二维数组dp表示以每个下标对的元素作为最后两个数字的斐波那契子序列的最大长度
        vector<vector<int>> dp(n, vector<int>(n, 2));  
        for (int i = 0; i < n; i++) pos[arr[i]] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int x = arr[i] - arr[j];
                if (x < arr[j] && pos.count(x)) {
                    int k = pos[x];
                    dp[i][j] = max(dp[i][j], dp[j][k] + 1);
                }
                res = max(res, dp[i][j]);
            }
        }
        return res >= 3 ? res : 0;
    }
};

int main() {
    system("pause");
    return 0;
}