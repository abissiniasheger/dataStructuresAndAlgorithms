#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int value;
    struct Node* next;
    struct Node* right;
    struct Node* left;
}Node;

Node* root = NULL;
Node* head = NULL;

void enqueue(Node* node_p);
Node* dequeue();
Node* createHeap(int rootIndex);
Node* createNode();

void breadthFirstSearch(Node* node_p);

int unsortedArray[] = {1, 12, 9, 5, 6, 10, 2, 30, 50, 70, 15, 20, 80, 300, 1000, 100, -2, 44, 25, 44, 99, 200, 400, 500};
int length = sizeof(unsortedArray)/sizeof(unsortedArray[0]);
int main()
{
    root = createHeap(0);
	
	breadthFirstSearch(root);
	
    return 0;
}

Node* createHeap(int rootIndex)
{
    Node* root = NULL;
    if (rootIndex >= length)
    {
        return NULL;
    }
    root = (Node*)malloc(sizeof(Node));
	root->value = unsortedArray[rootIndex];
	root->left = createHeap(rootIndex*2 + 1);
	root->right = createHeap(rootIndex*2 + 2);
	
    return root;	
}

void breadthFirstSearch(Node* root)
{
    enqueue(root);
	
	while (root != NULL)
	{
		printf("%d ", root->value);
		
		if (root->left != NULL)
			enqueue(root->left);
		if (root->right != NULL)
			enqueue(root->right);
		
		root = dequeue();
	}
}

void enqueue(Node* node_p)
{
	Node* newNode = createNode();
	newNode = node_p;
	
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
    }
    
}

Node* createNode()
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    return newNode; 
}

Node* dequeue()
{
    Node* prev = NULL;
    prev = head;
    head = head->next;
    prev->next = NULL;
    free(prev);
	
	return head;
}
