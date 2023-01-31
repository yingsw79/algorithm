#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    typedef long long LL;
    long long countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        LL sum = 0;
        vector<LL> v(n);  // 132
        for (int i = 0; i < n; i++) {
            int z = 0;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    sum += v[j];
                    z++;
                } else {
                    v[j] += z;
                }
            }
        }
        return sum;
    }
};

int main() {
    return 0;
}