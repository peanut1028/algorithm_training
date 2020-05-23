#include<stdio.h>
int main(){
    int e[10][10],dis[10],book[10],i,j,n,m,t1,t2,t3,u,v,min;
    // u 记录离源点最近的点
    // book 记录已知最短路径（源点——该点）的点
    int inf = 999999;
    scanf("%d %d",&n,&m);

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(i==j) e[i][j] = 0;
                else e[i][j] = inf;

    for(i=1;i<=m;i++){
        scanf("%d %d %d",&t1,&t2,&t3);
        e[t1][t2] =t3;
    }

    // 初始化dis数组，这里是1号点到其余各点的初始路程
    for(i=1;i<=n;i++){
        dis[i] = e[1][i];
    }

    for(i=1;i<=n;i++){
        book[i] = 0;
    }

    book[1] = 1;

    // Dijkstra核心语句
    for(i=1;i<=n;i++){
        //找到离1号点最近的点
        min = inf;
        for(j=1;j<=n;j++){
            if(book[j]==0 && dis[j]<min){
                min = dis[j];
                u = j;   
            }
        }
        book[u] = 1;
        for(v=1;v<=n;v++){
            // 考察所有以u为起点的边
            if(e[u][v]<inf){
                // 松弛
                if(dis[v]>dis[u]+e[u][v]){
                    dis[v]=dis[u]+e[u][v];
                }
            }
        }
    }

    // 输出结果
    for(i=1;i<=n;i++){
        printf("%d ",dis[i]);
    }
    getchar();getchar();
    return 0;
}