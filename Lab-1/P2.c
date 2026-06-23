#include <stdio.h>
void main()
{
    int n, v;
    printf("Enter of edges");
    scanf("%d", &n);
    printf("Enter of vertices");
    scanf("%d", &v);
    int edge[n][2];
    for (int i = 0; i < n; i++)
    {
        printf("Enter endpoints of edge");
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &edge[i][j]);
        }
    }
    int degree=0;
    int adMatrix[v][v];
    printf("Adjency Matrix \n");
    for (int i = 0; i < v; i++)
    {

        for (int j = 0; j < v; j++)
        {
            adMatrix[i][j] = 0;
        }
    }

    for (int j = 0; j < n; j++)
    {
        adMatrix[edge[j][0]][edge[j][1]]++;
    }

    for (int i = 0; i < v; i++)
    {
        
        for (int j = 0; j < v; j++)
        {
            printf(" %d ",adMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Adjency List");
    for (int i = 0; i < v; i++)
    {
        printf("%d ->", i);
        for (int j = 0; j < n; j++)
        {
            if (edge[j][0] == i)
            {
                printf("%d,", edge[j][1]);
            }
        }
        printf("\n");
    }

    printf("Degree of vertex=%d",degree);
    
    
}