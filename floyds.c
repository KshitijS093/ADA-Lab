#include<stdio.h>
void main()
{
    int adj[10][10],n,i,j,k;
    int result[10][10];
    printf("Floyd's algorithm\n");
    printf("enter the number of vertices\n");
    scanf("%d",&n);
    printf("Enter the distance matrix for %d vertices\n",n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&adj[i][j]);
            result[i][j]=adj[i][j];
        }
    }
    for(k=0;k<n;k++)
    {
        for(j=0;j<n;j++)
        {
            for(i=0;i<n;i++)
            {
                result[i][j]=result[i][j]<(result[i][k]+result[k][j])?result[i][j]:(result[i][k]+result[k][j]);
            }
        }
    }
    printf("\nResult\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",result[i][j]);
        }
        printf("\n");
    }

}