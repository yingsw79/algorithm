#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/1GxJYY/

class Solution {
public:
    const int MOD = 1e9 + 7;
    int beautifulBouquet(vector<int>& flowers, int cnt) {
        int n = flowers.size(), res = 0;
        unordered_map<int, int> mp;
        for (int i = 0, j = 0; j < n; ++j) {
            ++mp[flowers[j]];
            while (i <= j && mp[flowers[j]] > cnt) --mp[flowers[i++]];
            res = (res + j - i + 1) % MOD;  // 以flowers[j]结尾的满足要求的子数组个数为j-i+1(长度)
        }
        return res;
    }
};

int main() {
    

    return 0;
}