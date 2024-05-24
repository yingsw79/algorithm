#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e9 + 7;

// https://leetcode.cn/contest/tianchi2022/problems/8KXuKl/

class Solution {
public:
    int getLength(vector<string>& grid) {
        int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
        int m = grid.size(), n = grid[0].length();
        int res = 0;
        int x = -1, y = 0, k = 0;
        while (true) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) break;
            res++;
            if (k == 0) {
                if (grid[nx][ny] == 'L')
                    k = 3;
                else if (grid[nx][ny] == 'R')
                    k = 1;
            } else if (k == 1) {
                if (grid[nx][ny] == 'L')
                    k = 2;
                else if (grid[nx][ny] == 'R')
                    k = 0;
            } else if (k == 2) {
                if (grid[nx][ny] == 'L')
                    k = 1;
                else if (grid[nx][ny] == 'R')
                    k = 3;
            } else {
                if (grid[nx][ny] == 'L')
                    k = 0;
                else if (grid[nx][ny] == 'R')
                    k = 2;
            }
            x = nx, y = ny;
        }
        return res;
    }
};

int main() {
        return 0;
}