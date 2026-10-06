#include <stdio.h>
void main()
{
    int Edges[4][2] = {{0, 1}, {1, 2}, {3, 4}, {0, 4}};
    int adjs[5][5];
    int deg[5][5];
    int lap[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            adjs[i][j] = 0;
            deg[i][j] = 0;
            lap[i][j] = 0;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int v1 = Edges[i][0];
        int v2 = Edges[i][1];
        adjs[v1][v2] = 1;
    }
    for (int i = 0; i < 4; i++)
    {
        int v1 = Edges[i][0];
        int v2 = Edges[i][1];
        deg[v1][v1]++;
        deg[v2][v2]++;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            lap[i][j] = deg[i][j] - adjs[i][j];
        }
    }
    printf("Adjacent:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf(" %d ", adjs[i][j]);
        }
        printf("\n");
    }

    printf("Degree:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf(" %d ", deg[i][j]);
        }
        printf("\n");
    }
    printf("Laplasian:\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf(" %d ", lap[i][j]);
        }
        printf("\n");
    }
}