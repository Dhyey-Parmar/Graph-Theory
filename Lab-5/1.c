#include<stdio.h>
int DFS(int admat[4][4], int current, int visited[])
{
    visited[current] = 1;
    for (int i = 0; i <sizeof(admat[i])/sizeof(admat[i][0]); i++)
    {
        if(admat[current][i]==1&&visited[i]==0){
            
            DFS(admat,i,visited);
        }
    }   
}
void main(){
    int admat[4][4]={{1,1,0,0},{1,1,0,0},{0,0,1,1},{0,0,1,1}};
    int count=0;
    int visited[4]={0};
    for(int i=0;i<4;i++){
        if(visited[i]==0){
            DFS(admat,i,visited);
            count++;
        }
    }
    printf("%d",count);
}