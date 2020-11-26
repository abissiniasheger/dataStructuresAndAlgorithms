#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 6

typedef struct Node
{
    int dest;
	int weight;
	float cost;
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
	Node* head[N];
}graph;

typedef struct totalCost
{
    int node;
    float cost;
}totalCost;

graph* createGraph(edge* edges, int V)
{
	graph* Graph = (graph*)malloc(sizeof(graph));
	
	// initialize head pointer for all vertices
	for (int i = 0; i < N; i++)
	   Graph->head[i] = NULL;
		
	for (int i = 0; i < V; i++)
	{
		int destination = edges[i].destination;
		int source = edges[i].source;
		int weight = edges[i].weight;
		
		
		Node* newNode = (Node*)malloc(sizeof(Node));
	
		newNode->dest = destination;
		newNode->weight = weight;
		newNode->next = Graph->head[source];
	
		Graph->head[source] = newNode;
	}
	
	return Graph;
}

void bellManFord(graph* Graph, totalCost* calcCost)
{
    for (int j = 0; j < N; j++)
    {
        if (j == 0)
        {
            calcCost[j].cost = j;
        }
        else
        {
            calcCost[j].cost = INFINITY;
        }
        
        calcCost[j].node = j;
    }
    for (int i = 0; i < N; i++)
	{
		//Node* head = Graph->head[i];
		while (Graph->head[i] != NULL)
		{
		    float tmp = Graph->head[i]->weight + calcCost[i].cost;
		    float x = Graph->head[i]->dest;
		    //float test = Graph->head[Graph->head[i]->dest]->cost;
			if (tmp < calcCost[Graph->head[i]->dest].cost)
			{
			   calcCost[Graph->head[i]->dest].cost = tmp;
			}
			//printf(" (%d -> %d) weight = %d, cost = %f", i, Graph->head[i]->dest, Graph->head[i]->weight, Graph->head[i]->cost);
			Graph->head[i] = Graph->head[i]->next;
		}
		
		printf("\n");
	}
	
	for (int k = 0; k < N; k++)
	{
	    printf(" %d \t %f\n", k, calcCost[k].cost);
	}
}

void printGraph(graph* Graph)
{
	for (int i = 0; i < N; i++)
	{
		Node* head = Graph->head[i];
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
	struct edge Edges[] = {{0, 1, 4}, {0, 2, -5}, {1, 4, 6}, {2, 3, 8},
                           {3, 4, 3}, {3, 1, 10}, {4, 5, -2}, {5, 1, 3}};
    int n = sizeof(Edges)/sizeof(Edges[0]);
	graph* Graph = createGraph(Edges, n);
	printGraph(Graph);
	
	totalCost calcCost[N];
	bellManFord(Graph, calcCost);
	
	return 0;
}