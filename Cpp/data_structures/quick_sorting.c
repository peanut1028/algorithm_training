# include <stdio.h>
int a[101],n;

void quicksort(int left, int right){
    int i,j,t,temp;
    if (left>right)
        return;

    temp = a[left];  //temp里存基准数
    i = left;
    j = right;
    while (i != j)
    {
        //基准数在左侧，升序排序，必须先从右往左找
        while (a[j]<=temp && i<j)
        {   
            j--;
        }
        while (a[i]>=temp && i<j)
        {
            i++;
        }
        if (i<j) //当i没有和j相遇,就交换
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //将基准数放到中间，准备下一次排序
    a[left] = a[i];
    a[i] = temp;

    quicksort(left,i-1);
    quicksort(i+1,right);
}

int main()
{
    int i,j,t;
    scanf("%d",&n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(1,n);

    for (i = 1; i <= n; i++)
    {
        printf("%d",a[i]);
    }
    getchar();getchar();
    return 0;
}