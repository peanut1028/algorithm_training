# include <stdio.h>
struct note{
    int x;
    int y;
    int f;
    int s;
};
int main(){
    struct note que[2501];
    int a[51][51] = {0};
    int book[51][51] = {0};
    int next[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
    int head,tail;
    int i,j,k,n,m,startx,starty,p,q,tx,ty,flag;
    printf("please input n,m:\n");
    scanf("%d %d",&n,&m);
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            getchar();
            scanf(" %d",&a[i][j]);
    printf("input origin and object:\n");
    scanf("%d %d %d %d",&startx,&starty,&p,&q);


    head = 1;
    tail = 1;
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].f = 0;
    que[tail].s = 0;
    tail++;
    book[startx][starty] = 1;

    flag = 0; //用来标记是否到达目标

    while (head<tail){
        for(k=0;k<=3;k++){
            tx = que[head].x+next[k][0];  // que[head]始终表示当前正在搜索的坐标，也即队列的head始终指在当前坐标
            ty = que[head].y+next[k][1];
            if(tx<1 || tx>n || ty<1 || ty>m)
                continue;
            if(a[tx][ty]==0 && book[tx][ty]==0){
                book[tx][ty] = 1;
                //在tail处插入该点，表示搜索到
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].f = head; // 将当前head指向的坐标记下来
                que[tail].s = que[head].s+1;
                tail++;
            }
            // 如果到目标了，停止扩展，退出循环
            if(tx==p && ty==q){
                flag = 1;
                break;
            }   
        }
        if(flag == 1)
            break;
        head++;// 对下一个点进行搜索
    }
    printf("%d\n",que[tail-1].s);
    getchar();getchar();
    return 0;
}