#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/earliest-possible-day-of-full-bloom/description/?envType=daily-question&envId=2023-09-30

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<int> idx(plantTime.size());
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return growTime[i] > growTime[j]; });
        int res = 0, t = 0;
        for (int i : idx) {
            t += plantTime[i];
            res = max(res, t + growTime[i]);
        }
        return res;
    }
};

int main() {
    return 0;
}