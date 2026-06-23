#include <stdio.h>
int queue[10], front = -1, rear = -1;
int visited[5]={-1,-1,-1,-1,-1},visitedIndex=-1;
int isVisited(int n){
    for (int i = 0; i < 5; i++)
    {
        if(visited[i]==n){
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
int isEmpty(){
    if(front>rear){
        return 1;
    }
    return 0;
}
void main()
{
    int admatrix[5][5] = {{0, 1, 1, 0, 0}, {1, 0, 1, 1, 0}, {1, 1, 0, 0, 1}, {0, 1, 0, 0, 1}, {0, 0, 1, 1, 0}};
    int i=0;
    enqueue(0);
    visited[++visitedIndex]=0;
    while(1)
    {
        i=queue[front];
        for (int j = 0; j < 5; j++)
        {
            if(admatrix[i][j]==1){
                if(!isVisited(j)){
                    enqueue(j);
                    visited[++visitedIndex]=j;
                }
            }
        }
        if(isEmpty()){
            break;
        }
        printf(" %d ",dequeue());
    }
}