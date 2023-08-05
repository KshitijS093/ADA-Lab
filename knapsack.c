#include<stdio.h>
void main()
{
    int i,j,w[10],p[10],opt[10][10],x[10],n,m;
    printf("Enter the number of items\n");
    scanf("%d",&n);
    printf("enter the weight and profit of each item\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&w[i],&p[i]);
    }
    printf("enter the knapsack capacity\n");
    scanf("%d",&m);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                opt[i][j]=0;
            }
            else if(j-w[i]<0)
            {
                opt[i][j]=opt[i-1][j];
            }
            else
            {
                opt[i][j]=opt[i-1][j-w[i]]+p[i]>(opt[i-1][j])?opt[i-1][j-w[i]]+p[i]:(opt[i-1][j]);
            }
        }
    }
    //output
    printf("\nknapsack table\n");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            printf("%d\t",opt[i][j]);
        }
        printf("\n");
    }
    for(i=n;i>=1;i--)
    {
        if(opt[i][m]!=opt[i-1][m])
        {
            x[i]=1;
            m=m-w[i];
        }
        else
        {
            x[i]=0;
        }
    }
    printf("\nitems selected are designated 1\n");
    for(i=1;i<=n;i++)
    {
        printf("%d ",x[i]);
    }


}