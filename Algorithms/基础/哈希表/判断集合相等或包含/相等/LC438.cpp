#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.size(), n = p.size();
        if (m < n) return {};
        vector<int> hashTable(26);
        for (auto ch : p) ++hashTable[ch - 'a'];
        vector<int> ret;
        for (int l = 0, r = 0; r < m; ++r) {
            --hashTable[s[r] - 'a'];
            while (hashTable[s[r] - 'a'] < 0) {
                ++hashTable[s[l] - 'a'];
                ++l;
            }
            if (r - l + 1 == n) ret.push_back(l);
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen = s.size(), pLen = p.size();

        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> count(26);
        for (int i = 0; i < pLen; ++i) {
            ++count[s[i] - 'a'];
            --count[p[i] - 'a'];
        }

        int differ = 0;
        for (int j = 0; j < 26; ++j) {
            if (count[j] != 0) {
                ++differ;
            }
        }

        if (differ == 0) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {
            if (count[s[i] - 'a'] == 1) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从不同变得相同
                --differ;
            } else if (count[s[i] - 'a'] == 0) {  // 窗口中字母 s[i] 的数量与字符串 p 中的数量从相同变得不同
                ++differ;
            }
            --count[s[i] - 'a'];

            if (count[s[i + pLen] - 'a'] == -1) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从不同变得相同
                --differ;
            } else if (count[s[i + pLen] - 'a'] == 0) {  // 窗口中字母 s[i+pLen] 的数量与字符串 p 中的数量从相同变得不同
                ++differ;
            }
            ++count[s[i + pLen] - 'a'];

            if (differ == 0) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};

int main() {
    system("pause");
    return 0;
}