#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define lowbit(x) (x & (-x))
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
const int INF = 0x3f3f3f3f, MOD = 1e8 - 3;

// https://www.luogu.com.cn/problem/P1966
//1.排序不等式 2.广义逆序对

const int N = 100010;
int a[N], b[N], c[N], idx1[N], idx2[N];  //索引数组
int tr[N];
int n;

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}

int getsum(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum += tr[i];
    return sum;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), idx1[i] = i;
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]), idx2[i] = i;

    //对索引数组按照对应值大小排序得到该数组第i大元素所在的位置(下标)
    sort(idx1 + 1, idx1 + n + 1, [&](auto& i, auto& j) {
        return a[i] < a[j];
    });

    sort(idx2 + 1, idx2 + n + 1, [&](auto& i, auto& j) {
        return b[i] < b[j];
    });

    for (int i = 1; i <= n; i++) c[idx1[i]] = idx2[i];  //映射,必须要有c[i] = i,即数组c升序

    int res = 0;
    for (int i = n; i; i--) {  //转化为求数组c的逆序对
        int x = c[i];
        res = (res + getsum(x - 1)) % MOD;
        add(x, 1);
    }

    printf("%d\n", res);

    return 0;
}