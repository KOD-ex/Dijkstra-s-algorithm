#include "Dijkstras_algorithm.h"
#include <stdio.h>

int main()
{
    int graph[4][4];
    int costs[4];
    int parents[4];

    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            graph[i][j] = -1;
            costs[j] = -1;
            parents[j] = -1;
        }
    

    int connect, weight;

    for (int i = 0; i < 4; ++i)
    {
        printf("%d: \n", i);

        for (int j = 0; j < 4; ++j)
        {
            scanf("%d %d", &connect, &weight);
            if (connect == -1)
                break;

            graph[i][connect] = weight;
        }
    }


    costs[1] = 6;
    costs[2] = 2;
    costs[3] = 1000000000;

    parents[0] = -1;
    parents[1] = 0;
    parents[2] = 0;
    

    Dijkstras_algorithm(graph, costs, parents);
    //print graph
    print_graph(graph);
    
    return 0;
}
