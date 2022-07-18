#include <cstring>
#include <iostream>
using namespace std;

// N 表顶点个数 M 表边个数 视题目而定
const int N = 1010, M = 1e4 + 10;

//这是有向边
// e[idx]存的是u指向的顶点v, w[idx]存的是 u - v之间的权重
// ne[idx] 存的是下一顶点所在的下标 h[u] 就是头结点 idx是游标
int e[M], w[M], ne[M], h[N], idx;

//无向边是特殊的有向边 开双倍
// int e[M<<1], w[M<<1], ne[M<<1], h[N], idx;

void init()  //初始化
{
    idx = 0;                  //游标从零开始
    memset(h, -1, sizeof h);  //将所有头结点置空
}

void add(int a, int b, int c)  //加边操作
{
    e[idx] = b;      //存顶点值
    w[idx] = c;      //存边权
    ne[idx] = h[a];  //存h[a]指向的前驱顶点的下标
    h[a] = idx++;    // h[a]指向b所在下标, idx游标往后移动
}

int main() {
    int n, m;  //顶点数(1~n)和权值
    cin >> n >> m;

    init();  //别忘初始化
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);  //加边
    }

    for (int i = 1; i <= n; ++i)  //一个一个顶点遍历
    {
        for (int j = h[i]; j != -1; j = ne[j])  //遍历顶点指向的边
            cout << e[j] << "(" << w[j] << ") 	";
        cout << "\n\n";
    }

    return 0;
}
