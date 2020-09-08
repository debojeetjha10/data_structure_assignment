#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,size1=0,size2=0;
    printf("\nEnter the value of n:");
    scanf("%d",&n);

    printf("\nEnter the 1st sparse matrix:");
    printf("\n");

    int *sparse1[n]; 
    for (int i=0; i<n; i++)
    {
      sparse1[i] = (int *)calloc(n ,sizeof(int));
      for(int j=0; j<n; j++)
      {
        scanf("%d",&sparse1[i][j]);
        if(sparse1[i][j]!=0)
          size1++;
      }

    }

    printf("\nEnter the 2nd sparse matrix:");
    printf("\n");

    int *sparse2[n]; 
    for (int i=0; i<n; i++)
    {
        sparse2[i] = (int *)calloc(n ,sizeof(int));
        for(int j=0; j<n; j++)
        {
            scanf("%d",&sparse2[i][j]);
            if(sparse2[i][j]!=0)
                size2++;
        }

    }

    int ans[size1+size2][4];
    int k=0;
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<n; j++)
      {
        if(sparse1[i][j]||sparse2[i][j])
        {
          ans[k][0]=i;
          ans[k][1]=j;
          ans[k][2]=sparse1[i][j]+sparse2[i][j];
          ans[k][3]=sparse1[i][j]-sparse2[i][j];
          k++;
        }

      }
    }
    
    for(int i=0; i<size1+size2; i++) 
    {
        printf("Position = (%d, %d), Sum = %d, Difference = %d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
    }

    printf("\n.");
    
    //Deallocating the sparse matrix
    for(int i=0; i<n; i++)
    {
        free(sparse1[i]);
        free(sparse2[i]);

    }

    return 0;
}
