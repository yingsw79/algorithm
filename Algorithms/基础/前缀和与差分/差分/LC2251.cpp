#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/problems/number-of-students-doing-homework-at-a-given-time/
// https://leetcode.cn/problems/number-of-flowers-in-full-bloom/description/?envType=daily-question&envId=2023-09-28

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people) {
        int n = flowers.size();
        vector<int> starts(n), ends(n);
        for (int i = 0; i < n; i++) {
            starts[i] = flowers[i][0];
            ends[i] = flowers[i][1];
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        for (int &p : people)
            p = (upper_bound(starts.begin(), starts.end(), p) - starts.begin()) -
                (lower_bound(ends.begin(), ends.end(), p) - ends.begin());
        return people;
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &people) {
        map<int, int> diff;
        for (auto &f : flowers) {
            diff[f[0]]++;
            diff[f[1] + 1]--;
        }

        int n = people.size();
        vector<int> id(n);
        iota(id.begin(), id.end(), 0);  // id[i] = i
        sort(id.begin(), id.end(), [&](int i, int j) { return people[i] < people[j]; });

        auto it = diff.begin();
        int sum = 0;
        for (int i : id) {
            while (it != diff.end() && it->first <= people[i])
                sum += it++->second;  // 累加不超过 people[i] 的差分值
            people[i] = sum;          // 从而得到这个时刻花的数量
        }
        return people;
    }
};

int main() {
    return 0;
}