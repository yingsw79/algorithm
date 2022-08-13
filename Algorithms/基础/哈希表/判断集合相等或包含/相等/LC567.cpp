#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if (n1 > n2) return false;
        vector<int> cnt(26);
        for (auto& c : s1) cnt[c - 'a']++;
        for (int i = 0, j = 0; i < n2; i++) {
            cnt[s2[i] - 'a']--;
            while (cnt[s2[i] - 'a'] < 0) {
                cnt[s2[j] - 'a']++;
                j++;
            }
            if (i - j + 1 == n1) return true;
        }
        return false;
    }
};

int main() {
    system("pause");
    return 0;
}