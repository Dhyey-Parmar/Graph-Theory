#include <stdio.h>
int queue[6], front = -1, rear = -1;
int visited[6] = {-1, -1, -1, -1, -1}, visitedIndex = -1;
int isVisited(int n)
{
    for (int i = 0; i < 5; i++)
    {
        if (visited[i] == n)
        {
            return 1;
        }
    }
    return 0;
}
void enqueue(int n)
{
    if (front == -1)
    {
        front++;
    }
    queue[++rear] = n;
}

int dequeue()
{
    if (front > rear)
    {
        return -1;
    }
    return queue[front++];
}

void BFS(int admatrix[6][6], int distance[], int vertex)
{
    int i = vertex;
    enqueue(i);
    visited[++visitedIndex] = i;
    while (front > rear)
    {
        i = queue[front];
        for (int j = 0; j < 5; j++)
        {
            if (admatrix[i][j] == 1 && !isVisited(j))
            {
                enqueue(j);
                visited[++visitedIndex] = j;
                distance[j] = distance[i] + 1;
            }
        }
    }
    for (int i = 0; i < 6; i++)
    {
        visited[i] = 0;
    }
    visitedIndex = -1;
}
void main()
{
    int edge[5][2] = {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}};
    int degree[6] = {0};
    // for (int i = 0; i < 5; i++)
    // {
    //     degree[edge[i][0]]++;
    //     degree[edge[i][1]]++;
    // }
    // printf("1.Pendent Vertices:");
    // for (int i = 0; i < 6; i++)
    // {
    //     if (degree[i] == 1)
    //     {
    //         printf(" %d \n", i);
    //     }
    // }
    // printf("2.Degree of Vertices:");
    // for (int i = 0; i < 6; i++)
    // {
    //     printf("Degree of %d is %d \n", i, degree[i]);
    // }
    int adMat[6][6] = {{0, 1, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0}, {0, 1, 0, 0, 0, 0}, {1, 0, 0, 0, 1, 1}, {0, 0, 0, 1, 0, 0}, {0, 0, 0, 1, 0, 0}};
    int distance[6][6] = {0};
    for (int i = 0; i < 6; i++)
    {
        BFS(adMat, distance[i], i);
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf(" %d ", distance[i][j]);
        }
        printf("\n");
    }
}