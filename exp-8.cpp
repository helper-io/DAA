#include <iostream>
using namespace std;
#include <limits.h>

int minDistance(int dist[], bool sptSet[], int V)
{

	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

void printSolution(int dist[],int V)
{
	cout << "Vertex \t Distance from Source" << endl;
	for (int i = 0; i < V; i++)
		cout << i << " \t\t\t\t" << dist[i] << endl;
}

void dijkstra(int **graph, int V, int src)
{
	int dist[V]; 

	bool sptSet[V]; 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, sptSet, V);

		sptSet[u] = true;

		for (int v = 0; v < V; v++)

			
			if (!sptSet[v] && graph[u][v]
				&& dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	printSolution(dist,V);
}

int main()
{
	int V;
	cout<<"Enter the number of vertices: ";
	cin>>V;
	int **graph = new int*[V];
	for(int i=0;i<V;i++)
		graph[i] = new int[V];
	cout<<"Enter the adjacency matrix: "<<endl;
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			cin>>graph[i][j];
	
	
	// int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	// 					{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	// 					{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	// 					{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	// 					{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	// 					{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
	// 					{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
	// 					{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	// 					{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
	dijkstra(graph,V, 0);

	return 0;
}