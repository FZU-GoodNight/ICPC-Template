/*
输入：
输入一张图的所有边。
第一行输入两个整数 n, m 表示图的点数和边数；
接下来 m 行，每行输入三个整数 u, v, w 表示一条从 u 连向 v 且边权为 w 的边。

输出：
输出这张图的所有边。
共输出 m 行，每行输出三个整数 u, v, w 表示一条从 u 连向 v 且边权为 w 的边。

由 @Andy15 最后更新于 2020/11/10
*/

#include <bits/stdc++.h>
#define MAXN 1111
#define MAXM 1111

using namespace std;
int n, m;

struct Graph {
    struct Edge {
        int v, w;
        Edge *nxt;
    } *first[MAXN], e[MAXM], *ptr = e;

    inline void insert(register int &u, register int &v, register int &w) {
        *ptr = (Edge) {v, w, first[u]};
        first[u] = ptr++;
    }
} g;

int main() {
    for (scanf("%d%d", &n, &m); m; --m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        g.insert(u, v, w);
    }
    for (register int i = 1; i <= n; ++i) {
        for (register Graph::Edge *j = g.first[i]; j; j = j -> nxt) {
            printf("%d %d %d\n", i, j -> v, j -> w);
        }
    }
    return 0;
}
