#include "Graph.h"
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int N2 = 2e5 + 5;
std::vector<int> G1[N2]; // 邻接表 BFS
int G2[2000][2000]; // 邻接矩阵 Floyd

// 链式前向星 Dijkstra && Prim
const int INF = 0x3f3f3f;
int dis[N2], vis[N2];
int head[N2];
struct Edge
{
    int v, w, nxt;
} edges[N2 * 2];

int cnt = 0;
inline void add_edge(int u, int v, int w)
{
    edges[++cnt].v = v;
    edges[cnt].w = w;
    edges[cnt].nxt = head[u];
    head[u] = cnt;
}

// kruscal所用的并查集, 边集数组
struct E{
    int u, v, w;
} e[N2];
int fa[N2];
inline int find(int x)
{
    if(x == fa[x]){
        return x;
    }else{
        return find(fa[x]);
    }
}

inline void join(int x, int y)
{
    x = find(x);
    y = find(y);
    if(x == y) return ;
    fa[x] = y;
}



void bfs()
{
    
    
}

void prim()
{
    int n, m, cnt = 0, sum = 0;
    std::cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        std::cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    // memset(dis, INF, sizeof(dis));
    std::fill(dis, dis + N2, INF);
    std::priority_queue<std::pair<int, int>, 
    std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    dis[1] = 0;
    pq.push(std::make_pair(0, 1));
    while(!pq.empty() && cnt < n)
    {
        int u = pq.top().second, w = pq.top().first;
        pq.pop();
        if(vis[u]) continue;
        cnt++;
        sum += w;
        for(int i = head[u]; i != 0; i = edges[i].nxt)
        {
            int v = edges[i].v;
            if(!vis[v] && edges[i].w < dis[v])
            {
                dis[v] = edges[i].w;
                pq.push(std::make_pair(dis[v], v));
            }
        }
    }

    if(cnt == n) std::cout << sum;
    else std::cout << "orz";
}

void kruscal()
{

}

void dijkstra()
{

}

void floyd()
{

}
