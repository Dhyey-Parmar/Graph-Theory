#include <stdio.h>

int graph[4][4] = {
    {1, 1, 0, 0},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {0, 0, 1, 1}
};

int subsets[15][4] = {
    {1,0,0,0},
    {0,1,0,0},
    {0,0,1,0},
    {0,0,0,1},

    {1,1,0,0},
    {1,0,1,0},
    {1,0,0,1},
    {0,1,1,0},
    {0,1,0,1},
    {0,0,1,1},

    {1,1,1,0},
    {1,1,0,1},
    {1,0,1,1},
    {0,1,1,1},

    {1,1,1,1}
};

int checkHallsCondition()
{
    int i=0, j=0, k=0;
    int leftCount=0, rightCount=0;
    int used[4];
    for(i=0;i<15;i++){
        for(j=0;j<4;j++){
            if(subsets[i][j]==1){
                leftCount++;
            }
            for(k=0;k<4;k++){
                if (graph[j][k]==1)
                {
                    used[k]=1;
                }
            }
        }
        for(k=0;k<4;k++){
            if (used[k]==1)
            {
                rightCount++;
                used[k]=0;
            }
        }
        if(rightCount<leftCount){
            return 0;
        }    
    }
    /*
       Darek subset mate one by one check karvanu.
       Pehla to subset ma ketla vertex che e count karvana.
       Pachhi ena badha neighbour find karvana.
       Same neighbour ne ek j vaar count karvo.

       Jo koi pan subset mate right side na neighbour < left side na vertex
       hoy to Hall's condition satisfy nahi thay.

       Badha subset mate condition satisfy thay to Hall's condition satisfy thay.
    */

    // Write code here


    return 1;
}
void getSubset(){

}
void main()
{
    int ans;

    ans = checkHallsCondition();

    if(ans == 1)
        printf("Hall's condition is satisfied");
    else
        printf("Hall's condition is not satisfied");
}