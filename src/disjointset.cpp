#include "DisjointSet.h"
#include <iostream>

const int N1 = 2e5 + 5;
int fa_set[N1];

inline int find_set(int x)
{
    if(x == fa_set[x]){
        return x;
    }else{
        return find_set(fa_set[x]);
    }
}

inline void join_set(int x, int y)
{
    x = find_set(x);
    y = find_set(y);
    if(x == y) return ;
    fa_set[x] = y;
}

void menu()
{
    int n, m;
    std::cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        fa_set[i] = i;
    }

    for(int i = 1; i <= m; i++)
    {
        int z, x, y;
        std::cin >> z >> x >> y;
        if(z == 1){
            join_set(x, y);
        }else if(z == 2){
            if(find_set(x) == find_set(y)){
                std::cout << 'Y' << std::endl;
            }else{
                std::cout << 'N' << std::endl;
            }
        }
    }
}