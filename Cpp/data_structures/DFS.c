# include<stdio.h>
int n,m,p,q,min = 99999999;
int a[51][51],book[51][51];
void dfs(int x,int y,int step){
    int next[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int nextx,nexty,k;
    // 判断边界
    if (x==p && y==q){
        // 即找到目标，记录一下当前的步数，看是否最小
        if (step < min){
            min = step;
        }
        return;
    }
    // 循环尝试每一种可能
    for(k=0;k<=3;k++){
        nextx = x + next[k][1];
        nexty = y + next[k][0];
        // 检查是否越界
        if (nextx<0 || nextx>n-1 || nexty<0 || nexty>m-1){
            continue;
        }
        // 判断是否是障碍或当前路径已经走过
        if (a[nextx][nexty]==0 && book[nextx][nexty]==0){
            book[nextx][nexty] = 1;
            dfs(nextx,nexty,step+1); // 递推直到找到目标退出
            // 退出后要将当前的位置的标记取消，以便开始寻找另一条的路径
            book[nextx][nexty] = 0;    
        }
    }
    return;
}


int main(){
    int i,j,startx,starty;
    printf("please input n,m:\n");
    // fflush(stdout);
    scanf("%d %d",&n,&m);
    for(i=0;i<=n;i++)
        for(j=0;j<m;j++)
            // printf("input map:\n");
            // fflush(stdout);
            getchar();
            scanf(" %d",&a[i][j]); 
            
    printf("input origin and object:\n");
    // fflush(stdout);
    scanf("%d %d %d %d",&startx,&starty,&p,&q);
    book[startx][starty] = 1;
    dfs(startx,starty,0);
    printf("%d",min);
    getchar();getchar();
    return 0;
}