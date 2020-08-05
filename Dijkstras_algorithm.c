#include <stdio.h>
#include "Dijkstras_algorithm.h"
#include <assert.h>

//найти вершину с наименьшей стоимостью среди необработанных
int finding_the_cheapest_vertex(int costs[])
{
	int lowest_cost_vertex = 1000000;
	int vertex;

	for (int i = 0; i < 4; ++i)
	{
		if (costs[i] < lowest_cost_vertex && costs[i] != -1)
		{
			lowest_cost_vertex = costs[i];
			vertex = i;
		}
	}

	if (lowest_cost_vertex == 1000000)
		vertex = -1;

	return vertex;
}

//Алгоритм Дейкстры
int Dijkstras_algorithm(int graph[][4], int costs[], int parents[])
{
	int vertex = finding_the_cheapest_vertex(costs); // нашли наименьшую вершину
	int cost, new_cost, j = 0;

	while (vertex != -1) // делать пока  node не будет равно -1 
	{
		cost = costs[vertex]; // выдает сколько надо затратить чтобы добраться до узла cost["b"] = 2 
		int neighbors[4]; // стоимость соседей этого узла

		for (int i = 0; i < 4; ++i)
			neighbors[i] = -1;

		for (int i = 0; i < 4; ++i)
			if (graph[vertex][i] != -1)
			{
				neighbors[i] = graph[vertex][i]; 
				//printf("v %d %d\n", vertex, neighbors[j]);
				j += 1;
			}

		for (int i = 0; i < 4; ++i) // перебираем всех соседей текущего узла
			if (neighbors[i] != -1)
			{
				//printf("c %d n %d\n", cost, neighbors[i]);
				new_cost = cost + neighbors[i]; // сколько стоит добраться от вашего узла до соседей 

				if (costs[i] > new_cost)
				{
					costs[i] = new_cost; // обновим стоимость перехода к узлу
					parents[i] = vertex; // изменим родителя узла
				}

			}

		costs[vertex] = -1; // вершина помечается как обработанная
		vertex = finding_the_cheapest_vertex(costs); // найти следущий узел с мин стоимостью 
	}

	return 0;

}
