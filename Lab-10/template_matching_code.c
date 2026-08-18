#include <stdio.h>

#define E 5
#define V 6

int edges[][2] = {
    {0, 3},
    {0, 4},
    {1, 4},
    {1, 5},
    {2, 5}
};

int combinations[32][5] = {
    {-1,-1,-1,-1,-1},

    {0,-1,-1,-1,-1},
    {1,-1,-1,-1,-1},
    {2,-1,-1,-1,-1},
    {3,-1,-1,-1,-1},
    {4,-1,-1,-1,-1},

    {0,1,-1,-1,-1},
    {0,2,-1,-1,-1},
    {0,3,-1,-1,-1},
    {0,4,-1,-1,-1},
    {1,2,-1,-1,-1},
    {1,3,-1,-1,-1},
    {1,4,-1,-1,-1},
    {2,3,-1,-1,-1},
    {2,4,-1,-1,-1},
    {3,4,-1,-1,-1},

    {0,1,2,-1,-1},
    {0,1,3,-1,-1},
    {0,1,4,-1,-1},
    {0,2,3,-1,-1},
    {0,2,4,-1,-1},
    {0,3,4,-1,-1},
    {1,2,3,-1,-1},
    {1,2,4,-1,-1},
    {1,3,4,-1,-1},
    {2,3,4,-1,-1},

    {0,1,2,3,-1},
    {0,1,2,4,-1},
    {0,1,3,4,-1},
    {0,2,3,4,-1},
    {1,2,3,4,-1},

    {0,1,2,3,4}
};

int arr[32];
int p = 0;


/* Print a matching */
void printMatching(int index)
{
    int j;

    printf("{ ");

    for(j = 0; j < E; j++)
    {
        if(combinations[index][j] != -1)
        {
            printf("e%d ", combinations[index][j]);
        }
    }

    printf("}");
}


/* Count number of edges in a combination */
int getSize(int index)
{
    int j;
    int size = 0;

    for(j = 0; j < E; j++)
    {
        if(combinations[index][j] != -1)
            size++;
    }

    return size;
}


/*
    Find all matchings

    A matching is a set of edges where
    no two edges have a common vertex.
*/
void findMatching()
{
    int i, j;
    int edgeIndex;
    int start, end;
    int freq[V];
    int flag;

    printf("\n========== ALL MATCHINGS ==========\n");

    p = 0;

    for(i = 0; i < 32; i++)
    {
        /* Initialize frequency array */
        for(j = 0; j < V; j++)
            freq[j] = 0;

        flag = 1;

        /*
            Check every edge in the combination
        */
        for(j = 0; j < E; j++)
        {
            edgeIndex = combinations[i][j];

            if(edgeIndex == -1)
                break;

            start = edges[edgeIndex][0];
            end = edges[edgeIndex][1];

            /*
                If either vertex is already used,
                this is NOT a matching.
            */
            if(freq[start] == 1 || freq[end] == 1)
            {
                flag = 0;
                break;
            }

            freq[start] = 1;
            freq[end] = 1;
        }

        if(flag == 1)
        {
            arr[p] = i;
            p++;

            printf("Matching: ");
            printMatching(i);
            printf("\n");
        }
    }

    printf("Total Matchings = %d\n", p);
}


/*
    Find all maximal matchings.

    A matching is maximal if no additional edge
    can be added without violating the matching property.
*/
void findMaximalMatching()
{
    int i, j, e;
    int index;
    int edgeIndex;
    int start, end;
    int freq[V];
    int maximal;
    int currentSize;

    printf("\n========== MAXIMAL MATCHINGS ==========\n");

    for(i = 0; i < p; i++)
    {
        index = arr[i];

        /* Reset frequency */
        for(j = 0; j < V; j++)
            freq[j] = 0;

        /* Mark vertices used by current matching */
        for(j = 0; j < E; j++)
        {
            edgeIndex = combinations[index][j];

            if(edgeIndex == -1)
                break;

            start = edges[edgeIndex][0];
            end = edges[edgeIndex][1];

            freq[start] = 1;
            freq[end] = 1;
        }

        maximal = 1;
        currentSize = getSize(index);

        /*
            Try to add every edge which is not
            already present.
        */
        for(e = 0; e < E; e++)
        {
            /* Check if edge already exists */
            int alreadyPresent = 0;

            for(j = 0; j < E; j++)
            {
                if(combinations[index][j] == e)
                {
                    alreadyPresent = 1;
                    break;
                }
            }

            if(alreadyPresent)
                continue;

            start = edges[e][0];
            end = edges[e][1];

            /*
                If both vertices are free,
                we can add this edge.
                Therefore current matching is NOT maximal.
            */
            if(freq[start] == 0 && freq[end] == 0)
            {
                maximal = 0;
                break;
            }
        }

        if(maximal == 1)
        {
            printf("Maximal Matching: ");
            printMatching(index);
            printf("  Size = %d\n", currentSize);
        }
    }
}


/*
    Find maximum matching.

    Maximum matching = matching having
    the largest number of edges.
*/
void findMaximumMatching()
{
    int i;
    int index;
    int size;
    int maxSize = 0;

    printf("\n========== MAXIMUM MATCHING ==========\n");

    /*
        First find maximum size
    */
    for(i = 0; i < p; i++)
    {
        index = arr[i];

        size = getSize(index);

        if(size > maxSize)
            maxSize = size;
    }

    /*
        Print all matchings having maximum size
    */
    printf("Maximum Size = %d\n", maxSize);

    for(i = 0; i < p; i++)
    {
        index = arr[i];

        size = getSize(index);

        if(size == maxSize)
        {
            printf("Maximum Matching: ");
            printMatching(index);
            printf("\n");
        }
    }
}


/*
    Find perfect matching.

    Since V = 6, every vertex must be matched.
    Therefore a perfect matching must contain V/2 = 3 edges.
*/
void findPerfectMatching()
{
    int i, j;
    int index;
    int edgeIndex;
    int start, end;
    int freq[V];
    int size;
    int perfect;

    printf("\n========== PERFECT MATCHING ==========\n");

    for(i = 0; i < p; i++)
    {
        index = arr[i];

        size = getSize(index);

        /*
            For 6 vertices, perfect matching
            must contain exactly 3 edges.
        */
        if(size != V / 2)
            continue;

        for(j = 0; j < V; j++)
            freq[j] = 0;

        perfect = 1;

        for(j = 0; j < E; j++)
        {
            edgeIndex = combinations[index][j];

            if(edgeIndex == -1)
                break;

            start = edges[edgeIndex][0];
            end = edges[edgeIndex][1];

            if(freq[start] == 1 || freq[end] == 1)
            {
                perfect = 0;
                break;
            }

            freq[start] = 1;
            freq[end] = 1;
        }

        /*
            Check whether every vertex is matched
        */
        for(j = 0; j < V; j++)
        {
            if(freq[j] == 0)
            {
                perfect = 0;
                break;
            }
        }

        if(perfect == 1)
        {
            printf("Perfect Matching: ");
            printMatching(index);
            printf("\n");
        }
    }
}


int main()
{
    findMatching();

    // findMaximalMatching();

    // findMaximumMatching();

    // findPerfectMatching();

    return 0;
}