#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/super-egg-drop/
// https://www.acwing.com/video/3030/

class Solution {
public:
    int superEggDrop(int k, int n) {
        int f[n + 1][k + 1];
        memset(f, 0, sizeof f);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) 
                f[i][j] = f[i - 1][j - 1] + f[i - 1][j] + 1;
            if (f[i][k] >= n) return i;
        }        
        return -1;
    }
};

int main() {
    system("pause");
    return 0;
}