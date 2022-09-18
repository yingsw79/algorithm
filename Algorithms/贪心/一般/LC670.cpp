#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/maximum-swap/
// 最大交换

class Solution {
public:
    int maximumSwap(int num) {
        auto s = to_string(num);
        int n = s.length();
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] < s[i + 1]) {
                int k = i + 1;
                for (int j = k; j < n; ++j)
                    if (s[j] >= s[k]) k = j;
                for (int j = 0; j < n; ++j)
                    if (s[j] < s[k]) {
                        swap(s[j], s[k]);
                        return stoi(s);
                    }
            }
        }
        return num;
    }
};

int main() {

    return 0;
}