#include "Dijkstras_algorithm.h"
#include <stdio.h>
#include <assert.h>

//распечатаем кратчайший путь
void print_the_shortest_path(int parents[], int vertex) 
{
    printf("\n");
    printf("the shortest path: \n");
    
    for (int i = 0; vertex != -1; ++i)
    {
        printf("%d ", vertex);
        vertex = parents[vertex];
    }
    printf("\n");
}

void algorithm_testing(int parents[], int vertex)
{
    int result[3] = {3,2,0};
    for (int i = 0; vertex != -1; ++i)
    {
        assert(vertex == result[i]);
        vertex = parents[vertex];
    }
}

int main()
{
    int graph[4][4];
    int costs[4];
    int parents[4];


    printf("                +-------+               \n");           
    printf("                |       |               \n");  
    printf("         6      |   1   |   2           \n");
    printf("    +---------->+       +-------+       \n");
    printf("    |           +---+---+       |       \n");
    printf("    |               ^           |       \n");
    printf("    |               |           v       \n");
    printf("+---+---+           |         +-+-----+ \n");
    printf("|       |           |         |       | \n");
    printf("|   0   |         3 |         |  3    | \n");
    printf("|       |           |         |       | \n"); 
    printf("+---+---+           |         +--+----+ \n");
    printf("    |               |            ^      \n");
    printf("    |           +---+---+        |      \n");
    printf("    +---------->|       +--------+      \n");
    printf("          2     |   2   |     5         \n");
    printf("                |       |               \n");
    printf("                +-------+               \n");

    printf("\n\n");


    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
        {
            graph[i][j] = -1;
            costs[j] = -1;
            parents[j] = -1;
        }
    

    int connect, weight;

    graph[0][1] = 6;
    graph[0][2] = 2;
    graph[1][3] = 2;
    graph[2][1] = 3;
    graph[2][3] = 5;


    costs[1] = 6;
    costs[2] = 2;
    costs[3] = 1000000000;

    parents[0] = -1;
    parents[1] = 0;
    parents[2] = 0;
    
    Dijkstras_algorithm(graph, costs, parents);
    print_the_shortest_path(parents, 3);
    algorithm_testing(parents, 3);
    
    return 0;
}
