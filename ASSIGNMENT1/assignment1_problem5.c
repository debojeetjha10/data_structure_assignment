#include<stdio.h>
#include<stdlib.h>

int main()
{
    int row,col,size=0;
    printf("Enter no. of rows and columbs(n*n) of the sparse matrix: ");
    scanf("%d",&row);
    col = row;

    printf("Enter the sparse matrix:\n");
    int *sparse[row]; 
    for (int i=0; i<row; i++)
    {
        sparse[i] = (int *)calloc(col ,sizeof(int));
        for(int j=0; j<col; j++)
        {
            scanf("%d",&sparse[i][j]);
            if(sparse[i][j]!=0)
                size++;
        }

    }

    int ans[3][size];
    int k=0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(sparse[i][j]!=0)
            {
                ans[0][k]=i;
                ans[1][k]=j;
                ans[2][k]=sparse[i][j];
                k++;
            }

        }
    }
    
    printf("\nElement\t Corresponding Row\tCorresponding Column\n");
    for(int j=0; j<size; j++)
    {
        printf("%d\t\t%d\t\t%d\n",ans[2][j],ans[0][j],ans[1][j]);
    }

    //Deallocating the sparse matrix
    for(int i=0; i<row; i++)
    {
        free(sparse[i]);
    }

    return 0;
}
/*output:
Enter no. of rows and columbs(n*n) of the sparse matrix: 4
Enter the sparse matrix:
1 0 0 0
2 0 0 0
0 0 0 0
0 0 0 0

Element  Corresponding Row  Corresponding Column
1       0       0
2       1       0
*/
