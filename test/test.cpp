#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        vector<int> f(n);
        vector<int> g(n);
        f[0] = nums[0];
        for (int i = 1; i < n; i++) {
            f[i] = max(f[i - 1], 0) + nums[i];
        }
        int pre = nums[n - 1], temp = nums[n - 1];
        g[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            pre = max(pre, 0) + nums[i];
            temp = max(temp, pre);
            g[i] = temp;
        }
        int res = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            res = max(res, f[i] + g[i + 1]);
        }
        cout << res << endl;
    }
}