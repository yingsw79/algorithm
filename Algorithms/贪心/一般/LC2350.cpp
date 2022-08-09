#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/shortest-impossible-sequence-of-rolls/

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        unordered_set<int> st;
        int cnt = 0;
        for (auto& x : rolls) {
            st.insert(x);
            if (st.size() == k) cnt++, st.clear();
        }
        return cnt + 1;
    }
};

int main() {
    system("pause");
    return 0;
}