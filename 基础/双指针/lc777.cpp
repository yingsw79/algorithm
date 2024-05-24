#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/swap-adjacent-in-lr-string/

class Solution {
public:
    bool canTransform(string start, string end) {
        int n = start.size();
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (start[i] == 'X') continue;
            while (j < n && end[j] == 'X') j++;
            if (j == n || start[i] != end[j]) return false;
            if (start[i] == 'L' && i < j || start[i] == 'R' && i > j) return false;
            j++;
        }
        for (int i = j; i < n; ++i)
            if (end[i] != 'X') return false;
        return true;
    }
};

int main() {
    return 0;
}