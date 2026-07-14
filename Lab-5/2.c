#include <stdio.h>
int DFS(int admat[5][5], int current, int visited[], int path[], int curBranch)
{
    visited[current] = 1;
    path[curBranch++] = current;
    for (int i = 0; i < 5; i++)
    {
        if (admat[current][i] == 1 && visited[i] == 0)
        {

            DFS(admat, i, visited, path, curBranch);
        }
    }
}
void main()
{
    int edges[6][2] = {(0, 1), (0, 2), (1, 2), (1, 3), (2, 4), (3, 4)};
    int admat[5][5] = {{0, 1, 1, 0, 0}, {1, 0, 1, 1, 0}, {1, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}};
    int path[5], branch[4][2];
    int visited[5] = {0};
    int chord[2][2];
    int curBranch = 0,indChord=0,isbranch=0;
    DFS(admat, 0, visited, path, curBranch);

    printf("Branches:");
    for (int i = 0; i < 4; i++)
    {
        branch[i][0] = path[i];
        branch[i][1] = path[i + 1];
        printf("\n(%d,%d)", branch[i][0], branch[i][1]);
    }
    printf("Chordes:");
    for (int i = 0; i < 6; i++)
    {
        isbranch=0;
        for (int j = 0; j < 4; j++)
        {
            if(branch[j][0]==edges[i][0]&&branch[j][1]==edges[i][1]){
                isbranch=1;
                break;
            }
        }    
        if(!isbranch){
            chord[indChord][0]=edges[i][0];
            chord[indChord++][1]=edges[i][1];
            printf("\n(%d,%d)", chord[indChord][0], chord[indChord][1]);
        }   
    }
}