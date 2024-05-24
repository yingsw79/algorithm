#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef pair<int, int> PII;

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int res = -1;
        unordered_map<int, int> hash;
        for (auto& x : nums) {
            int s = 0, y = x;
            while (y) s += y % 10, y /= 10;
            if (hash.count(s)) res = max(res, x + hash[s]);  //有动态规划的思想，选x与不选x的最大值
            hash[s] = max(hash[s], x);  //只需每次更新目前的最大值
        }
        return res;
    }
};

int main() {
    system("pause");
    return 0;
}