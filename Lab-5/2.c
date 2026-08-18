#include<stdio.h>

void DFS(int vertex,int adjs[5][5],int visited[],int path[],int n_path,int endVertex){

    visited[vertex] = 1;
    path[n_path++] = vertex;
    for(int i=0;i<5;i++){ 
        if(adjs[vertex][i] != 0 && !visited[i]){
            DFS(i,adjs,visited,path,n_path,endVertex);
        }
    }
}

void main(){
    int edges[6][2] = {{0,1},{0,2},{1,2},{1,3},{2,4},{3,4}}; 
    int v = 5;
    int path[v];
    int n_path = 0;
    int visited[5] = {0};
    int branch[v-1][2];
    int chord[6-v+1][2];
    int chord_idx = 0;
    int isBranch = 0;

    int adjs[5][5] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };

    DFS(0,adjs,visited,path,n_path,-1);

    for(int i=0;i<5;i++){
        printf("%d,",path[i]);
    }

    for(int i=0;i<v-1;i++){
        branch[i][0] = path[i];
        branch[i][1] = path[i+1];
    }

    printf("\n Branchs \n");
    for(int i=0;i<v-1;i++){
        printf("%d,%d\n",branch[i][0],branch[i][1]);
    }

    for(int i=0;i<6;i++){
        isBranch = 0;
        for(int j=0;j<v-1;j++){
            if(edges[i][0] == branch[j][0] && edges[i][1] == branch[j][1]){
                isBranch = 1;
                break;
            }
        }

        if(!isBranch){
            chord[chord_idx][0] = edges[i][0];
            chord[chord_idx++][1] = edges[i][1];
        }
    }


    printf("\n Chords \n");
    for(int i=0;i<6-v+1;i++){
        printf("%d,%d\n",chord[i][0],chord[i][1]);
    }
    for(int i=0;i<5;i++){
        visited[i]=0;
    }
    n_path=0;
    int branch_Admat[5][5]={{0,1,0,0,0},{1,0,1,0,0},{0,1,0,0,1},{0,0,0,0,1},{0,0,1,1,0}};
    for(int i=0;i<6-v+1;i++){
        DFS(chord[i][0],branch_Admat,visited,path,n_path,chord[i][1]);
    }
}