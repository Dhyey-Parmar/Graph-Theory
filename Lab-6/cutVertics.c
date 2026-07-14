#include<stdio.h>
int DFS(int admat[5][5], int current, int visited[],int removeVertex)
{
    visited[current] = 1;
    for (int i = 0; i < 5; i++)
    {
        if (i!=removeVertex && admat[current][i] == 1 && visited[i] == 0)
        {
            DFS(admat, i, visited,removeVertex);
        }
    }
}

void main(){
    int edges[5][2] = {(0, 1),(1, 2), (1, 3), (2, 4), (3, 4)};
    int admat[5][5] = {{0, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}};
    int ans[5]={-1};
    int ans_ind=0;
    
    for(int i=0;i<5;i++){
        int visited[5] = {0};
        if(i==0) DFS(admat,1,visited,i);
        else DFS(admat,0,visited,i);

        for(int j=0;j<5;j++){
            if(j!=i&&visited[j]!=1){
                ans[ans_ind++]=i;
                break;
            }
        }
    }
    for(int i=0;i<ans_ind;i++){
        printf("%d",ans[i]);
    }
}