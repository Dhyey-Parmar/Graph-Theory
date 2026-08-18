#include<stdio.h>
#define v 4
int adjs[v][v]={
    {0,1,1,0},
    {1,0,1,1},
    {1,1,0,0},
    {0,1,0,0}
};

int singleVertices[v][1]={{0},{1},{2},{3}};

int twoVertices[6][2]={
    {0,1},
    {0,2},
    {0,3},
    {1,2},
    {1,3},
    {2,3}
};

int threeVertices[4][3]={
    {0,1,2},
    {0,1,3},
    {0,2,3},
    {1,2,3}
};

int fourVertices[1][4]={{0,1,2,3}};

void getDominationSet(int set[],int size,int visited[]){
    visited[set[0]]=1;
    for(int i=0;i<size;i++){
        for(int j=0;j<v;j++){
            visited[set[i]]=adjs[i][j];            
        }   
    }
}

int checkVisited(int visited[]){
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            return -1;
        }        
    }
    return 1;
}

void printSet(int set[],int size){
    printf("{");
    for(int i=0;i<size;i++){
        printf();        
    }
}

void main(){

    for(int i=0;i<v;i++){
        int visited[v]=0;
        getDominationSet(singleVertices[i][1],1,visited);
    }
}