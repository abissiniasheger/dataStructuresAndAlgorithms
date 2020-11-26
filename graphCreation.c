#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 6

typedef struct Node
{
    int dest;
	int weight;
    struct Node* next;
}Node;

typedef struct edge
{
	int source;
	int destination;
	int weight;
}edge;

typedef struct graph
{
	struct Node* array[N];
}graph;


graph* createGraph(edge* edges, int V)
{
	graph* Graph = (graph*)malloc(sizeof(graph));
	
	for (int i = 0; i < V; i++)
	{
		int destination = edges[i].destination;
		int source = edges[i].source;
		int weight = edges[i].weight;
		
		
		Node* newNode = (Node*)malloc(sizeof(Node));
	
		newNode->dest = destination;
		newNode->weight = weight;
		newNode->next = Graph->array[source];
	
		Graph->array[source] = newNode;
	}
	
	return Graph;
}

void printGraph(graph* Graph)
{
	for (int i = 0; i < N; i++)
	{
		Node* head = Graph->array[i];
		while (head != NULL)
		{
			printf(" (%d -> %d) weight = %d", i, head->dest, head->weight);
			head = head->next;
		}
		
		printf("\n");
	}
	
}


int main()
{
	struct edge Edges[] = {{ 0, 1, 20}, { 1, 2, 8}, { 2, 0, 10}, { 2, 1, 15},
                           { 3, 2, 6}, { 4, 5, 100}, { 5, 4, 200}};
    int n = sizeof(Edges)/sizeof(Edges[0]);
	graph* Graph = createGraph(Edges, n);
	printGraph(Graph);
	
	return 0;
}