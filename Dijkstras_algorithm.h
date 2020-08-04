//Алгоритм Дейкстры
int Dijkstras_algorithm(int graph[][4], int costs[], int parents[]);

//найти вершину с наименьшей стоимостью среди необработанных
int finding_the_cheapest_vertex(int costs[]);

//распечатка графа
void print_graph(int graph[][4]);