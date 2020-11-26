#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int value;
    struct Node* next;
}Node;

Node* head = NULL;
void enqueue(int value);
void dequeue();
Node* createNode(int value);

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    
    for (int i = 0; i < 5; i++)
    {
        enqueue(arr[i]);
    }
    
    dequeue();
    
    return 0;
}

void enqueue(int value)
{
    Node* newNode = createNode(value);
    
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

void dequeue()
{
    if (head == NULL)
    {
        return;
    }
    
    Node* prev = NULL;
    while (head != NULL)
    {
        printf("%d ", head->value);
        prev = head;
        head = head->next;
        prev->next = NULL;
        free(prev);
    }
}

Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    
    return newNode; 
}
