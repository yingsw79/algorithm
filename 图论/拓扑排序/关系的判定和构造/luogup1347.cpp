#include <bits/stdc++.h>
using namespace std;

// https://www.luogu.com.cn/problem/P1347

const int N = 28, M = 610;
int h[N], e[M], ne[M], idx;
int de[N], q[N], l, r;
int n, m;
bool flag;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort() {
    int des[N];
    memcpy(des, de, sizeof de);
    flag = true;  //初始化
    l = 0, r = -1;

    for (int i = 0; i < n; i++) {  //前m个关系中未出现的变量入度一定为0，也会被加入队列
        if (!des[i]) q[++r] = i;   //此时拓扑排序就算成功也不唯一，不成功则一定有矛盾
    }

    while (l <= r) {
        if (r - l + 1 > 1) flag = false;  //队列中元素个数大于1则拓扑序列不唯一
        int t = q[l++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (--des[j] == 0) {
                q[++r] = j;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= m; i++) {
        char c[5];
        scanf("%s", c);
        int a = c[0] - 'A', b = c[2] - 'A';
        add(a, b);
        de[b]++;
        topsort();
        if (r == n - 1 && flag) {
            printf("Sorted sequence determined after %d relations: ", i);
            for (int j = 0; j <= r; j++) {
                printf("%c", q[j] + 'A');
            }
            puts(".");
            return 0;
        } else if (r < n - 1) {
            printf("Inconsistency found after %d relations.\n", i);
            return 0;
        }
    }
    puts("Sorted sequence cannot be determined.");

    return 0;
}