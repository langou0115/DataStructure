#include "Graph.h"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

const int N2 = 2e5 + 5;
std::vector<int> G1[105]; // 邻接表 BFS 拓补排序
int G2[105][105]; // 邻接矩阵 Floyd

// 链式前向星 Dijkstra && Prim
const int INF = 0x3f3f3f3f;
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


void prim()
{
    int n, m, cnt_n = 0, sum = 0;
    std::cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        std::cin >> u >> v >> w;
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    std::fill(dis, dis + N2, INF);
    std::priority_queue<std::pair<int, int>, 
    std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    dis[1] = 0;
    pq.push(std::make_pair(0, 1));
    while(!pq.empty() && cnt_n < n)
    {
        int u = pq.top().second, w = pq.top().first;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        cnt_n++;
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

    if(cnt_n == n) std::cout << sum;
    else std::cout << "orz";
}

void kruscal()
{
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
    for(int i = 1; i <= m; i++){
        std::cin >> e[i].u >> e[i].v >> e[i].w;
    }
    std::sort(e + 1, e + m + 1, [](E e1, E e2){
        return e1.w < e2.w;
    });
    
    int ans = 0, cnt_m = 0;
    for(int i = 1; i <= m; i++){
        if(find(e[i].u) == find(e[i].v)) continue;
        join(e[i].u, e[i].v);
        cnt_m++;
        ans += e[i].w;
    }
    if(cnt_m == n - 1){
        std::cout << ans;
    }else{
        std::cout << "orz";
    }
}

void dijkstra()
{
    int n, m, s;
    std::cin >> n >> m >> s;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        std::cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    std::fill(dis, dis + N2, INF);
    dis[s] = 0;
    std::priority_queue<std::pair<int, int>, 
    std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push(std::make_pair(0, s));
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = head[u]; i != 0; i = edges[i].nxt){
            int v = edges[i].v, w = edges[i].w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                pq.push(std::make_pair(dis[v], v));
            }
        }
    }
    for(int i = 1; i <= n; i++){
        std::cout << dis[i] << " ";
    }
}

void floyd()
{
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i != j) G2[i][j] = INF;
        }
    }
    for(int i = 1; i <= m; i++){
        int u, v, w;
        std::cin >> u >> v >> w;
        G2[u][v] = std::min(G2[u][v], w);
        G2[v][u] = std::min(G2[v][u], w);
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(G2[i][k] != INF && G2[j][k] != INF){
                    G2[i][j] = std::min(G2[i][j], G2[i][k] + G2[j][k]);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            std::cout << G2[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void topologicalSort()
{
    int n;
    std::cin >> n;
    int indegree[n + 5];
    memset(indegree, 0, sizeof(indegree));
    for(int i = 1; i <= n; i++){
        int v;
        while(true){
            std::cin >> v;
            if(v == 0) break;
            G1[i].push_back(v);
            indegree[v]++;
        }
    }
    std::queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!indegree[i]) q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        std::cout << u << " ";
        for(int i = 0; i < G1[u].size(); i++){
            int v = G1[u][i];
            if(!--indegree[v]) q.push(v);
        }
    }
}