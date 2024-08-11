package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

// 假设一个探险家被困在了地底的迷宫之中，要从当前位置开始找到一条通往迷宫出口的路径。
// 迷宫可以用一个二维矩阵组成，有的部分是墙，有的部分是路。
// 迷宫之中有的路上还有门，每扇门都在迷宫的某个地方有与之匹配的钥匙，只有先拿到钥匙才能打开门。
// 请设计一个算法，帮助探险家找到脱困的最短路径。如前所述，迷宫是通过一个二维矩阵表示的，
// 每个元素的值的含义如下 0-墙，1-路，2-探险家的起始位置，3-迷宫的出口，大写字母-门，小写字母-对应大写字母所代表的门的钥匙
// 输入描述：
// 迷宫的地图，用二维矩阵表示。第一行是表示矩阵的行数和列数M和N
// 后面的M行是矩阵的数据，每一行对应与矩阵的一行（中间没有空格）。M和N都不超过100, 门不超过10扇。
// 输出描述：
// 路径的长度，是一个整数

type state struct{ x, y, keys int }

func solve(in io.Reader, out io.Writer) {
	var m, n int
	Fscan(in, &m, &n)
	g := make([]string, m)
	var startX, startY, endX, endY int
	for i := 0; i < m; i++ {
		Fscan(in, &g[i])
		for j := 0; j < n; j++ {
			if g[i][j] == '2' {
				startX, startY = i, j
			} else if g[i][j] == '3' {
				endX, endY = i, j
			}
		}
	}

	vis := make([][][]bool, m)
	for i := range vis {
		vis[i] = make([][]bool, n)
		for j := range vis[i] {
			vis[i][j] = make([]bool, 1024) // 2^10 = 1024
		}
	}
	q := []state{{startX, startY, 0}}
	vis[startX][startY][0] = true
	dirs := []struct{ x, y int }{{0, 1}, {-1, 0}, {0, -1}, {1, 0}}

	for res := 1; len(q) > 0; res++ {
		tmp := q
		q = nil
		for _, cur := range tmp {
			for _, d := range dirs {
				nx, ny := cur.x+d.x, cur.y+d.y
				if nx < 0 || nx >= m || ny < 0 || ny >= n || g[nx][ny] == '0' {
					continue
				}
				if g[nx][ny] >= 'A' && g[nx][ny] <= 'Z' && (cur.keys>>(g[nx][ny]-'A'))&1 == 0 {
					continue
				}
				newKeys := cur.keys
				if g[nx][ny] >= 'a' && g[nx][ny] <= 'z' {
					newKeys |= 1 << (g[nx][ny] - 'a')
				}
				if vis[nx][ny][newKeys] {
					continue
				}
				if nx == endX && ny == endY {
					Fprint(out, res)
					return
				}
				vis[nx][ny][newKeys] = true
				q = append(q, state{nx, ny, newKeys})
			}
		}
	}
}

func main() { solve(bufio.NewReader(os.Stdin), os.Stdout) }
