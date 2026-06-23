#include <stdio.h>
int DFS(int admat[5][5], int current, int visited[])
{
    visited[current] = 1;
    printf(" %d ",current);
    for (int i = 0; i <sizeof(admat[i])/sizeof(admat[i][0]); i++)
    {
        if(admat[current][i]==1&&visited[i]==0){
            
            DFS(admat,i,visited);
        }
    }   
}
void main()
{
    int admat[5][5] = {{0, 1, 1, 0, 0}, {1, 0, 1, 0, 0}, {1, 1, 0, 1, 1}, {0, 0, 1, 0, 0}, {0, 0, 1, 0, 0}};
    int visited[5] = {0};
    int current = 0;
    DFS(admat,current,visited);
}